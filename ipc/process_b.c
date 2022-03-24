#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>


//read
int main(void)
{
	int fd;
	int len;
	char buffer[1024];
	bzero(buffer,sizeof(buffer));
	fd = open("fifo",O_RDONLY);

	len = read(fd,buffer,sizeof(buffer));
	printf("process b  pid %d recv message = %s\n",getpid(),buffer);
	
	close(fd);

	printf("delete fifo..\n");

	unlink("fifo"); //销毁管道 参数为文件名

	return 0;
}
