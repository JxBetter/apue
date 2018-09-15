#if 0
#include <dirnet.h>
#endif
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

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


// int err(void)
// {
// 	/* 不同的errno对应不同的错误信息 */
// 	int i;
// 	char *err;
// 	for (i=0; i<48; i++)
// 	{
// 		err = (char *)strerror(i);
// 		printf("%d: %s\n", i, err);
// 	}
// 	return 0;
// }


// int user_identify(void)
// {
// 	printf("uid = %d, gid = %d\n", get_uid(), get_gid());
// 	return 0;
// }
// 

int toStringHex(unsigned char c)
{
	/* 
	 * 输入0-255数值，输出十六进制字符串
	 */
	if ((c >> 4) < 0x0a)
	{
		printf("0x%c\n", ((c >> 4) + '0'));
	}
	else
		printf("%c\n", ((c >> 4) + 'A' - 0x0a));

	if ((c & 0x0f) < 0x0a)
	{
		printf("0x%c\n", ((c & 0x0f) + '0'));
	}
	else
		printf("%c\n", ((c & 0x0f) + 'A' - 0x0a));

	return 0;
}


int print_word(unsigned int c)
{
	toStringHex((unsigned char) (c >> 8));
	toStringHex((unsigned char) (c & 0xff));
}


char *decToBin(unsigned int val)
{
	/*
	 * 输入十进制数，输出二进制字符串
	 */
	 int i, x, y, len;
	 char t[32] = {0}, r[32] = {0};
	 char *res = (char *)malloc(32 * sizeof(char));
	 i = 0;
	 x = val;
	 y = val;

	 while (x != 0)
	 {
	 	t[i++] = x % 2 + '0';
	 	x = (int)(x / 2);
	 }
	len = strlen(t);
	for (i=len-1; i>=0; i--)
		r[len-1-i] = t[i];
	 strcpy(res, r);
	 return res;
}


char *decToHex(unsigned int val)
{
	/*
	 * 输入十进制数，输出十六进制字符串
	 */
	 int i, x, y, len;
	 char t[32] = {0}, r[32] = {0};
	 char *res = (char *)malloc(32 * sizeof(char));
	 i = 0;
	 x = val;
	 y = val;

	 while (x != 0)
	 {
	 	if (x % 16 <10)
	 		t[i++] = x % 16 + '0';
	 	else
	 		t[i++] = x % 16 + 'a' - 10;
	 	x = (int)(x / 16);
	 }
	len = strlen(t);
	for (i=len-1; i>=0; i--)
		r[len-1-i] = t[i];
	 strcpy(res, r);
	 return res;
}

 
int main(void)
{
	char * str;
    str = decToHex(5678);
    printf("str = %s\n", str);
	getc(stdin);
}