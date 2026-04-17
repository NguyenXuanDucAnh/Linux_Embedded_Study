/*
BT3. Sử Dụng Condition Variables
Viết một chương trình có hai threads: producer và consumer như sau:
    Producer: Tạo ra một số ngẫu nhiên từ 1 đến 10 và lưu vào một biến toàn cục data.
    Consumer: Đợi producer cung cấp dữ liệu, sau đó đọc và in ra dữ liệu đó.
    Sử dụng pthread_cond_wait và pthread_cond_signal để đồng bộ hóa giữa producer và consumer, đảm bảo rằng consumer chỉ đọc dữ liệu khi producer đã cung cấp xong.
    Lặp lại quá trình trên 10 lần và in ra tất cả các giá trị do consumer đọc được.
Gợi ý: Sử dụng pthread_cond_wait để cho consumer đợi cho đến khi có tín hiệu từ producer rằng dữ liệu đã sẵn sàng.

*/


#include <iostream>
#include <pthread.h>

#include <unistd.h>

using namespace std;
int count = 0;

// khai báo biến mutex
pthread_mutex_t mutexVariable = PTHREAD_MUTEX_INITIALIZER;
// khai báo condition variable
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
// global value counter
int counter = 0;
// nếu sử dụng condition variable thì define cái này
// #define USE_CONDITION_VARIABLE

void * Producer (void * arg){

    pthread_mutex_lock (&mutexVariable);
    for (int i=0; i<5; i++)
    {
        cout << "count value: " << counter << endl;
        counter ++;
        sleep(1);
    }

    // có thể thử không dùng Condition variable để check
    #ifdef USE_CONDITION_VARIABLE
        pthread_cond_signal (&cond);
    #endif
    pthread_mutex_unlock (&mutexVariable);
    return NULL;
}

void * Consumer (void * arg){
    return NULL;
}

int main (int argv, char * argc[]){

    // tạo thread ID:
    pthread_t threadProducerID;
    // tạo biến condition variable
    // pthread_cond 

    // khởi tạo mutex
    // INIT MUTEX
    if (pthread_mutex_init (&mutexVariable, NULL) < 0)
    {
        perror ("ERROR when init mutex: ");
    }

    // khởi tạo thread
    int status = pthread_create (&threadProducerID, NULL, Producer, NULL);
    if (status < 0)
    {
        perror ("error when create thread!");
    }

    // CONSUMER
    pthread_mutex_lock (&mutexVariable);
    // có thể thử không dùng Condition variable để check
    #ifdef USE_CONDITION_VARIABLE
        pthread_cond_wait (&cond, &mutexVariable);
    #endif
    cout << "counter in consummer have value: " << counter << endl;
    pthread_mutex_unlock (&mutexVariable);

    pthread_join(threadProducerID, NULL);  
    
    return 0;
}
/*
Mong muốn: chương trình producer sẽ chạy và đếm count lên 5 sau đó consumer (trong main) sẽ in ra biến count sau khi đếm tới 5
Tuy nhiên, nếu không dùng Condition variable mà chỉ dùng Mutex thì Comsumer lại chạy trước khi producer kịp count nên kết quả sẽ là:
    ducanhwsl@admin:~/myDirLinuxEmbedded/Linux_Embedded_Study/04-Thread/03-ConditionVariables$ ./run 
    counter in consummer have value: 0
    count value: 0
    count value: 1
    count value: 2
    count value: 3
    count value: 4
Theo như tìm hiểu, thì hiện tượng này là do khi tạo thread Producer, nó sẽ được đưa vào queue của scheduler với trạng thái Ready chứ chưa chạy nên consumer lại được chạy trước (ta có thể chứng minh bằng cách dùng sleep trước khi vào comsumer thì sẽ thấy Producer hoạt động trước khi Comsumer in ra => logic đúng nhưng hiệu suất không tối ưu). Vì vậy, ta cần dùng biến Condition Variable. 
Về cơ bản, biến này sẽ dùng chung với mutex. Khi chạy ctrinh, Consumer được thực thi trước nên Mutex bị Lock. Do mutex bị lock nên Producer sẽ không thể truy cập để vào trong tăng counter lên được. Nhưng điều kỳ diệu nằm ở hàm pthread_cond_wait, hàm này khi được gọi nó sẽ mở khóa Mutex và chờ đến khi có signal (được phát ra khi một thread nào đó gọi pthread_cond_signal), do pthread_cond_wait đã mở lock mutex nên Producer có thể truy cập vào tài nguyên và tăng biến count lên. Khi đã tăng count lên đủ, producer gọi hàm pthread_cond_signal để báo cho consumer rằng đã thực hiện xong và như vậy consumer mới in ra màn hình. Nếu không dùng biến condition variable mà dùng while và polling điều kiện thì sẽ gây tốn CPU. Còn dùng Condition variable thì thread sẽ được rơi vào trạng thái sleep nên CPU có tài nguyên làm việc khác.
Console khi chạy đúng sẽ là:
    ducanhwsl@admin:~/myDirLinuxEmbedded/Linux_Embedded_Study/04-Thread/03-ConditionVariables$ ./run 
    count value: 0
    count value: 1
    count value: 2
    count value: 3
    count value: 4
    counter in consummer have value: 5
*/

