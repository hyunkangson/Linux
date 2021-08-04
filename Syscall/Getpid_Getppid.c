//pid, ppid받아오기
 
#include<sys/types.h>
#include<unistd.h>
#include <stdio.h>
 
int main()
{
    pid_t mypid;
    pid_t myppid;
 
    mypid = getpid(); // own pid
    myppid = getppid(); // parent pid
 
    printf("pid is %ld\n", (long)mypid);
    printf("ppid is %ld\n", (long)myppid);
}
