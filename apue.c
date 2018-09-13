#if 0
#include <dirnet.h>
#endif
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <stdlib.h>

#if 0
int ls(char *dirname)
{
	DIR *dp;
	struct dirnet *dirp;

	if ((dp = opendir()) == NULL)
		exit(1);
	while ((dirp = readdir(dp)) != NULL)
		printf("%s\n", dirp->name);

	closedir(dp);
	exit(0);
}
#endif


int copy(void)
{
	/* 从标准输入读入数据，输出到标准输出 */
	#define BUFFSIZE 4096
	int n;
	char buff[BUFFSIZE];

	while ((n = read(0, buff, BUFFSIZE)) > 0)
		if ((write(1, buff, n)) != n)
			return 1;

	return 0;
}


int copy2(void)
{
	/* 带IO缓冲的copy */
	int c;
	while ((c = getc(stdin)) != EOF)
		if ((putc(c, stdout)) == EOF)
			return 1;

	return 0;
}


int get_pid(void)
{
	/* 获取当前进程id */
	printf("process ID is %ld\n", (long)getpid());
	return 0;
}


int err(void)
{
	/* 不同的errno对应不同的错误信息 */
	int i;
	char *err;
	for (i=0; i<48; i++)
	{
		err = (char *)strerror(i);
		printf("%d: %s\n", i, err);
	}
	return 0;
}


// int user_identify(void)
// {
// 	printf("uid = %d, gid = %d\n", get_uid(), get_gid());
// 	return 0;
// }


int main(void)
{
	extern int errno;
	int fd;
	if( (fd = open("test.txt", 'w')) == -1 ) {
        printf("Open failure, errno is %d :%s \n", errno,strerror(errno));
    } else {
        printf("Open successfully!\n");
    }

    err();
	getc(stdin);
}