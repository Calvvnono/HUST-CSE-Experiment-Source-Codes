#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	unsigned short x;
	int m,n;
	int flag=0;
	scanf("%x %d %d",&x,&m,&n);
	if(m>=0 && n && m<16 && m+n<16){
		x=(x>>m)<<(16-n);
		flag=1;
	}
	if(flag) printf("%x",x);
	else puts("error");
}
