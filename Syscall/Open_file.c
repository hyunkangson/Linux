#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
 
int main(int argc, char *argv[])
{
    int fd;
    if (argc !=2) // command라인에서 받아들인 파라미터 수가 1
    {
        printf("open need filename\n");
        exit(0);
    }
    printf("argv[0]:%s\n",argv[0]); //명령어 (1)
    printf("argv[1]:%s\n",argv[1]); //명령어 뒤 파라미터 (2)
 
    fd = open(argv[1], O_RDONLY); // 파일 이름을 읽기 버전 
    if(fd == -1) //error
    {
        perror("my open");
        exit(0);
    }
    else
    {
        printf("file %s exists\n", argv[1]); // 존재하면 해당 파일의 이름 출력
    }
    
    return 0;
}
