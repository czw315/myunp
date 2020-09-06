#include"unp.h"

void str_echo(int fd){
    char buf[MAXLINE];
    ssize_t n;
again:
    while((n=read(fd, buf, MAXLINE))>0){
        Writen(fd, buf, n);
    }
    if(n<0&&errno==EINTR)
        goto again;
    else if(n<0)
        err_sys("read error");
}