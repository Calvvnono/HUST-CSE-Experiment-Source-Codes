#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	int x;
	scanf("%d",&x);
	
	int a,b,c,d,e,f,g,h;
	a=x&0x0000000f;
	b=x>>4&0x0000000f;
	c=x>>8&0x0000000f;
	d=x>>12&0x0000000f;
	e=x>>16&0x0000000f;
	f=x>>20&0x0000000f;
	g=x>>24&0x0000000f;
	h=x>>28&0x0000000f;
	
	printf("%X%X%X%X%X%X%X%X",h,g,f,e,d,c,b,a);
	
	return 0;
}
