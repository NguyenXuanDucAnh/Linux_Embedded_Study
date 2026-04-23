# Tóm gọn ý hiểu

+ Khi cần phải xử lý dài, lâu trong handler thì sẽ không dùng handler mà dùng poll()
+ Về cơ chế, poll() sẽ xử lý lần lượt.
+ Bài toán cơ bản nhất: Đang ghi dữ liệu vào file mà có signal tới thì sao?
=> Nếu dùng handler, scheduler sẽ ngắt việc ghi dữ liệu vào file và xử lý handler trước => dữ liệu ngắt quãng thậm chí có thể bị dừng quá trình write => khiến cho chương trình sai
=> dùng poll(): Được ghi nhận có signal tới. Nếu đang không thực hiện việc gì khác thì sẽ xử lý phần logic chịu trách nhiệm cho signal còn nếu không thì thực hiện hết các việc rồi vào xử lý => sự kiện nào sinh ra trước thì được xử lý trước.

## Handler vs Poll() — Khi nào dùng cái nào?

### Bản chất khác nhau cốt lõi

```
Signal Handler:          Poll() + signalfd:
─────────────────        ──────────────────────
Signal đến               Signal đến
    ↓                        ↓
Nhảy vào NGAY            Được "pending" (chờ)
(bất kỳ lúc nào)             ↓
    ↓                    poll() báo "có signal"
Handler chạy                 ↓
    ↓                    Bạn xử lý KHI BẠN SẴN SÀNG
Quay lại chỗ bị ngắt
```

---

### Dùng Handler khi

**1 — Chương trình đơn giản, không có I/O phức tạp:**
```cpp
// Script chạy một việc rồi thôi — hoàn toàn ổn
void handler(int s) {
    if (s == SIGINT) {
        save_progress();   // đơn giản, nhanh
        exit(0);
    }
}
int main() {
    signal(SIGINT, handler);
    do_heavy_computation(); // không có cout/printf chạy song song
}
```

**2 — Chỉ set flag, không làm gì khác trong handler:**
```cpp
// Pattern an toàn nhất khi dùng handler
volatile sig_atomic_t should_exit = 0;  // kiểu duy nhất an toàn trong handler

void handler(int s) {
    should_exit = 1;  // CHỈ làm mỗi việc này — ghi 1 biến atomic
}

int main() {
    signal(SIGTERM, handler);
    while (!should_exit) {   // main loop kiểm tra flag
        do_work();
    }
    cleanup();
}
```

**3 — Cần phản ứng cực nhanh** (real-time, embedded):
```cpp
// Watchdog timer — cần dừng máy ngay lập tức khi quá nhiệt
void emergency_handler(int s) {
    gpio_write(MOTOR_PIN, OFF);  // dừng động cơ NGAY, không chờ poll()
}
```

---

### Dùng Poll() + signalfd khi

**1 — Vừa đọc stdin/socket vừa nhận signal** (đúng bài toán của bạn):
```cpp
// Không biết stdin hay signal đến trước → poll() xử lý cả 2
fds[0] = STDIN_FILENO   // bàn phím
fds[1] = signalfd       // signal
poll(fds, 2, -1);       // chờ cái nào đến trước thì xử lý cái đó
```

**2 — Server / daemon chạy dài, cần graceful shutdown:**
```cpp
// Nginx, PostgreSQL, Redis đều làm kiểu này
// SIGTERM đến → không dừng ngay, xử lý nốt request đang dang dở
if (fds[sfd].revents & POLLIN) {
    read(sfd, &info, sizeof(info));
    if (info.ssi_signo == SIGTERM) {
        finish_current_requests();  // làm nốt việc đang làm
        close_connections();
        exit(0);
    }
}
```

**3 — Cần biết thêm thông tin về signal** (ai gửi, PID nào):
```cpp
struct signalfd_siginfo info;
read(sfd, &info, sizeof(info));

info.ssi_signo  // signal số bao nhiêu
info.ssi_pid    // PID của process gửi signal
info.ssi_uid    // UID của người gửi
// → handler truyền thống không lấy được các thông tin này dễ dàng
```

---

### Bảng tóm tắt

```
                    Handler         Poll() + signalfd
─────────────────────────────────────────────────────────
Độ phức tạp         Đơn giản        Phức tạp hơn
Phản ứng            Ngay lập tức    Khi poll() quay về
An toàn với I/O     Không           Có
Lấy info signal     Khó             Dễ (signalfd_siginfo)
Dùng printf/cout    KHÔNG được      Được
Kết hợp nhiều fd    Không           Đúng mục đích
─────────────────────────────────────────────────────────
Phù hợp             Script nhỏ      Server, daemon,
                    Real-time       app có I/O phức tạp
                    Chỉ set flag
```

---

### Rule of thumb

```
Trong handler, chỉ được làm 1 trong 2 việc:
  ✅ Set một biến volatile sig_atomic_t = 1
  ✅ Gọi _exit() (không phải exit())

Nếu cần làm BẤT CỨ THỨ GÌ KHÁC → dùng poll() + signalfd
```

Bài của bạn rơi vào trường hợp "vừa đọc stdin vừa nhận signal" → `poll() + signalfd` là lựa chọn đúng, không phải vì handler sai, mà vì **bạn cần kiểm soát thứ tự xử lý** khi 2 sự kiện có thể xảy ra cùng lúc.