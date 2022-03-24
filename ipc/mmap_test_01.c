#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>	//mmap头文件
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*测试共享影射，将影射文件的内容影射到内存中，对内存进行修改，看是否可以同步到文件中*/


int main(void)

{
	//打开影射文件
	int mfd = open("mmap_file",O_RDWR);
	//获取文件大小
	int fsize = lseek(mfd,0,SEEK_END);

	//内存共享影射
	//int *ptr = NULL;
	char* ptr = NULL;
	if((ptr = mmap(NULL,fsize,PROT_READ | PROT_WRITE,MAP_SHARED,mfd,0)) == MAP_FAILED)
	{
		perror("mmap call failed");
		exit(0);
	}
	close(mfd);//关闭映射文件

	//修改影射内容，将内存中的前4个字节改为1234
	//ptr[0] = 0x34333231; //1234四个字符的16进制表示 
	ptr[0] = '8';//以单个字符形式修改 定义ptr时要定义为char*类型
	ptr[1] = '8';

	//使用完毕释放影射内存
	munmap(ptr,fsize);
	return 0;
}
