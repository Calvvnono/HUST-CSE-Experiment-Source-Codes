/*��1������ִ��Դ���򡣽����ٽ���strcateʱ���۲��ַ�����t��s�е����ݣ���������Ƿ���ȷ��
������ִ�й��������ڵڶ���while���������ʱ��iΪ��ֵ��t[i]Ϊ��ֵ�������ý���Ƿ�������⡣
������ִ�й�������strcate�����������Ǽ��һ�����"}"������ʱ���ַ�����t��s�ֱ�Ϊ��ֵ��
�����Ƿ�ʵ�����ַ������ӡ�
��2�����ٽ��뺯��strdelcʱ���۲��ַ�����s�е����ݺ��ַ�c��ֵ����������Ƿ���ȷ��
����ִ��for�������У��۲��ַ�����s, j��kֵ�ı仯�������ý���Ƿ�������⡣
������ִ�й�������strdelc������������"}"������ʱ���ַ���sΪ��ֵ��
�����Ƿ�ʵ������Ҫ���ɾ��������*/

#include<stdio.h>
void strcate(char [],char []);
void strdelc(char [],char );
int main(void)
{
	char a[]="Language", b[100]="Programming";  //b[]�ĳ���Ҫ�趨һ�� 
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

