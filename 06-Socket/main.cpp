#include <iostream>
#include <fstream>
#include <pthread.h>
#include <string.h>
#include <sys/socket.h> // => for socket
#include <netinet/in.h> // => for struct sockaddr_in
#include <unistd.h> // => for read/write
#include <arpa/inet.h> // for inet_addr
#include "include/help.h"
#include "include/socket.h"

using namespace std;

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
    serverSocket server(8080);

    server.serverAccept();

    while (1){
        cout << "Waiting request form client" << endl;
        char requestFromClient[2048];
        if (server.waitRequestFromClient(1, requestFromClient) > 0){
            cout << "request from client:" << requestFromClient << endl;
            server.sendMsgToClient ("ducanhdeptrai1234 server 67890");
        }
        sleep (2);
    }
}

void clientListener (){
    sleep (2);
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