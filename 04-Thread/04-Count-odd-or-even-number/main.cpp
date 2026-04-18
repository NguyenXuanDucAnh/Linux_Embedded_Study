/*
BT4. Đếm Số Chẵn và Số Lẻ với Threads
Viết một chương trình để thực hiện các bước sau:
    Tạo một mảng ngẫu nhiên chứa 100 số nguyên từ 1 đến 100.
    Tạo hai threads: một thread đếm số chẵn và một thread đếm số lẻ trong mảng.
    Khi hai threads hoàn tất việc đếm, in ra tổng số số chẵn và tổng số số lẻ.
    Sử dụng pthread_join để đảm bảo rằng chương trình chỉ kết thúc khi cả hai threads hoàn thành nhiệm vụ.
Gợi ý: Mỗi thread sẽ xử lý một phần công việc khác nhau, vì vậy không cần mutex trong bài này.

*/


#include <iostream>
#include <pthread.h>

#include <unistd.h>

using namespace std;

#define NUM_THREAD 2
// khai báo biến mutex
pthread_mutex_t mutexVariable = PTHREAD_MUTEX_INITIALIZER; // khai báo mutex tĩnh
// khai báo condition variable
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
/*
Phát tín hiệu condition variable: pthread_cond_signal (&cond);
Đợi tín hiệu Condition variable: pthread_cond_wait (&cond, &mutexVariable);
*/

// Thread kiểm tra xem có bao nhiêu số lẻ
void * CheckOddNumber (void * arg){

    int countOddNumber = 0;
    int * ptrArr = (int *) arg;

    pthread_mutex_lock (&mutexVariable);

    for (int i=0; i<100; i++)
    {
        // cout << "from odd thread: " << *(ptrArr+i) << endl;
        if ((*(ptrArr+i)%2) != 0)
        {
            countOddNumber++;
        }
    }

    cout << "number of odd number in array is: " << countOddNumber << endl;

    pthread_mutex_unlock (&mutexVariable);
    return NULL;
}

// Thread kiểm tra xem có bao nhiêu số chẵn
void * CheckEvenNumber (void * arg){
    
    int countEvenNumber = 0;
    int * ptrArr = (int *) arg;

    pthread_mutex_lock (&mutexVariable);

    // bắt đầu kiểm tra
    for (int i=0; i<100; i++)
    {
        // cout << "from even thread: " << *(ptrArr+i) << endl;
        if ((*(ptrArr+i)%2) == 0)
        {
            countEvenNumber++;
        }
    }
    cout << "number of even number in array is: " << countEvenNumber << endl;

    pthread_mutex_unlock (&mutexVariable);
    return NULL;
}

int main (int argv, char * argc[]){

    // tạo thread ID:
    pthread_t threadID[NUM_THREAD];
    
    // tạo mảng lưu số chẵn lẻ từ 0-100
    int arrNumber [100];
    for (int i=0; i<100; i++) // gán dữ liệu cho mảng
    {
        arrNumber[i] = i;
    }

    // khởi tạo mutex
    // INIT MUTEX
    if (pthread_mutex_init (&mutexVariable, NULL) < 0) // khai báo mutex tĩnh (static nên trường attribute để là null, khi khai báo động (dynamic) thì phải để attribute vào)
    {
        perror ("ERROR when init mutex: ");
    }

    // khởi tạo thread check số lẻ
    int status = pthread_create (&threadID[0], NULL, CheckOddNumber, &arrNumber);
    if (status < 0)
    {
        perror ("error when create thread!");
    }

    // khởi tạo thread check số chẵn
    status = pthread_create (&threadID[1], NULL, CheckEvenNumber, &arrNumber);
    if (status < 0)
    {
        perror ("error when create thread!");
    }

    
    // chờ các thread hoàn thành trước khi kết thúc process
    pthread_join(threadID[0], NULL);  
    pthread_join(threadID[1], NULL);  
    
    return 0;
}
