/*
BT1. Tạo và Chạy Threads Cơ Bản
Viết một chương trình sử dụng thư viện pthread.h để thực hiện các thao tác sau:
    Tạo hai threads. Mỗi thread sẽ in ra một chuỗi thông báo kèm theo ID của thread (ví dụ: "Thread 1: Hello from thread").
    Sử dụng hàm pthread_join để đợi cả hai threads hoàn thành trước khi chương trình kết thúc.
    Sử dụng pthread_create và pthread_join như thế nào? Khi nào thread kết thúc?
Gợi ý: Sử dụng hàm pthread_create để tạo threads và pthread_join để chờ các threads hoàn thành.

*/


#include <iostream>
#include <pthread.h>

#include <unistd.h>

using namespace std;

// nếu muốn tái hiện trường hợp RACE_CONDITION thì define nó. Nếu muốn hoạt động bth thì không define nó.
// #define RACE_CONDITION


#ifdef RACE_CONDITION
void * my_thread (void * arg){

    // sử dụng argument truyền vào để xử lý
    int * indexThread = (int *)arg;
   
    // lấy giá trị pthread_id và tên thread in ra màn hình
    cout <<"My thread name: " << __FUNCTION__ << "\t my index: " << *indexThread << "\tThis is my thread ID: " << pthread_self()  << endl;
    sleep (5);
    
    printf ("thread %d is finished\n", (*indexThread));
    return NULL;

}
#endif
#ifndef RACE_CONDITION
void * my_thread (void * arg){

    // sử dụng argument truyền vào để xử lý
    int * indexThread = (int *)arg;

    // thread index 1 thì sleep 1s, thread index 2 thì sleep 2s vì nếu không làm vậy thì bị in chồng chéo, RACE CONDITION STDOUT
    // cách đơn giản nhất để tránh Race condition nhưng chỉ là tạm thời, cần thêm mutex và enviroment variable để xử lý cho chuyên nghiệp. Thực hiện ở bài tập 2
    sleep ((*indexThread));

    // lấy giá trị pthread_id và tên thread in ra màn hình
    cout <<"My thread name: " << __FUNCTION__ << "\t my index: " << *indexThread << "\tThis is my thread ID: " << pthread_self()  << endl;
    sleep (2);
    
    printf ("thread %d is finished\n", (*indexThread));
    return NULL;

}
#endif

int main (int argv, char * argc[]){

#ifdef RACE_CONDITION
    int count = 1;
    pthread_t threadID[2];

    // tạo 2 thread
    for (int i=0; i<2; i++)
    {
        int status = pthread_create (&threadID[i], NULL, my_thread, &count);
        if (status < 0)
        {
            perror ("error when create thread!");
        }
        count++;        
    }

    // nếu không thêm hàm này, thread chưa kịp chạy thì main đã bị kết thúc khiến cho thread bị crash và dừng luôn
    pthread_join(threadID[0], NULL);
    pthread_join(threadID[1], NULL);   
#endif 
#ifndef RACE_CONDITION

    int index[2] = {0, 1};
    pthread_t threadID[2];

    // tạo 2 thread
    for (int i=0; i<2; i++)
    {
        int status = pthread_create (&threadID[i], NULL, my_thread, &index[i]);
        if (status < 0)
        {
            perror ("error when create thread!");
        }     
    }

    // nếu không thêm hàm này, thread chưa kịp chạy thì main đã bị kết thúc khiến cho thread bị crash và dừng luôn
    pthread_join(threadID[0], NULL);
    pthread_join(threadID[1], NULL);
#endif
    return 0;
}

