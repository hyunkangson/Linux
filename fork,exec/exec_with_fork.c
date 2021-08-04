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
        execl("/bin/ls", "ls", "-l","-F",(char*)NULL);
        exit(20);
    }
    else
    {
        int exitstatus;
        printf("parent %d\n", getppid());
        wait(&exitstatus);
        if(WIFEXITED(exitstatus)) // 정상 종료 확인, 정상 종료 시 0이 아닌 값
        {
            printf("exit code %d \n", WEXITSTATUS(exitstatus)); //exit의 인자 값 혹은 return값
        }
    }
}
