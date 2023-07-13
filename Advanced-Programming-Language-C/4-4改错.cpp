#include <stdio.h> 
#define MAX(a,b,c) (a>b)?((a>c)?a:c):(b>c?b:c)   //*

int max(int x, int y, int z);         //函数未声明 
float sum(float x, float y);

int main(void)
{
	int a, b, c;
  	float d, e;
  	printf("Input three integers:");
  	scanf("%d %d %d",&a,&b,&c);
  	printf("\nThe maximum of them is %d(%d)\n",max(a,b,c),MAX(a,b,c));

  	printf("Input two floating point numbers:");
	scanf("%f %f",&d,&e);
	printf("\nThe sum of them is %f\n",sum(d,e));
	return 0;
}
	
int max(int x, int y, int z)					
{
	int m=z;
	if (x>y){
		if(x>z) m=x;         //主if要套起来 
	}
	else
    	if(y>z) m=y;
    return m;
}

float sum(float x, float y)
{
	return x+y;
}

