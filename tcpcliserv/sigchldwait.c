#include"unp.h"

void sig_chld(int signum){
    pid_t pid;
    int stat;
    pid=wait(&stat);
    printf("child %d terminated\n", pid);
    return;
}