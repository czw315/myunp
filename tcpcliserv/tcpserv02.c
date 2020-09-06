#include"unp.h"

void sig_chld(int);

int main(){
    int sockfd, connfd;
    pid_t childpid;
    struct sockaddr_in servaddr, connaddr;
    socklen_t connaddr_len;

    sockfd=Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(SERV_PORT);
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

    Bind(sockfd, (SA*)&servaddr, sizeof(servaddr));
    Listen(sockfd, LISTENQ);
    Signal(SIGCHLD, sig_chld);
    for(;;){
        connaddr_len=sizeof(connaddr);
        connfd=Accept(sockfd, (SA*)&connaddr, &connaddr_len);
        if((childpid=Fork())==0){
            Close(sockfd);
            str_echo(connfd);
            Close(connfd);
            exit(0);
        }
        Close(connfd);
    }
    return 0;
}