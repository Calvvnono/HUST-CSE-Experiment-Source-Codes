#include <stdio.h>
long long sum_fac(int n);  //函数未声明 

int main(void)
{
    int k;
    for(k=1;k<=20;k++)
        printf("k=%d\tthe sum is %lld\n",k,sum_fac(k));   //相应的，改lld 
    return 0;
}
long long sum_fac(int n)
{
    long long s=0;                 //s定long long，不然不够大 
    int i;
    long long fac=1;               //fac不能定int且没初始化 
    for(i=1;i<=n;i++){
    	fac*=i;
    	s+=fac;
	}
        
    return s;
}

