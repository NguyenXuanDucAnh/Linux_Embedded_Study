#include <iostream>
#include <fstream>
#include <pthread.h>
#include <string.h>
#include <sys/socket.h> // => for socket
#include <netinet/in.h> // => for struct sockaddr_in
#include <unistd.h> // => for read/write
#include <arpa/inet.h> // for inet_addr
#include "include/help.h"

#define NUM_THREAD 2
std::string listThreadName[NUM_THREAD+1] = {"SERVER_THREAD", "CLIENT_THREAD"};
enum {
    SERVER_THREAD =0,
    CLIENT_THREAD
    //OTHER THREAD
};

#define BACKLOG_NUM 10
void serverListener (){
    std::cout << "I'm server" << std::endl;
    /*Step 1: create socket file desciptor*/
    // int socket(int domain, int type, int protocol);
    int fd_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (fd_socket < 0)
    {
        perror ("error when create socket");
    }
    /* Step 2: bind action: When a socket is created with socket(2), it exists in a name space
       (address family) but has no address assigned to it.  bind()
       assigns the address specified by addr to the socket referred to by
       the file descriptor sockfd*/
    // int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    
    // declare struct sockaddr_in to define attribute of socket (ip, port)
    //  struct sockaddr_in {
    //        sa_family_t     sin_family;     /* AF_INET */
    //        in_port_t       sin_port;       /* Port number */
    //        struct in_addr  sin_addr;       /* IPv4 address */
    //    };
    
    struct sockaddr_in serverAdrr; // using ipv4, if you want to use IPV6, let get struct sockaddr_in6
    serverAdrr.sin_addr.s_addr = INADDR_ANY; // auto get Ip of device, not hardcode
    serverAdrr.sin_family = AF_INET;
    serverAdrr.sin_port = htons(8080);

    int bindRet = bind(fd_socket, (struct sockaddr *)&serverAdrr, sizeof (serverAdrr));
    if (bindRet < 0)
    {
        perror ("error when bind socket");
    }
    /* Step 3: Listen*/
    // int listen(int sockfd, int backlog);
    int listenRet = listen(fd_socket, BACKLOG_NUM);
    if (bindRet < 0)
    {
        perror ("error when listen socket");
    }
    /* Step 4: Accept*/
    // int accept(int sockfd, struct sockaddr *_Nullable restrict addr, socklen_t *_Nullable restrict addrlen);

    struct sockaddr_in peerAddr;
    socklen_t socketLen = sizeof (peerAddr);
    int fd_accepted = accept(fd_socket, (struct sockaddr *)&peerAddr, &socketLen);
    if (fd_accepted < 0)
    {
        perror ("error when accept socket");
    }  

    char buffer[1024] = {0};
    while (1)
    {
        // 5. Nhận dữ liệu
        int bytes = read(fd_accepted, buffer, 1024);
        if (bytes > 0) {
            printf("Server Received: %s\n", buffer);
        }

        // 6. Gửi phản hồi
        const char *msg = "Hello from server!";
        write(fd_accepted, msg, strlen(msg));
    }

    // 7. Đóng socket
    close(fd_accepted);
    close(fd_socket);
}

void clientListener (){
    sleep (5);
    std::cout << "I'm client" << std::endl;

    /*Step 1: create socket file desciptor*/
    // int socket(int domain, int type, int protocol);
    int fd_socket = socket(AF_INET, SOCK_STREAM, 0);

    /* Step 2: connect*/
    // int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    // struct sockaddr_in {
    //        sa_family_t     sin_family;     /* AF_INET */
    //        in_port_t       sin_port;       /* Port number */
    //        struct in_addr  sin_addr;       /* IPv4 address */
    //    };
    struct sockaddr_in serverAddr;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_family = AF_INET;

    int connectRet = connect(fd_socket, (struct sockaddr *)&serverAddr, sizeof (serverAddr));
    if (connectRet<0)
    {
        perror ("error when connect socket");
    }

    const char *msg = "Hello from Client!";
    write(fd_socket, msg, strlen(msg));

    char buffer[1024] = {0};
    int bytes = read(fd_socket, buffer, 1024);
    if (bytes > 0) {
        printf("Client Received: %s\n", buffer);
    }

    close (fd_socket);
}

void (*functionPtr)(); // funciton pointer
void * threadHandler (void * arg){
    int *index = (int*)(arg);

    std::cout << "index is: " << *index << std::endl;
    switch (*index){
        case SERVER_THREAD:
            functionPtr = &serverListener;
            
            break;
        case CLIENT_THREAD:
            functionPtr = &clientListener;
            break;
    }
    functionPtr();
    return nullptr;
}


int main (int argv, char * argc[]){

    std::cout << "starting!!!" << std::endl;

    pthread_t threadID [NUM_THREAD];
    int indexList[NUM_THREAD];
    for (int index = 0; index < NUM_THREAD; index++){
        std::cout << "index in main: " << index << std::endl;
        indexList[index] = index;
        int status = pthread_create (&threadID[index], NULL, threadHandler, &indexList[index]);
        if ( status != 0)
        {
            std::cerr << "Error creating thread " << listThreadName[index]
                  << strerror(status)  // lấy mã lỗi trả về và in ra
                  << std::endl;
        }
        
    }
    
    // std::cout << MENU_GUIDE << std::endl;

    pthread_join (threadID[SERVER_THREAD], NULL);
    pthread_join (threadID[CLIENT_THREAD], NULL);
    return 1;

}