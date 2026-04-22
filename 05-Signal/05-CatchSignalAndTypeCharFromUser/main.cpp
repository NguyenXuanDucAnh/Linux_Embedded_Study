/*
BT5. Chương trình chờ tín hiệu kết hợp chờ người dùng nhập liệu
Mục tiêu: Viết một chương trình có thể nhận tín hiệu đồng thời cho phép người dùng nhập liệu từ bàn phím.
    Hướng dẫn:
        Dùng select() hoặc poll() để cho phép chương trình xử lý tín hiệu mà không làm gián đoạn khi nhận dữ liệu nhập từ bàn phím.
        Khi nhận tín hiệu SIGINT, in ra thông báo “SIGINT received.”
        Nếu nhận tín hiệu SIGTERM, thoát chương trình.
Gợi ý: Kết hợp giữa việc bắt tín hiệu và đọc nhập liệu để chương trình linh hoạt hơn.


link signal: https://man7.org/linux/man-pages/man2/signal.2.html

*/

#include <iostream>
#include <signal.h>

#include <unistd.h> // -> for alarm
#include <sys/wait.h>

using namespace std;


// signal handler
void handler_SIGTSTP (int sig)
{    
}

int main (int argv, char * argc[]){

    cout << "waiting for signal" << endl;
    cout << "Main PID:" << getpid() << endl;


    exit(EXIT_SUCCESS);
}