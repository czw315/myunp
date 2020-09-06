#include"unp.h"

SigFunc* signal(int signum, SigFunc* sigfunc){
    struct sigaction act, oact;
    act.sa_handler=sigfunc;
    sigemptyset(&act.sa_mask);
    act.sa_flags=0;
    if(signum==SIGALRM){
#ifdef SA_INTERRUPT
        act.sa_flags |= SA_INTERRUPT;
#endif
    }else{
#ifdef SA_RESTART
        act.sa_flags |= SA_RESTART;
#endif
    }
    
    if(sigaction(signum, &act, &oact)<0)
        return SIG_ERR;
    return oact.sa_handler;
}

SigFunc* Signal(int signo, SigFunc* func)	/* for our signal() function */
{
	SigFunc* sigfunc;

	if ( (sigfunc = signal(signo, func)) == SIG_ERR)
		err_sys("signal error");
	return(sigfunc);
}