#include <stdio.h>
int main(void)
{ 
	int i, x, k, flag = 0;
	printf("�������жϺ��������������1����������Ctrl+Z����\n");
	while ((scanf("%d", &x))!=EOF) {
		if(x==1)	printf("1�Ȳ�������Ҳ���Ǻ���\n");   //�������ĵ��� 
		else{
			flag=0;                   //ÿһ�ֶ�Ҫ��ʼ��flag 
			for(i=2,k=x>>1;i<=k;i++)    //���������Ż�    
				if (!(x%i)) {
					flag = 1;         //ֻҪwhileѭ��û�����ҳ��ֹ���������֮��flag��Ϊ1 
					break;
				}
			if(flag==1) printf("%d�Ǻ���\n", x);     //ӦΪflag==1 
			else printf("%d���Ǻ���\n", x);
		}
	}
	return 0;
}


