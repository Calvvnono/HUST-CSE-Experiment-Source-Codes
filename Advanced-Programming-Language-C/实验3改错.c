#include <stdio.h>
int main(void)
{ 
	int i, x, k, flag = 0;
	printf("本程序判断合数，请输入大于1的整数，以Ctrl+Z结束\n");
	while ((scanf("%d", &x))!=EOF) {
		if(x==1)	printf("1既不是质数也不是合数\n");   //可以做的调整 
		else{
			flag=0;                   //每一轮都要初始化flag 
			for(i=2,k=x>>1;i<=k;i++)    //可以做的优化    
				if (!(x%i)) {
					flag = 1;         //只要while循环没结束且出现过合数，则之后flag都为1 
					break;
				}
			if(flag==1) printf("%d是合数\n", x);     //应为flag==1 
			else printf("%d不是合数\n", x);
		}
	}
	return 0;
}


