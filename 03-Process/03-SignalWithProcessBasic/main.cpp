/*
Mô tả: Viết một chương trình tạo hai process cha - con. Tiến trình cha sẽ gửi tín hiệu SIGUSR1 tới tiến trình con sau một khoảng thời gian.
Yêu cầu:
Sử dụng signal() để định nghĩa hành vi của tiến trình con khi nhận tín hiệu SIGUSR1.
In ra một thông báo khi tiến trình con nhận được tín hiệu.


ý tưởng: do chưa học signal nên sẽ dùng tập exec để thực thi cmd "kill -10 <pid>" vì trong bảng kill SIGUSR1 là 10 (có thể chạy kill -l để xem chi tiết)
 */


#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>



using namespace std;

// Hàm xử lý signal
void handle_sigterm(int sig) {

    printf("Process con nhận được tín hiệu kill (SIGUSR1)!\n");
    exit(0); // thoát sau khi xử lý
}


int main ()
{
    pid_t pid = fork();

    int status;

    if (pid < 0)
    {
        perror ("ERROR when create process: ");
    }

    if (pid == 0)
    {
        cout << "i'm chill process with pid:" << getpid() << endl;

        signal(SIGUSR1, handle_sigterm); // đăng ký handler

        while(1); // chờ process cha gửi lệnh kill
    }
    if (pid > 0)
    {
        cout << ">> i'm parent process with pid:" << getpid() << endl;
        cout << ">> my chill process have pid:" << pid << endl;
        
        sleep (2);

        execlp("kill", "kill", "-10", to_string(pid).c_str(), NULL);
        wait (NULL);
    }
    return 0;
}