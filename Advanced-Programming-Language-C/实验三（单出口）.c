#include <stdio.h>
int main(void)
{ 
	int i, x, k, flag = 0;
	printf("本程序判断合数，请输入大于1的整数，以Ctrl+Z结束\n");
	while ((scanf("%d", &x))!=EOF) {
		flag=0;                   
		for(i=2,k=x>>1;i<=k;i++)            
			if (!(x%i)) {
				flag = 1;          //直接去掉break 就是单出口了
				//break;
			}
		if(flag==1) printf("%d是合数\n", x);      
		else printf("%d不是合数\n", x);
	}
	return 0;
}
