/*
BT6. Tính Tổng Mảng với Threads và Mutex
    Viết một chương trình tính tổng một mảng lớn gồm 1 triệu số nguyên.
    Chia mảng thành 4 phần bằng nhau.
    Tạo 4 threads, mỗi thread tính tổng một phần của mảng.
    Sử dụng một biến tổng toàn cục và mutex để tổng hợp kết quả từ tất cả các threads.
    In ra kết quả tổng của mảng sau khi các threads hoàn thành.
Gợi ý: Sử dụng pthread_mutex_lock để bảo vệ biến tổng khi các threads cộng kết quả của chúng.

*/


#include <iostream>
#include <pthread.h>

#include <unistd.h>
#include <pthread.h>
#include <stdint.h>

using namespace std;

// số lượng thread cần tạo
#define TOTAL_THREAD 4

// tạo data
#define TOTAL_ELEMENT_ARRAY 1000000
int arrayNumber[TOTAL_ELEMENT_ARRAY]; // tạo mảng 1 triệu số nguyên
uint64_t totalNumber;
uint64_t indexArray[2] = {0, (TOTAL_ELEMENT_ARRAY/4)}; // lưu start index và stop index phục vụ cho các thread khi đọc tại vì phải chia array thành 4 phần bằng nhau. index[0] là start index còn index[1] là stop index

// khai báo biến mutex
pthread_mutex_t mutexVariable = PTHREAD_MUTEX_INITIALIZER; // khai báo mutex tĩnh

// thread tính tổng
void * calcThread (void * arg){

    pthread_mutex_lock (&mutexVariable);

    cout << "index start:" << indexArray[0] << endl;
    cout << "index stop:" << indexArray[1] << endl << endl;

    for (uint64_t ind = indexArray[0]; ind <indexArray[1]; ind++)
    {
        totalNumber += arrayNumber[ind];
    }
    // 1.000.000
    indexArray[0] = indexArray[1];
    indexArray[1] = (TOTAL_ELEMENT_ARRAY/4) + indexArray[1];
    
    pthread_mutex_unlock (&mutexVariable);
    return NULL;
}

int main (int argv, char * argc[]){

    // tạo thread ID:
    pthread_t threadID[TOTAL_THREAD];
    // khởi tạo giá trị cho array
    for (int i =0; i<TOTAL_ELEMENT_ARRAY; i++)
    {
        arrayNumber[i] = i;
    }
    // khởi tạo thread
    for (int i=0; i<TOTAL_THREAD; i++)
    {
        int status = pthread_create (&threadID[i], NULL, calcThread, &arrayNumber);
        if (status < 0)
        {
            perror ("error when create thread:");
        }
    }

    // thread join
    for (int i=0; i<TOTAL_THREAD; i++)
    {
        pthread_join (threadID[i],NULL);
    }
    
    uint64_t sumTemp =0;
    for (int i=0; i<TOTAL_ELEMENT_ARRAY; i++)
    {
        sumTemp += i;
    }
    // tổng mong muốn
    cout << "sumTemp: " << sumTemp << endl;
    // in dữ liệu ra sau khi tính
    cout << "Total Array: " << totalNumber << endl;
   
    return 0;
}
