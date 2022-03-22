#include <process_copy.h>


int process_create(const char* src_file,const char* des_file,int pro_num,int blocksize)
{
	pid_t pid;
	int i;
	int pos;
	char str_pos[10];
	char str_blocksize[10];
	for(i=0;i<pro_num,i++)
	{
		pid = fork();
		if(pid == 0)
			break;
	}
	if(pid > 0)
	{
		printf("process create successly...\n");
		printf("parent process pid %d call zombie_wait...\n",getpid());
		zombie_wait();
	}else if(pid == 0){
		//pos 子进程的读写指针位置 ，itoa
		pos = i * blocksize;
		sprintf(str_pos,"%d",pos);
		sprintf(str_blocksize,"%d",blocksize);
		execl("/home/tqy/0524/process/PROCESS_COPY/mod/COPY","COPY",src_file,des_file,str_pos,str_blocksize,NULL);
	}else{
		str_err("process_create >> fork call failed",-1);
	}

	return 0;
}
