#include <stdio.h> 

#define ToAscii 48
int main(void){
	int a;
	char s[32];
	scanf("%d",&a);
	
	for(int index=0; index<32 ;index++){
		s[index] = abs(((a >> index) % 2))+ToAscii;     //注意负数取完余是-1 !
	}
	
	for(int cnt=31;cnt>=0;cnt--){
		putchar(s[cnt]);
	}
	
	return 0;
}
