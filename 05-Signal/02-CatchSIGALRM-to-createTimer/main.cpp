/*
BT2. Sử dụng Tín hiệu SIGALRM để Tạo Timer
    Yêu cầu: Viết chương trình tạo một bộ đếm thời gian bằng cách sử dụng tín hiệu SIGALRM.
    Sử dụng hàm alarm() để đặt thời gian kích hoạt SIGALRM mỗi giây.
    Khi nhận tín hiệu SIGALRM, chương trình sẽ tăng biến đếm và in ra dòng "Timer: <giây> seconds".
    Dừng chương trình sau khi đếm đến 10 giây.
Gợi ý: Sử dụng hàm signal() để đăng ký xử lý tín hiệu SIGALRM, và đặt alarm(1) để bộ đếm lặp lại hàng giây.
Câu hỏi: Điều gì xảy ra nếu không gọi lại alarm(1) trong hàm xử lý? =>> signal chỉ hoạt động 1 lần. Sau đó alarm không hoạt động nữa => timer không được hình thành

link signal: https://man7.org/linux/man-pages/man2/signal.2.html

*/

#include <iostream>
#include <signal.h>

#include <unistd.h> // -> for alarm

using namespace std;

// Time alarm (second)
#define TIME_ALARM 1

// signal handler
void handler_SIGALRM (int sig)
{
    static int count_alarm = 0;
    cout << "alarm is receive" << endl;
    cout << "count_alarm value:" << count_alarm++ << endl;
    alarm(TIME_ALARM);
    if (count_alarm > 9)
        exit(EXIT_SUCCESS);
}

int main (int argv, char * argc[]){

    signal (SIGALRM, handler_SIGALRM);

    cout << "waiting for signal" << endl;
    cout << "Sig PID:" << getpid() << endl;

    cout << "alram init:" << alarm(TIME_ALARM) << endl;

    while (1)
    {
        // if (count < 1)
        // {
        //     cout << "Alarm Value:" << alarm(TIME_ALARM) << endl;
        // }
        sleep(1);
    }
}