/*
BT5. Tạo Process Zombie và Orphan
Mô tả: Viết một chương trình tạo ra một tiến trình zombie và một tiến trình orphan để hiểu về các loại tiến trình đặc biệt này.
Yêu cầu:
    Để tạo zombie, cho tiến trình cha kết thúc sớm trong khi tiến trình con vẫn còn chạy, và sử dụng ps để quan sát trạng thái zombie của tiến trình.
    Để tạo orphan, cho tiến trình con ngủ trong một khoảng thời gian dài hơn tiến trình cha, để tiến trình con trở thành orphan.
    Giải thích trạng thái zombie và orphan, cùng lý do tại sao chúng xuất hiện trong Linux

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
    }
    else if (pid > 0)
    {
        cout << ">> i'm parent process with pid:" << getpid() << endl;
        cout << ">> my chill process have pid:" << pid << endl;
        while (1);
    }
    return 0;


}

// lệnh check: ducanhwsl@admin:~$ ps aux | grep <pid-process>
// ducanhw+    1592  0.0  0.0      0     0 pts/2    Z+   02:10   0:00 [run] <defunct>
// ducanhw+    1600  0.0  0.0   4088  1920 pts/0    S+   02:12   0:00 grep --color=auto 1592
// process 1592 chính là zoombie (trạng thái Z+)
