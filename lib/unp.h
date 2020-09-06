#pragma once

#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<signal.h>

#include<arpa/inet.h>
#include<netinet/in.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/wait.h>


#define LISTENQ 1024        /* 2nd argument to listen() */
#define MAXLINE 4096        /* max text line length */
#define BUFFSIZE 8192       /* buffer size for reads and writes */

#define	SERV_PORT		 9877			/* TCP and UDP */
#define	SERV_PORT_STR	"9877"			/* TCP and UDP */

#define SA struct sockaddr  

#define	min(a,b)	((a) < (b) ? (a) : (b))
#define	max(a,b)	((a) > (b) ? (a) : (b))

typedef void SigFunc(int);
SigFunc* signal(int signum, SigFunc*);
SigFunc* Signal(int signum, SigFunc*);

ssize_t writen(int fd, const void* buf, size_t count);
void Writen(int fd, const void* buf, size_t count);
ssize_t readn(int fd, void* buf, size_t count);
ssize_t Readn(int fd, void* buf, size_t count);
ssize_t	 readline(int, void *, size_t);
ssize_t	 Readline(int, void *, size_t);

//wrapper: bind, listen, write, read, accept, connect......
ssize_t Read(int fd, void *buf, size_t count);
void Write(int fd, const void *buf, size_t count);
void Bind(int fd, const struct sockaddr *sa, socklen_t salen);
void Connect(int fd, const struct sockaddr *sa, socklen_t salen);
int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
void Listen(int fd, int backlog);
int Socket(int family, int type, int protocol);
void Close(int fd);
pid_t Fork(void);
void Inet_pton(int family, const char *strptr, void *addrptr);
char *Fgets(char *s, int size, FILE *stream);
void Fputs(const char *s, FILE *stream);

void	 err_dump(const char *, ...);
void	 err_msg(const char *, ...);
void	 err_quit(const char *, ...);
void	 err_ret(const char *, ...);
void	 err_sys(const char *, ...);

void str_echo(int fd);
void str_cli(FILE* fp, int sockfd);