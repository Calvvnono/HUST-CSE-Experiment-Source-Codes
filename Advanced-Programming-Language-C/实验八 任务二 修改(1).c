#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
	FILE* fp;
	char ch;

	if (argc != 2)
	{
		printf("arguments error!\n");
		exit(-1);
	}
	if ((fp = freopen(argv[1], "r", stdin)) == NULL)
	{                                 
		printf("Can't open %s file!\n", argv[1]);
		exit(-1);
	}
	while ((ch = getchar()) != EOF)
		putchar(ch);
	fclose(fp);                      

	return 0;
}
