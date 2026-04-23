/*
BT5. Chương trình chờ tín hiệu kết hợp chờ người dùng nhập liệu
Mục tiêu: Viết một chương trình có thể nhận tín hiệu đồng thời cho phép người dùng nhập liệu từ bàn phím.
    Hướng dẫn:
        Dùng select() hoặc poll() để cho phép chương trình xử lý tín hiệu mà không làm gián đoạn khi nhận dữ liệu nhập từ bàn phím.
        Khi nhận tín hiệu SIGINT, in ra thông báo “SIGINT received.”
        Nếu nhận tín hiệu SIGTERM, thoát chương trình.
Gợi ý: Kết hợp giữa việc bắt tín hiệu và đọc nhập liệu để chương trình linh hoạt hơn.


Giải thích: Đây là loại bug gọi là Heisenbug — chạy thử thì không tái hiện, lên production mới chết. Đó là lý do bài tập yêu cầu dùng poll() + signalfd — không phải vì cách cũ luôn sai, mà vì cách mới đảm bảo không bao giờ sai.

link signal: https://man7.org/linux/man-pages/man2/signal.2.html
*/

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <poll.h>
#include <signal.h>
#include <sys/signalfd.h>

int main() {
    // Bước 1: Chặn SIGINT và SIGTERM — không dùng handler cũ nữa
    sigset_t mask;
    // Tạo một "danh sách signal" rỗng (mask = bộ lọc, chưa có gì trong đó)
    sigemptyset(&mask);
    // Thêm SIGINT (Ctrl+C) vào danh sách "muốn chặn"
    sigaddset(&mask, SIGINT);
    // Thêm SIGTERM (kill) vào danh sách "muốn chặn"
    sigaddset(&mask, SIGTERM);
    // Áp dụng danh sách lên process:
    // SIG_BLOCK = "chặn các signal trong mask lại, đừng cho nhảy vào handler nữa"
    // Từ đây SIGINT và SIGTERM sẽ bị pending (xếp hàng chờ)
    // signalfd sẽ là nơi duy nhất đọc chúng ra
    sigprocmask(SIG_BLOCK, &mask, nullptr);
    // => bản chất bước này là đưa hai signal vào pending để dùng được với poll()

    // Bước 2: Tạo signalfd — signal giờ đây đọc được như file
    int sfd = signalfd(-1, &mask, 0);

    // Bước 3: Cấu hình poll() theo dõi 2 fd
    struct pollfd fds[2];
    fds[0].fd     = STDIN_FILENO;  // bàn phím
    fds[0].events = POLLIN;
    fds[1].fd     = sfd;           // signal
    fds[1].events = POLLIN;

    std::cout << "Đang chờ... (Ctrl+C = SIGINT, kill = SIGTERM)\n";

    while (true) {
        int ready = poll(fds, 2, -1);
        if (ready < 0) break;

        // Bàn phím có data
        if (fds[0].revents & POLLIN) {
            std::string line;
            std::getline(std::cin, line);
            std::cout << "Bạn nhập: " << line << "\n";
        }

        // Có signal đến
        if (fds[1].revents & POLLIN) {
            struct signalfd_siginfo info;
            read(sfd, &info, sizeof(info));  // đọc signal như đọc file

            if (info.ssi_signo == SIGINT) {
                std::cout << "SIGINT received.\n";
                // KHÔNG thoát, tiếp tục vòng lặp
            }
            else if (info.ssi_signo == SIGTERM) {
                std::cout << "SIGTERM received. Thoát.\n";
                break;
            }
            std::cout << "thực hiện xong even signal" << std::endl;
        }
    }

    close(sfd);
    return 0;
}