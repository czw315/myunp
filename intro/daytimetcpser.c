#include"unp.h"
#include<time.h>

int main(){
    int servfd, connfd;
    char buf[MAXLINE];
    struct sockaddr_in servaddr;
    time_t ticks;

    if((servfd=socket(AF_INET, SOCK_STREAM, 0))<0)
        err_sys("socket error");
    
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(13);
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

    Bind(servfd, (SA*)&servaddr, sizeof(servaddr));
    Listen(servfd, LISTENQ);

    for(;;){
        connfd=Accept(servfd, (SA*)NULL, NULL);
        ticks=time(NULL);
        snprintf(buf, MAXLINE, "%.24s\r\n", ctime(&ticks));
        Write(connfd, buf, strlen(buf));
        Close(connfd);
    }
    return 0;
}