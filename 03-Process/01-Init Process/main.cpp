
// BT1. Khởi tạo và Theo dõi Process
// Mô tả: Viết một chương trình C tạo một process con bằng cách sử dụng fork(). Sau khi tạo process, tiến trình con sẽ in ra PID của nó và tiến trình cha in ra PID của tiến trình con

#include <stdio.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int main ()
{
    pid_t pid = fork();
    if (pid >= 0)
    {
        if (pid > 0)
        {
            cout << "I am parent process: " << getpid() << endl;
        }
        if (pid == 0)
        {
            cout << "I am chill process: " << getpid() << " my parrent process have pid is: " << getppid() << endl;
        }
    }
    else
    {
        perror ("Error when create process: ");
    }
    return 0;
}