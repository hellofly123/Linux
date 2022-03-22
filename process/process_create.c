#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	//Parent Start
	pid_t pid;
	pid = fork(); //create 

	//
	if(pid > 0){
		printf("Parent Procrss...\n");
	}else if(pid == 0){
		//child Start
		printf("child procrss...\n");
		while(1)
				sleep(1);
		//child End
	}else{
			perror("fork call failed\n");
			exit(-1);
	}

	printf("Parent other job...\n");

	while(1)
		sleep(1);


	return 0;
	//Parent End
}
