#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
 
 
int main()
{
    if(fork()==0)
    {
        printf("child %d\n", getpid());
        sleep(20);
    }
    else
    {
        printf("parent %d\n", getppid());
        sleep(20);
    }
}
 
