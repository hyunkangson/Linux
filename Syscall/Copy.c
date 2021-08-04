// file copy
 
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
 
#define BUFF_SZ 100
int main(int argc, char *argv[])
{
    int fd;
    if (argc !=3) // command라인에서 받아들인 파라미터 수가 3미만
    {
        printf("need more argument\n");
        exit(0);
    }
    int fd_source = open(argv[1], O_RDONLY);
    int fd_target = open(argv[2], O_WRONLY|O_CREAT, 0666);
 
 
    fd = open(argv[1], O_RDONLY); // 파일 이름을 읽기 버전 
  
    if (fd_source == -1 || fd_target == -1)
    {
        perror("open");
        exit(1);
    }
    else
    {
        char buffer[BUFF_SZ];
        int nb;
        while(nb = read(fd_source, buffer, BUFF_SZ))
        {
            write(fd_target, buffer, nb);
        }
        close(fd_source);
        close(fd_target);
    }
    
    return 0;
}
