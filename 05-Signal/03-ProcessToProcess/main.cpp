/*
BT3. Tạo Giao tiếp giữa Các Process bằng Tín hiệu
Yêu cầu: Viết chương trình tạo hai process (cha và con) và sử dụng tín hiệu SIGUSR1 để giao tiếp giữa chúng.
Cách thực hiện
    Dùng fork() để tạo process con từ process cha.
    Process cha sẽ gửi tín hiệu SIGUSR1 cho process con mỗi 2 giây.
    Khi nhận tín hiệu SIGUSR1, process con sẽ in ra thông báo "Received signal from parent".
    Dừng chương trình sau khi đã gửi tín hiệu 5 lần.
Gợi ý: Dùng kill() để gửi tín hiệu từ process cha đến process con, và sử dụng signal() trong process con để bắt tín hiệu SIGUSR1.
Câu hỏi: Tại sao chúng ta cần sử dụng kill() để gửi tín hiệu trong bài này? => có thể xử lý một số tác vụ mà process cha muốn kiểm soát hoặc dừng khẩn cấp process con

link signal: https://man7.org/linux/man-pages/man2/signal.2.html

*/

#include <iostream>
#include <signal.h>

#include <unistd.h> // -> for alarm
#include <sys/wait.h>

using namespace std;

// Time alarm (second)
#define TIME_ALARM 1

// count to exit
#define COUNT_TO_EXIT 5

// signal handler
void handler_SIGUSR1 (int sig)
{
    static int count_alarm = 0;
    if (sig == SIGUSR1)
    {
        cout << "SIGUSR1 is receive" << endl;
        cout << "count_alarm value:" << count_alarm++ << endl;

        if (count_alarm > 9)
            exit(EXIT_SUCCESS);
    }
    
}

int main (int argv, char * argc[]){

    cout << "waiting for signal" << endl;
    cout << "Main PID:" << getpid() << endl;

    pid_t pid = fork();

    // process con đăng ký signal và lắng nghe process cha gửi signal
    if (pid == 0)
    {
        signal (SIGUSR1, handler_SIGUSR1);
        cout << "I'm chill process | my pid:" << getpid() << endl;
        cout << "my parrent pid:" << getppid() << endl;

        while (1);
    }
    
    // process cha gửi 10 signal tới process con
    for (int i=0; i<10; i++)
    {
        sleep (1);
        cout << "my child pid:" << pid << endl;
        kill (pid, SIGUSR1);
    }
    cout << "I am parent process with pid:" << getpid() << endl;

    wait(NULL);
}