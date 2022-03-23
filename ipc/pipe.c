#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MSG "hello child "

int main(void)
{
	pid_t pid;
	pid_t wpid;
	int fds[2];//成功传出操作管道的两个描述副

	pid = fork();
	if(pid > 0){
		close(fds[0]);
		printf("parent pid %d send message ..\n",getpid());
		write(fds[1],MSG,strlen(MSG));
		close(fds[1]);

		wpid = wait(NULL);
		printf("parent wait the zimbie %d\n",wpid);
	}
	else if(pid == 0){
		close(fds[1]);
		int len;
		char buffer[1024];
		bzero(buffer,sizeof(buffer));
		len = read(fds[0],buffer,sizeof(buffer));
		printf("child read message = %s \n",buffer);
		close(fds[0]);
		exit(0);
	}
	else{
		perror("fork call failed");
		exit(-1);
	}


	return 0;
}
