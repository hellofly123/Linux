#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void)
{
	pid_t pid;
	int i;
	for(i = 0;i<2;i++){
		pid = fork();
		if(pid == 0)
			break;
	}

	if(pid > 0){
		int status;
		int wpid;
		while((wpid = waitpid(-1,&status,WNOHANG)) != -1)
		{
			if(wpid > 0){	//子进程退出校验
				if(WIFEXITED(status))
					printf("wait zombie pid %d child exitcode %d\n",wpid,WEXITSTATUS(status));
				if(WIFSIGNALED(status))
					printf("wait zombie pid %d kill cjhild signal No %d\n",wpid,WTERMSIG(status));
		 	}
		}
	}
	else if(pid == 0){
		if(i == 0){
			printf("child 01 pid %d exiting...\n",getpid());
			sleep(5);
			exit(3);
		}
		else {
			while(1){
				printf("child 02 pid %d running...\n",getpid());
				sleep(1);
			}
		}
	}
	else{
		perror("fork call failed");
		exit(0);
	}

	return 0;
}
