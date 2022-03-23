#include <process_copy.h>


void zombie_wait(void)
{
	pid_t wpid;

	while((wpid = waitpid(-1,NULL,WNOHANG)) != -1 )
	{
		if(wpid > 0)
			printf("Parent process %d wait the zombie process successly...\n",getpid());
		else
			continue;	
	}
}
