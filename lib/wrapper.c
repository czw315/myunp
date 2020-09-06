#include"unp.h"

ssize_t Read(int fd, void *buf, size_t count){
    ssize_t n;
    if((n=read(fd, buf, count))==-1)
        err_sys("read error");
    return n;
}

void Write(int fd, const void *buf, size_t count){
    if(write(fd, buf, count)!=count)
        err_sys("write error");
}

int
Socket(int family, int type, int protocol)
{
	int		n;

	if ( (n = socket(family, type, protocol)) < 0)
		err_sys("socket error");
	return(n);
}

void Close(int fd){
    if(close(fd)==-1)
        err_sys("close error");
}

void
Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if (bind(fd, sa, salen) < 0)
		err_sys("bind error");
}

void
Connect(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if (connect(fd, sa, salen) < 0)
		err_sys("connect error");
}

int
Accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
	int		n;

again:
	if ( (n = accept(fd, sa, salenptr)) < 0) {
#ifdef	EPROTO
		if (errno == EPROTO || errno == ECONNABORTED)
#else
		if (errno == ECONNABORTED)
#endif
			goto again;
		else
			err_sys("accept error");
	}
	return(n);
}

void
Listen(int fd, int backlog)
{
	char	*ptr;

		/*4can override 2nd argument with environment variable */
	if ( (ptr = getenv("LISTENQ")) != NULL)
		backlog = atoi(ptr);

	if (listen(fd, backlog) < 0)
		err_sys("listen error");
}

pid_t Fork(void){
	pid_t pid;
	if((pid=fork())==-1)
		err_sys("fork error");
	return pid;
}

void Inet_pton(int family, const char *strptr, void *addrptr)
{
	int		n;

	if ( (n = inet_pton(family, strptr, addrptr)) < 0)
		err_sys("inet_pton error for %s", strptr);	/* errno set */
	else if (n == 0)
		err_quit("inet_pton error for %s", strptr);	/* errno not set */

	/* nothing to return */
}

char *Fgets(char *s, int size, FILE *stream){
	char* p;
	if((p=fgets(s, size, stream))==NULL&&ferror(stream))
		err_sys("fgets error");
	return p;
}

void Fputs(const char *s, FILE *stream){
	if(fputs(s, stream)==EOF)
		err_sys("fputs error");
}
