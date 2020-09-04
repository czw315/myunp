#include"unp.h"

ssize_t readn(int fd, void* buf, size_t count){
    ssize_t nleft;
    size_t nread;
    char* ptr;

    nleft=count;
    ptr=buf;
    while(nleft>0){
        if((nread=read(fd, ptr, nleft))<0){
            if(errno==EINTR)
                nread=0;
            else
                return -1;
        }else if(nread==0)
            break;
        nleft-=nread;
        ptr+=nread;
    }
    return count-nleft;
}

ssize_t Readn(int fd, void* buf, size_t count){
    ssize_t n;
    if((n=readn(fd, buf, count))<0)
        err_sys("readn error");
    return n;
}