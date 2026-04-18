/*
BT5. Chia Sẻ Tài Nguyên Với Read-Write Lock
Viết một chương trình mô phỏng tình huống có nhiều thread đọc và ghi dữ liệu:
    Tạo một biến data chứa một số nguyên.
    Tạo 5 threads đọc và 2 threads ghi:
    Các thread đọc sẽ chỉ đọc data mà không thay đổi.
    Các thread ghi sẽ tăng giá trị của data lên 1.
    Sử dụng read-write lock để đảm bảo nhiều threads có thể đọc cùng lúc, nhưng chỉ một thread được ghi tại bất kỳ thời điểm nào.
    In ra giá trị của data sau khi tất cả các threads hoàn thành.
Gợi ý: Sử dụng pthread_rwlock_rdlock và pthread_rwlock_wrlock cho đọc-ghi đồng bộ.
// bài này hoàn toàn có thể sử dụng mutex và condition variable tuy nhiên phần pthread_rwlock_rdlock và pthread_rwlock_wrlock đã xử lý cho rồi nên sử dụng luôn

    pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;

    // Khởi tạo động (nếu cần)
    pthread_rwlock_init(&rwlock, NULL);

    // Khóa đọc (nhiều thread có thể giữ cùng lúc)
    pthread_rwlock_rdlock(&rwlock);

    // Khóa ghi (độc quyền)
    pthread_rwlock_wrlock(&rwlock);

    // Mở khóa (dùng chung cho cả read và write)
    pthread_rwlock_unlock(&rwlock);

    // Hủy
    pthread_rwlock_destroy(&rwlock);

*/


#include <iostream>
#include <pthread.h>

#include <unistd.h>
#include <pthread.h>

using namespace std;

#define NUM_THREAD_READ 5
#define NUM_THREAD_WRITE 5
#define TOTAL_THREAD (NUM_THREAD_READ+NUM_THREAD_WRITE)

// tạo biến data là biến dùng chung
int mydata = 0;
pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;

// Thread đọc
void * readThread (void * arg){

    while (1)
    {
        int status = pthread_rwlock_rdlock(&rwlock);
        if (status < 0)
        {
            perror ("Error while read: ");
        }
        cout << "data in thread read"<< pthread_self() << " have value is: " << mydata << endl;
        pthread_rwlock_unlock(&rwlock);

        sleep (1);
    }
    return NULL;
}

// thread ghi
void * writeThread (void * arg){
    cout << "thread write:"<< endl;
    while (1){
        int status = pthread_rwlock_wrlock(&rwlock);
        if (status < 0)
        {
            perror ("Error while lock write: ");
        }

        // tăng dữ liệu lên (ghi dữ liệu)
        mydata +=10;

        pthread_rwlock_unlock(&rwlock);
        sleep (1);
    }
    
    return NULL;
}

int main (int argv, char * argc[]){

    // tạo thread ID:
    pthread_t threadID[TOTAL_THREAD];
    
    // khởi tạo thread
    for (int i=0; i<TOTAL_THREAD; i++)
    {
        if (i < NUM_THREAD_READ)
        {
            int status = pthread_create (&threadID[i], NULL, &readThread, NULL);
            if (status < 0)
            {
                perror ("Error when create thread read: ");
            }
            
        }
        else
        {
            int status = pthread_create (&threadID[i], NULL, &writeThread, NULL);
            if (status < 0)
            {
                perror ("Error when create thread write: ");
            }
            
        }

    }

    // join thread
    for (int i=0; i<TOTAL_THREAD; i++)
    {
        pthread_join (threadID[i], NULL);
    }
    
    
    return 0;
}
