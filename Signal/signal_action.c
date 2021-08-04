#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
 
void handler(int signal)
{
    printf("\nOuch\n");
}
 
int main(void)
{
    struct sigaction sa_int;
 
    sa_int.sa_handler=handler;
    sigemptyset(&sa_int.sa_mask); // 초기화 
    sa_int.sa_flags=0; //default=0;
    sigaction(SIGINT, &sa_int, NULL);
 
    while(1)
    {
        printf("running\n");
        sleep(1);
    }
}
