#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
 
void handler(int signal)
{
    printf("\nOuch\n");
}
 
void handler2(int signal)
{
    printf("\nGood bye\n");
}
 
int main(void)
{
    struct sigaction sa_int;
    struct sigaction sa_quit;
    
    sa_int.sa_handler=handler;
    sa_quit.sa_handler=handler2;
 
    sigemptyset(&sa_int.sa_mask);
    sigemptyset(&sa_quit.sa_mask);
 
    sa_int.sa_flags=0;
    sa_quit.sa_flags=0;
 
    sigaction(SIGINT,&sa_int,NULL);
    sigaction(SIGQUIT,&sa_quit,NULL);
 
    while(1)
    {
        printf("running\n");
        sleep(1);
    }
 
}
