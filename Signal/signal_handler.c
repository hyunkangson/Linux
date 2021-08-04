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
    signal(SIGINT, handler);
    while(1)
    {
        printf("running\n");
        sleep(1);
    }
}
