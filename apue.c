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

 
int enum_test(void)
{
	enum en { RED=66, BLUE, GREEN };
	enum en e1;
	e1 = BLUE;
	printf("%d\n", e1);
}


int struct_test(void)
{
	typedef struct person
	{
		int age;
	}person, *p_person;

	person p;
	p.age = 33;

	person person_array[64];
	person_array[0] = p;
	person_array[0].age = 66;
	printf("%d\n", person_array[0].age);
}


struct test
{
	int age;
};

int test_fun(struct test *st)
{
	st->age = 33;
	printf("in test_fun age = %d\n", st->age);
	return 0;
}



int copy_n(char dst[], char src[], int n)
{
	/* 把一个字符串从src复制到dst中去，和strncpy功能相同 */
	int i = 0, j, k;
	char temp;
	for (i=0; i<n; i++)
	{
		if (src[i] == '\0')
		{
			printf("%d\n", n-i);
			k = n-i;
			for (j=0; j<k; j++)
			{
				dst[i] = '\0';
				printf("%d: %d\n", i, dst[i]);
				i++;
			}
			goto end;
		}
		temp = src[i];
		dst[i] = temp;
	}

end:
	printf("dst = %s\n", dst);
	printf("%d\n", strlen(dst));
	return 0;
}


int deblank(char *str)
{
	/* 从一个字符串中去除多余的空格，如果一个地方有一个或多个空格，则替换成一个空格 */
	int i, j, len, flag;
	j = 0;
	flag = 0;
	len = strlen(str);
	printf("%d\n", len);
	char res[len];
	memset(res, 0, len);
	for (i=0; i<len; i++)
	{
		if ((flag == 1) && (str[i] != ' '))
		{
			flag = 0;
		}

		if (flag == 0)
		{
			res[j++] = str[i];
			printf("str[%d] = %c, flag = %d\n", i, str[i], flag);
			printf("res[%d] = %c\n", i, res[i]);
		}

		if (str[i] == ' ')
		{
			flag = 1;
		}
	}
	printf("%s, len = %d\n", res, strlen(res));
	return 0;
}


int de_allblank(char *str)
{
	/* 从一个字符串中去除所有的空格 */
	int i, j, len;
	j = 0;
	len = strlen(str);
	printf("%d\n", len);
	char res[len];
	memset(res, 0, len);
	for (i=0; i<len; i++)
	{
		if (str[i] != ' ') //不是空格
		{
			res[j++] = str[i];
			printf("str[%d] = %c\n", i, str[i]);
			printf("res[%d] = %c\n", i, res[i]);
		}
		else //是空格，则跳过
			continue;

	}
	printf("%s, len = %d\n", res, strlen(res));
	return 0;
}


int count_one_bits(unsigned int val)
{
	int ones;

	for (ones=0; val!=0; val >>= 1)
	{
		if (val % 2 == 1)
		{
			ones += 1;
		}
	}

	printf("%d\n", ones);

	return ones;
}


int main(void)
{
	// de_allblank("gu  jggg    g xxx         ");
	// printf("\n");
	deblank("gu  jggg    g xxx         ");
	count_one_bits(66);
	getc(stdin);
}

