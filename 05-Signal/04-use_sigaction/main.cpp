/*
BT4. Viết một chương trình có thể bỏ qua tín hiệu SIGTSTP (thường là Ctrl+Z).
    Sử dụng signal() hoặc sigaction() để bắt và bỏ qua tín hiệu SIGTSTP.
    Khi nhận tín hiệu SIGTSTP, chương trình sẽ không dừng mà tiếp tục chạy và in thông báo "SIGTSTP ignored".
    Gợi ý: Đảm bảo chương trình sẽ tiếp tục chạy thay vì bị dừng khi nhấn Ctrl+Z.
Câu hỏi: Điều gì xảy ra nếu không xử lý tín hiệu SIGTSTP và người dùng nhấn Ctrl+Z?

link signal: https://man7.org/linux/man-pages/man2/signal.2.html

*/

#include <iostream>
#include <signal.h>

#include <unistd.h> // -> for alarm
#include <sys/wait.h>

using namespace std;

// count to exit
#define COUNT_TO_EXIT 5

// signal handler
void handler_SIGTSTP (int sig)
{
    static int count_alarm = 0;
    if (sig == SIGTSTP)
    {
        cout << "SIGTSTP is receive" << endl;
        cout << "count_alarm value:" << count_alarm++ << endl;

        if (count_alarm > 9)
            exit(EXIT_SUCCESS);
    }
    
}

int main (int argv, char * argc[]){

    cout << "waiting for signal" << endl;
    cout << "Main PID:" << getpid() << endl;

    // khai báo struct
    struct sigaction act;

    act.sa_handler = handler_SIGTSTP;

    sigaction (SIGTSTP, &act, NULL);

    while (1) {
        sleep(1);
    }

}