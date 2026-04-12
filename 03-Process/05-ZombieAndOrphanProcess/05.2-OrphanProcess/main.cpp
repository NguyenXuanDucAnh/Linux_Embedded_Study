/*
BT5. Tạo Process Zombie và Orphan
Mô tả: Viết một chương trình tạo ra một tiến trình zombie và một tiến trình orphan để hiểu về các loại tiến trình đặc biệt này.
Yêu cầu:
    Để tạo zombie, cho tiến trình cha kết thúc sớm trong khi tiến trình con vẫn còn chạy, và sử dụng ps để quan sát trạng thái zombie của tiến trình.
    Để tạo orphan, cho tiến trình con ngủ trong một khoảng thời gian dài hơn tiến trình cha, để tiến trình con trở thành orphan.
    Giải thích trạng thái zombie và orphan, cùng lý do tại sao chúng xuất hiện trong Linux

 */

 /*
 Tiến trình orphan: tiến trình cha kết thúc trước nên tiến trình con không có ai để giải phóng bộ nhớ!
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
        signal(SIGHUP, SIG_IGN);

        cout << "i'm chill process with pid:" << getpid() << endl;

        sleep(10); // thay vì while(1)

        cout << "child still alive after parent died" << endl;
    }
    else if (pid > 0)
    {
        cout << ">> i'm parent process with pid:" << getpid() << endl;
        cout << ">> my chill process have pid:" << pid << endl;
        // while (1);
    }
    return 0;


}

/*
Để chắc chắn tạo được một orphan process, cần phải xử lý một vđề sau:
Khi parent process kết thúc:

Terminal có thể gửi tín hiệu:
SIGHUP (hangup)
Tất cả process liên quan (cùng session/process group) sẽ bị kill

➡️ Child của bạn cũng bị chết theo

==> Giải pháp: Tiến hành tạo signal hứng SIGUP (process sẽ phải xử lý thay vì kill như bth - học thêm về signal sẽ hiểu)
*/
