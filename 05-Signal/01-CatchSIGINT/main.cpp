/*
BT1. Bắt Tín hiệu SIGINT
Yêu cầu: Viết một chương trình bắt tín hiệu SIGINT (được gửi khi nhấn Ctrl+C) và in ra thông báo khi nhận được tín hiệu này.
    Sử dụng hàm signal() để đăng ký một hàm xử lý cho tín hiệu SIGINT.
    Trong hàm xử lý, in ra thông báo "SIGINT received" mỗi khi nhận được tín hiệu SIGINT.
    Chương trình sẽ tiếp tục chạy cho đến khi nhận được SIGINT lần thứ 3, sau đó kết thúc.
Gợi ý: Sử dụng một biến đếm toàn cục để đếm số lần tín hiệu SIGINT được nhận và kiểm tra biến này trong hàm xử lý.
Câu hỏi: Nếu bỏ qua tín hiệu SIGINT, chuyện gì sẽ xảy ra khi nhấn Ctrl+C? => khi bỏ qua sigint thì khi nhấn Ctrl+C, handler sẽ catch nó và xử lý bên trong chứ không dừng chương trình cho tới khi được phép

link signal: https://man7.org/linux/man-pages/man2/signal.2.html

*/

#include <iostream>
#include <signal.h>

using namespace std;

// signal handler
void handler_sigint (int sig)
{
    static int count_sig = 0;
    cout << "SIGINT received" << count_sig++ << endl;
    if (count_sig > 3)
        exit (EXIT_SUCCESS);
}

int main (int argv, char * argc[]){

    signal (SIGINT, handler_sigint);

    cout << "waiting for signal" << endl;
    cout << "Sig PID:" << getpid() << endl;
    while (1);
}