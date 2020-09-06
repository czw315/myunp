#include"unp.h"

int main(int argc, char** argv){
    int sockfd;
    struct sockaddr_in sockaddr;

    if(argc!=2)
        err_quit("Usage: a.out <IP address>");
    
    sockfd=Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&sockaddr, sizeof(sockaddr));
    sockaddr.sin_family=AF_INET;
    sockaddr.sin_port=htons(SERV_PORT);
    Inet_pton(AF_INET, argv[1], &sockaddr.sin_addr);

    Connect(sockfd, (SA*)&sockaddr, sizeof(sockaddr));
    str_cli(stdin, sockfd);

    return 0;
}