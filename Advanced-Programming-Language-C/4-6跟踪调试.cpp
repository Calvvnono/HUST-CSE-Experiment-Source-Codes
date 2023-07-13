//进入函数integerl_fraction时，watch窗口中x为何值(s)？在返回main时, watch窗口中i为何值([s])？

#include <stdio.h> //* 
#define  R
int integer_fraction(float x);
void assert(int a);       //*

int main(void)
{
	float  r, s;
	int s_integer=0;
    printf ("Input a number: ");
    scanf("%f",&r);
    #ifdef  R
       s=3.14159*r*r;
       printf("Area of round is: %f\n",s);
       s_integer=integer_fraction(s);
       assert((s-s_integer)<0.5);
       printf("The integer fraction of area is %d\n", s_integer);
    #endif
    return 0;
}

int integer_fraction(float x)
{
	int i=x;
	return i;
}

void assert(int a){
	if(a==1)	
		;
	else if(a==0)
		printf("assertion failed\n");
}

