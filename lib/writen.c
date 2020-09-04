#include"unp.h"

//write count bytes to fd
ssize_t writen(int fd, const void* buf, size_t count){
    size_t nleft;
    ssize_t nwritten;
    const char* ptr;

    nleft=count;
    ptr=buf;

    while(nleft>0){
        if((nwritten=write(fd, ptr, nleft))<=0){
            if(nwritten<0&&errno==EINTR)
                nwritten=0;
            else 
                return -1;
        }
        ptr+=nwritten;
        nleft-=nwritten;
    }
    return count;
}

void Writen(int fd, const void* buf, size_t count){
    if(writen(fd, buf, count)!=count)
        err_sys("writen error");
}