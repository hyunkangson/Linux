#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
 
int x=1;
 
void *func (void *data) 
{
    x = x+1;
    pthread_exit((void*)42); // 명시적으로 종료하고 42 리턴
}
 
int main(void)
{
    pthread_t mythread; 
    int result;
    int i;
 
    result = pthread_create(&mythread, NULL, func, NULL);
    if(result) exit(1);
 
    pthread_join(mythread, (void**)&i); // mythread 종료시까지 대기
    printf("%d\n", i);
}
