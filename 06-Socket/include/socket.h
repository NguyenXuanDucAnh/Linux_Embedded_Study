#ifndef __SOCKET_H__
#define __SOCKET_H__

#include <iostream>
#include <string.h>

#include <sys/socket.h> // => for socket
#include <netinet/in.h> // => for struct sockaddr_in
#include <unistd.h> // => for read/write
#include <arpa/inet.h> // for inet_addr

#define BACKLOG_NUM 10

class serverSocket{
    
    public:
    /*constructor*/
    serverSocket (int port){
        /*Step 1: create socket file desciptor*/
        // int socket(int domain, int type, int protocol);
        fdServer = socket(AF_INET, SOCK_STREAM, 0);
        if (fdServer < 0)
        {
            perror ("error when create socket");
        }
        /* Step 2: bind action: When a socket is created with socket(2), it exists in a name space
       (address family) but has no address assigned to it.  bind()
       assigns the address specified by addr to the socket referred to by
       the file descriptor sockfd
        int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen); */
    
        // when use bind, we will use "struct sockaddr" to define family, port and addr for server. But, in fact, we will use "struct sockaddr_in" (for IPv4) or "struct sockaddr_in6" (for IPv6) then Casting to "struct sockaddr"
        // declare struct sockaddr_in to define attribute of socket (ip, port)
        //  struct sockaddr_in {
        //        sa_family_t     sin_family;     /* AF_INET */
        //        in_port_t       sin_port;       /* Port number */
        //        struct in_addr  sin_addr;       /* IPv4 address */
        //    };
        
        struct sockaddr_in serverAdrr; // using ipv4, if you want to use IPV6, let get struct sockaddr_in6
        serverAdrr.sin_addr.s_addr = INADDR_ANY; // auto get Ip of device, not hardcode
        serverAdrr.sin_family = AF_INET;
        serverAdrr.sin_port = htons(port);

        bindRet = bind(fdServer, (struct sockaddr *)&serverAdrr, sizeof (serverAdrr));
        if (bindRet < 0)
        {
            perror ("error when bind socket");
        }

        /* Step 3: Listen*/
        // int listen(int sockfd, int backlog);
        int listenRet = listen(fdServer, BACKLOG_NUM);
        if (listenRet < 0)
        {
            perror ("error when listen socket");
        }

    }

    /*Destructor*/
    ~ serverSocket (){
        // 7. Đóng socket
        close(fdClient);
        close(fdServer);
        std::cout << "Server Socket is destructor!" << std::endl;
    }
    
    public:
        /**
         * @brief server accept connection
         * 
         * @return struct sockaddr_in : struct contain port client connect to, and addr of client
         */
        struct sockaddr_in serverAccept (){
            /* Step 4: Accept*/
            // int accept(int sockfd, struct sockaddr *_Nullable restrict addr, socklen_t *_Nullable restrict addrlen);

            struct sockaddr_in peerAddr;
            socklen_t socketLen = sizeof (peerAddr);
            fdClient = accept(fdServer, (struct sockaddr *)&peerAddr, &socketLen);
            if (fdClient < 0)
            {
                perror ("error when accept socket");
            }  

            std::cout << "Client addr:" << inet_ntoa(peerAddr.sin_addr) << std::endl;

            return peerAddr;
        }

        /**
         * @brief read requet from client through socket. If client not send request, server will go to block state
         * 
         * @param fdSocket : file descriptor socket
         * @param requestRet : String request return
         * @return int : Num bytes read from client request
         */
        int waitRequestFromClient (int fdSocket, char * requestRet){
            char buffer[1024] = {0};
            // 5. Nhận dữ liệu
            int bytes = read(fdClient, buffer, 1024);
            std::cout << "Byte lenght read:" << bytes << std::endl;
            if (bytes == 0){
                printf ("Client disconnected!\n");
                memset (requestRet, '\0', 1024);
                return bytes;
            }
            else if (bytes > 0) {
                printf("Server Received: %s | byte read: %d\n", buffer, bytes);
                memcpy (requestRet, buffer, bytes);
                requestRet[bytes] = '\0';
                return bytes;
            }

            return -1;
        }

        /**
         * @brief read requet from client through socket. If client not send request, server will go to block state
         * 
         * @param fdSocket : file descriptor socket
         * @param requestRet : String request return
         * @return int : Num bytes read from client request
         */
        int waitRequestFromClient (int fdSocket, char * requestRet, int lenghtRead){
            char buffer[lenghtRead] = {0};
            // 5. Nhận dữ liệu
            int bytes = read(fdClient, buffer, lenghtRead);
            if (bytes > 0) {
                printf("Server Received: %s\n", buffer);
                memcpy (buffer, requestRet, lenghtRead);
                requestRet[bytes] = '\0';
                return bytes;
            }
            return -1;
        }

        /**
         * @brief Send msg to client
         * 
         * @param msg 
         * @return ssize_t: size message server send
         */
        ssize_t sendMsgToClient (const char *msg){
            // 6. Gửi phản hồi
            return write(fdClient, msg, strlen(msg));
        }
    private:
        int fdServer = -1;
        int bindRet = -1;
        int fdClient = -1;
    protected:
};

#endif