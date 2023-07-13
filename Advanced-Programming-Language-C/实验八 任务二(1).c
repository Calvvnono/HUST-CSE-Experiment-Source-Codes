#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
	char ch;
	FILE* fp;

	if (argc != 2)                    //*argv[0]�ǳ����� 
	{
		printf("Arguments error!\n");
		exit(-1);
	}
	if ((fp = fopen(argv[1], "r")) == NULL)    //*1->2
	{                                 
		printf("Can't open %s file!\n", argv[1]);
		exit(-1);
	}

	while ((ch = fgetc(fp)) != EOF)   /* ��filename�ж��ַ� */
		putchar(ch);                  /* ����ʾ����д�ַ� */
	fclose(fp);                       /* �ر�filename */
	
	return 0;
}
