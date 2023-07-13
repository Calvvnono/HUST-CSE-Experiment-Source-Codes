 #include <stdio.h>
 #include <math.h>
 #include <stdlib.h>
 #include <string.h>
 
 #define p(a,b,c) (a+b+c)/2.0
 #define s(p,a,b,c) sqrt(p*(p-a)*(p-b)*(p-c))
  
int main(void){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	double p=p(a,b,c);
	printf("s=%.2f\n",p);
	printf("area=%.2f",s(p,a,b,c));
	return 0;
}

