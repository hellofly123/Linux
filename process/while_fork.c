#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(void)
{
	pid_t pid;
	int i;
	for(i=0;i<7;i++)
	{
		pid = fork();
		if(pid == 0)
		{
			break;
		}
	}

	if(pid > 0){
		printf("Parent pid %d\n",getpid());
	}
	else if(pid == 0)
	{	
		if(i == 0)
		{
			printf("fire\n");
		}
		else if(i == 1)
		{
			printf("water\n");
		}
		else if(i == 2)
		{
			printf("yin sheng\n");
		}
		else if(i == 3)
		{
			printf("dao qiang bu ru\n");
		}
		else
		{
			printf("other brother\n");
		}
		while(1)
			sleep(1);
	}
	else
	{
		perror("fork call failed");
		exit(-1);
	}

	return 0;
}
