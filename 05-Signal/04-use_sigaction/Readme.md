# Link document về sigaction
### https://man7.org/linux/man-pages/man2/sigaction.2.html

# AI cung cấp kiến thức

Dưới đây là phần bạn cần nắm nếu muốn dùng signal “chuẩn POSIX” và tránh các bug khó chịu 👇

---

# 🧠 1. `sigaction` là gì?

`sigaction()` là API **chuẩn POSIX** để:

* đăng ký signal handler
* kiểm soát chi tiết hành vi khi signal xảy ra

👉 Nó **thay thế hoàn toàn `signal()`** trong code production.

---

# ⚙️ Cú pháp

```cpp
#include <signal.h>

int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
```

---

# 🧩 Cấu trúc `sigaction`

```cpp
struct sigaction {
    void     (*sa_handler)(int);        // handler đơn giản
    void     (*sa_sigaction)(int, siginfo_t *, void *); // handler nâng cao
    sigset_t sa_mask;                  // block thêm signal trong handler
    int      sa_flags;                 // flag điều khiển
};
```

---

# 🔑 Các thành phần quan trọng

## 1. `sa_handler`

```cpp
void handler(int sig);
```

👉 giống `signal()`

---

## 2. `sa_sigaction` (pro hơn)

```cpp
void handler(int sig, siginfo_t *info, void *context);
```

👉 cho thêm thông tin:

* PID gửi signal
* UID
* giá trị kèm theo (real-time signal)

---

## 3. `sa_flags`

### Các flag hay dùng:

| Flag           | Ý nghĩa                         |
| -------------- | ------------------------------- |
| `SA_SIGINFO`   | dùng `sa_sigaction`             |
| `SA_RESTART`   | tự restart syscall bị interrupt |
| `SA_NODEFER`   | không block chính signal đó     |
| `SA_RESETHAND` | handler chỉ chạy 1 lần          |
| `SA_NOCLDWAIT` | không tạo zombie process        |

---

## 4. `sa_mask`

👉 danh sách signal bị block khi handler đang chạy

Ví dụ:

```cpp
sigemptyset(&act.sa_mask);
sigaddset(&act.sa_mask, SIGINT);
```

---

# 🔥 2. Ví dụ dùng `sigaction`

```cpp
#include <iostream>
#include <signal.h>
#include <unistd.h>

using namespace std;

void handler(int sig)
{
    write(STDOUT_FILENO, "Received SIGUSR1\n", 18);
}

int main()
{
    struct sigaction act;

    act.sa_handler = handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_RESTART;

    sigaction(SIGUSR1, &act, NULL);

    while (1)
        pause();
}
```

---

# 🚀 3. Ví dụ nâng cao với `SA_SIGINFO`

```cpp
void handler(int sig, siginfo_t *info, void *context)
{
    char buf[100];
    int len = snprintf(buf, sizeof(buf),
                       "Signal from PID: %d\n", info->si_pid);
    write(STDOUT_FILENO, buf, len);
}
```

```cpp
act.sa_sigaction = handler;
act.sa_flags = SA_SIGINFO;
```

---

# ⚔️ 4. So sánh `signal()` vs `sigaction()`

| Tiêu chí          | `signal()`                                 | `sigaction()`     |
| ----------------- | ------------------------------------------ | ----------------- |
| Chuẩn POSIX       | ❌ không chuẩn (behavior khác nhau giữa OS) | ✅ chuẩn           |
| Kiểm soát         | ❌ rất ít                                   | ✅ đầy đủ          |
| Độ ổn định        | ❌ không đáng tin                           | ✅ ổn định         |
| Restart syscall   | ❌ không đảm bảo                            | ✅ có `SA_RESTART` |
| Thông tin signal  | ❌ không có                                 | ✅ có `siginfo_t`  |
| Block signal khác | ❌ không                                    | ✅ có `sa_mask`    |
| Dùng production   | ❌ không nên                                | ✅ bắt buộc        |

---

# 💣 5. Điểm nguy hiểm của `signal()`

## ❗ Behavior không consistent

Trên một số hệ:

```cpp
signal(SIGINT, handler);
```

👉 sau khi handler chạy xong:

* có hệ: handler vẫn giữ
* có hệ: handler bị reset về default 😱

---

## ❗ Syscall bị interrupt

```cpp
read(fd, buf, size);
```

Nếu có signal:

* `signal()` → syscall có thể fail (`EINTR`)
* `sigaction()` + `SA_RESTART` → tự chạy lại

---

# 🧠 6. Khi nào dùng gì?

## ❌ Không dùng `signal()` khi:

* viết code production
* làm embedded Linux / system programming
* multi-process / multi-thread

## ✅ Luôn dùng `sigaction()` khi:

* cần ổn định
* cần debug chuẩn
* cần behavior predictable

---

# 🎯 7. Best Practice

### ✅ Template chuẩn:

```cpp
struct sigaction act;
memset(&act, 0, sizeof(act));

act.sa_handler = handler;
sigemptyset(&act.sa_mask);
act.sa_flags = SA_RESTART;

if (sigaction(SIGINT, &act, NULL) == -1)
{
    perror("sigaction");
    exit(1);
}
```

---

# 🧠 Insight quan trọng

👉 `signal()` thực chất thường được implement bằng `sigaction()` phía dưới, **nhưng bị giới hạn behavior**

👉 Vì vậy:

> `signal()` = bản rút gọn, thiếu kiểm soát
> `sigaction()` = bản đầy đủ, dùng cho system-level

---

# 🚀 Nếu bạn muốn đi sâu hơn

Mình có thể giúp bạn:

* demo race condition khi dùng signal
* viết framework xử lý signal kiểu production (graceful shutdown)
* hoặc tích hợp với `epoll` / `signalfd` (rất xịn cho Linux)

Chỉ cần nói 👍



# Bảng sa_flags

| Flag                | Nhóm            | Ý nghĩa ngắn gọn                      | Chi tiết                                                          | Khi nên dùng                   |
| ------------------- | --------------- | ------------------------------------- | ----------------------------------------------------------------- | ------------------------------ |
| `SA_NOCLDSTOP`      | SIGCHLD         | Bỏ qua stop/resume của child          | Không nhận `SIGCHLD` khi child bị `SIGSTOP`, `SIGTSTP`, `SIGCONT` | Khi chỉ quan tâm child chết    |
| `SA_NOCLDWAIT`      | SIGCHLD         | Không tạo zombie                      | Child chết → kernel tự dọn, không cần `wait()`                    | Server fork nhiều process      |
| `SA_NODEFER`        | Handler control | Cho phép signal lặp lại trong handler | Signal không bị block khi handler đang chạy → có thể re-enter     | Rất hiếm, cần nested signal    |
| `SA_ONSTACK`        | Stack           | Dùng stack riêng                      | Handler chạy trên stack từ `sigaltstack()`                        | Crash handler, system critical |
| `SA_RESETHAND`      | Handler control | Handler chạy 1 lần                    | Sau khi chạy → reset về default (`SIG_DFL`)                       | Trap/debug, xử lý 1 lần        |
| `SA_RESTART`        | Syscall         | Tự restart syscall                    | Nếu syscall bị interrupt → tự chạy lại                            | Gần như luôn dùng              |
| `SA_SIGINFO`        | Advanced        | Handler 3 tham số                     | Dùng `sa_sigaction`, nhận thêm `siginfo_t`                        | Debug, IPC, realtime signal    |
| `SA_RESTORER`       | Internal        | Dùng nội bộ libc                      | Liên quan `sigreturn()`                                           | ❌ Không dùng                   |
| `SA_UNSUPPORTED`    | Kernel probe    | Test kernel support flag              | Kiểm tra flag nào kernel hỗ trợ                                   | Viết lib portable              |
| `SA_EXPOSE_TAGBITS` | Memory debug    | Giữ tag bits trong `si_addr`          | Dùng cho kiến trúc có memory tagging (ARM MTE)                    | Debug low-level                |
