#include<stdio.h>

double sum(double x, int n)
{
	double z=1;
	double sum=1;
	int cnt=1;
	while(cnt<=n){
		z=z*x/cnt;
		sum+=z;
		cnt++;
	}
	return sum;
}

int main()
{
 	double x;
	int n;
	printf("Input x and n:");
	scanf("%lf%d",&x,&n);
	printf("The result is %lf:",sum(x,n));
	return 0;	  
}

