/*
BT2. Đồng Bộ Hóa Threads với Mutex
Viết một chương trình sử dụng pthread và mutex để thực hiện các thao tác sau:
    Tạo một biến toàn cục counter khởi tạo bằng 0.
    Tạo ba threads, mỗi thread tăng giá trị của counter lên 1, 1.000.000 lần.
    Sử dụng mutex để đảm bảo rằng việc tăng counter được thực hiện an toàn.
    In ra giá trị cuối cùng của counter khi tất cả các threads hoàn thành.
Hỏi: Tại sao cần mutex trong bài này? Điều gì xảy ra nếu bỏ mutex? ==> biến count sẽ có giá trị không xác định, đếm sai giá trị mong muốn
Gợi ý: Sử dụng pthread_mutex_lock và pthread_mutex_unlock để khóa và mở khóa mutex khi truy cập vào counter.

*/


#include <iostream>
#include <pthread.h>

#include <unistd.h>

using namespace std;
int count = 0;

// khai báo biến mutex
pthread_mutex_t mutexVariable = PTHREAD_MUTEX_INITIALIZER;

// nếu muốn tái hiện trường hợp RACE_CONDITION thì define nó. Nếu muốn hoạt động bth thì không define nó.
// #define RACE_CONDITION

void * my_thread (void * arg){

    cout <<"My thread name: " << __FUNCTION__ << "\tThis is my thread ID: " << pthread_self()  << endl;

    #ifndef RACE_CONDITION
        // use mutex to prevent race condition. Otherwise, use mutex to go to "critical section"!
        pthread_mutex_lock(&mutexVariable);
        for (int i=0; i<10000; i++)
        {
            count++;
        }
        printf ("Thread id: %ld \tmy count:: %d\n", pthread_self(), count);
        pthread_mutex_unlock (&mutexVariable);
    #else
        // not use mutex => race conditon (nonatomic) => số tăng loạn xạ không kiểm soát và giá trị cuôi cùng trả ra không đúng như mong muốn
        for (int i=0; i<10000; i++)
        {
            count++;
        }
        printf ("Thread id: %ld \tmy count:: %d\n", pthread_self(), count);
    #endif

    
    printf ("thread %ld is finished\n", pthread_self());
    return NULL;

}

int main (int argv, char * argc[]){

    // INIT MUTEX
    if (pthread_mutex_init (&mutexVariable, NULL) < 0)
    {
        perror ("ERROR when init mutex: ");
    }

    pthread_t threadID[2];
    // tạo 2 thread
    for (int i=0; i<2; i++)
    {
        int status = pthread_create (&threadID[i], NULL, my_thread, NULL);
        if (status < 0)
        {
            perror ("error when create thread!");
        }
    }

    // nếu không thêm hàm này, thread chưa kịp chạy thì main đã bị kết thúc khiến cho thread bị crash và dừng luôn
    pthread_join(threadID[0], NULL);
    pthread_join(threadID[1], NULL);   

    // destroy mutex to flush resource
    pthread_mutex_destroy (&mutexVariable);
    return 0;
}

