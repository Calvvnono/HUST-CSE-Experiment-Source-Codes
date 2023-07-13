#include <stdio.h>
char *strcpy(char *,const char *);
void main(void)
{
    char a[60],b[60]="there is a boat on the lake.";   //a²»¹»³¤ 
	printf("%s\n",strcpy(a,b));
}

char *strcpy(char *s,const char *t)
{
    char *tmp=s;                                       //*
	while(*tmp++=*t++);
    return s;
}

