/*
BT4. Ghi nhận Trạng thái Process
Mô tả: Viết một chương trình tạo một tiến trình con, sau đó tiến trình cha sử dụng wait() để chờ tiến trình con kết thúc và ghi nhận trạng thái kết thúc của nó.

Yêu cầu:
    Trong tiến trình con, chọn trạng thái kết thúc bằng cách gọi exit() với các giá trị khác nhau.
    Sử dụng WIFEXITED() và WEXITSTATUS() để xác nhận và ghi nhận mã thoát của tiến trình con.
 */


#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main (int argv, char * argc [])
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

        // while (1);
        sleep (5);
        exit(atoi(argc [1])); // lấy argument để làm trạng thái exit
    }
    else if (pid > 0)
    {
        cout << ">> i'm parent process with pid:" << getpid() << endl;
        cout << ">> my chill process have pid:" << pid << endl;
        wait (&status);

        // WIFEXITED(wstatus) returns true if the child terminated normally, 
        // that is, by calling exit(3) or _exit(2), or by returning from main()
        cout <<  WIFEXITED(status) << endl; 

        //  WEXITSTATUS(status) returns the exit status of the child.  This consists of the
        //   least significant 8 bits of the status argument that the
        //   child specified in a call to exit(3) or _exit(2) or as the
        //   argument for a return statement in main().  This macro
        //   should be employed only if WIFEXITED returned true.
        cout <<  WEXITSTATUS(status) << endl; 

        /* READ MORE in: https://man7.org/linux/man-pages/man2/wait.2.html*/
    }
    return 0;
}
