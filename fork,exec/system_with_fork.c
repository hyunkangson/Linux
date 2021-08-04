#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
 
int my_system(char *command)
{
    if(fork()==0)
    {
        execl("/bin/sh", "sh","-c",command,(char*)NULL); 
        exit(20);
    }
    
    else
    {
        int exitstatus;
    
        wait(&exitstatus);
        if (WIFEXITED(exitstatus)) return exitstatus;
    }
}
 
int main()
{
    int status;
    status=my_system("ls -l | wc");
    printf("exit code %d\n", WEXITSTATUS(status));
    
    int status2 = system("ls -l | wc");
    printf("exit code %d\n", WEXITSTATUS(status2));
    
    return 0;
}
