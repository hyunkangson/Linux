#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
 
struct two_double{
        double a;
        double b;
}data;
 
void signal_handler(int sig){
        printf("%f, %f\n",data.a,data.b);
        alarm(1);
}
 
int main(void){
        struct sigaction sa;
        static struct two_double zeros={0.0,0.0}, ones={1.0,1.0};
        sigset_t block_set, prev_set;
        sigemptyset(&block_set);
        sigaddset(&block_set,SIGALRM);
 
        sigemptyset(&sa.sa_mask);
        sa.sa_flags=0;
        sa.sa_handler = signal_handler;
 
        if(sigaction(SIGALRM,&sa,NULL)==-1){
                perror("sigaction");
                exit(0);
        }
 
        sigprocmask(SIG_BLOCK,&block_set,&prev_set);
        data = zeros;
        alarm(1);
 
        while(1){
                sigprocmask(SIG_SETMASK,&prev_set,NULL);
                sigprocmask(SIG_BLOCK,&block_set,&prev_set);
                data = ones;
                sigprocmask(SIG_SETMASK,&prev_set,NULL);
                sigprocmask(SIG_BLOCK,&block_set,&prev_set);
                data = zeros;
        }
        return 0;
}
 
