#include <process_copy.h>

int check_pram(int arg_num,const char* src_file,int pro_num)
{
	if(arg_num < 3){
		printf("Param error:missing pram...\n");
		exit(-1);
	}
	
	//文件测试函数，可以测试文件存在与否，文件权限
	if((access(src_file,F_OK)) != 0)
	{
		printf("param error: file does not exist...\n");
		exit(-1);
	}

	if(pro_num <= 0 || pro_num > 100)
	{
		printf("param error: the number of process can't be less than 0 and greater than 100...\n");
		exit(-1);
	}

	return 0;
}
