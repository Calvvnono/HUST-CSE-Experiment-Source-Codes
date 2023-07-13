/*（1）单步执行源程序。进跟踪进入strcate时，观察字符数组t和s中的内容，分析结果是否正确。
当单步执行光条刚落在第二个while语句所在行时，i为何值？t[i]为何值？分析该结果是否存在问题。
当单步执行光条落在strcate函数块结束标记即右花括号"}"所在行时，字符数组t和s分别为何值？
分析是否实现了字符串连接。
（2）跟踪进入函数strdelc时，观察字符数组s中的内容和字符c的值，分析结果是否正确。
单步执行for语句过程中，观察字符数组s, j和k值的变化，分析该结果是否存在问题。
当单步执行光条落在strdelc函数块结束标记"}"所在行时，字符串s为何值？
分析是否实现了所要求的删除操作。*/

#include<stdio.h>
void strcate(char [],char []);
void strdelc(char [],char );
int main(void)
{
	char a[]="Language", b[100]="Programming";  //b[]的长度要设定一下 
	printf("%s %s\n", b,a);
	strcate(b,a);	printf("%s %s\n",b,a);
	strdelc(b, 'a');	printf("%s\n",b);
	return 0;
}

void strcate(char t[],char s[])
{
	int i = 0,  j = 0;
	while(t[i++]) ;
	t--;                     
	while((t[i++] = s[j++] )!= '\0');
}

void strdelc(char s[], char c)
{
	int j,k;
	for(j=k=0; s[j] != '\0'; j++)     
		if(s[j] != c)	s[k++] = s[j];
	s[k]='\0';                          
}

