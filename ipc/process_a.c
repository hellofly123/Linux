#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>

#define msg "test message...\n"

//write
int main(void)
{
	int fd;
	mkfifo("fifo",0664);  //使用函数创建又名管道文件
	fd = open("fifo",O_WRONLY);
	printf("block...\n");

	write(fd,msg,strlen(msg));
	printf("process a pid %d send message successfully...\n",getpid());
	
	close(fd);

	return 0;
}
