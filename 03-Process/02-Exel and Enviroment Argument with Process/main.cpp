/**
BT2. Sử dụng exec và Biến Môi Trường
Mô tả: Viết một chương trình trong đó tiến trình con sẽ thay thế chương trình đang chạy bằng một chương trình khác, ví dụ ls hoặc date, sử dụng hàm execlp() hoặc execvp().
Yêu cầu:
Truyền các biến môi trường vào chương trình và thực hiện các công việc khác nhau (ví dụ biến môi trường được truyền vào là 1 thì thực hiện lệnh ls, nếu là 2 thì thực hiện lệnh date).
Giải thích điều gì xảy ra với tiến trình ban đầu sau khi exec được gọi.
=> Giải thích: khi tiến trình gọi hàm exe thì tiến trình sẽ kết thúc khi gọi. Nên nếu gọi hai hàm exec trong cùng 1 process thì hàm nào được gọi trước sẽ được thực hiện còn hàm nào gọi sau thì sẽ không thực hiện do tiến trình đã kết thúc trước khi tới được hàm exec sau.
 */



#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

#include <cstring>

using namespace std;

enum {
    CMD = 1, // ls or date
    OPTION  // 1 or 2 (1 is execlp, 2 is execvp)
};

int main (int argv, char * argc [])
{
    for (int i = 0; i< argv; i++)
    {
        cout << "argument: " << argc [i] << endl;
    }


    pid_t pid = fork();
    if (pid >= 0)
    {
        if (pid > 0)
        {
            cout << "I am parent process: " << getpid() << endl;
            wait (NULL);
        }
        if (pid == 0)
        {
            cout << "I am chill process: " << getpid() << " my parrent process have pid is: " << getppid() << endl;

            /* NẾU GỌI NHƯ CÁCH NÀY THÌ CHỈ THỰC HIỆN HÀM EXECLP THÔI VÌ PROCESS SẼ KẾT THÚC TRƯỚC KHI TỚI ĐƯỢC HÀM TIẾP THEO */
            // // THỰC THI HÀMexeclp ()
            // cout << "date execlp: " << endl;
            // execlp("date", "--date='@2147483647'", NULL) ;

            //  // THỰC THI HÀM execvp ()
            // // Array of arguments: program name, options, and terminating NULL
            // char *args[] = {(char*)"ls", (char*)"-la", NULL};

            // // Execute 'ls' with the arguments in 'args'
            // // If successful, this process is replaced and the next line never runs
            // execvp("ls", args);
            if (strcmp (argc[CMD], "ls") == 0)
            {
                if (strcmp (argc[OPTION], "1") == 0)
                {
                    execlp("ls", "ls", "-l", "-a", NULL) ;
                }
                if (strcmp (argc[OPTION], "2") == 0)
                {
                     // THỰC THI HÀM execvp ()
                    // Array of arguments: program name, options, and terminating NULL
                    char *args[] = {(char*)"ls", (char*)"-la", NULL};

                    // Execute 'ls' with the arguments in 'args'
                    // If successful, this process is replaced and the next line never runs
                    execvp("ls", args);
                }
            }
            if (strcmp (argc[CMD], "date") == 0)
            {
                if (strcmp (argc[OPTION], "1") == 0)
                {
                    execlp("date", "date", "--date=@2147483647", NULL) ;
                }
                if (strcmp (argc[OPTION], "2") == 0)
                {
                     // THỰC THI HÀM execvp ()
                    // Array of arguments: program name, options, and terminating NULL
                    char *args[] = {(char*)"date", (char*)"--date=@2147483647", NULL};

                    // Execute 'ls' with the arguments in 'args'
                    // If successful, this process is replaced and the next line never runs
                    execvp("date", args);
                }
            }
        }
    }
    else
    {
        perror ("Error when create process: ");
        
    }
    return 0;
}