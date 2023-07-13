#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
	char ch;
	FILE* fp;

	if (argc != 2)                    //*argv[0]是程序名 
	{
		printf("Arguments error!\n");
		exit(-1);
	}
	if ((fp = fopen(argv[1], "r")) == NULL)    //*1->2
	{                                 
		printf("Can't open %s file!\n", argv[1]);
		exit(-1);
	}

	while ((ch = fgetc(fp)) != EOF)   /* 从filename中读字符 */
		putchar(ch);                  /* 向显示器中写字符 */
	fclose(fp);                       /* 关闭filename */
	
	return 0;
}
