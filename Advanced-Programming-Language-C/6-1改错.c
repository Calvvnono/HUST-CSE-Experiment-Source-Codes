#include<stdio.h>
char *strcopy(char *, const char *);
int main(void)
{
	char s1[100], s2[100], *s3;     //s1,s2应为字符数组 
	printf("Input a string:\n");
	scanf("%s", s2);
	strcopy(s1, s2);
	printf("%s\n", s1);
	printf("Input a string again:\n");
	scanf("%s", s2);
	s3 = strcopy(s1, s2);
	printf("%s\n", s3);
	return 0;
}

/*将字符串s复制给字符串t，并且返回串t的首地址*/
char * strcopy(char *t, const char *s)
{
	char *tmp=t;
	while(*tmp++= *s++);
	return t;         //直接返回t不是首字符的位置 
}

