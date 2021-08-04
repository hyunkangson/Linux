#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int cnt=0;
void handler(int sig)
{
    printf("%d", cnt);
    cnt++;
    alarm(1);
}
 
int main(void)
{
    struct sigaction sa_alarm;
    sa_alarm.sa_handler = handler;
    sigemptyset(&sa_alarm.sa_mask);
    sa_alarm.sa_flags=0;
    sigaction(SIGALRM, &sa_alarm, NULL);
    alarm(1);
    WHILE(1);
}
