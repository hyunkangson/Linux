#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
 
void *snow (void *data) // 인자로써 void 포인터로를 받아오고 void 포인터를 리턴
{
    printf("Let it snow %s\n", (char*) data);  // 보이드 포인터를 타입 캐스팅 하여 내부적으로 사용
    pthread_exit(NULL);
}
 
int main(void)
{
    pthread_t mythread; 
    char *data = "Let it snow.";
    int result;
 
    result = pthread_create(&mythread, NULL, snow, data); 
    // pthread_t타입의 핸들 사용, attribure:NULL, 새로 생성된 스레드가 사용할 함수, 함수에 넘겨줄 데이터 
    // pthread_create라는 메인 스레드가 수행되는 동안 snow를 수행하는 스레드를 만들어 동시에 수행한다.
   
    if (result) exit(1);
    pthread_exit(NULL);
}
