#include <stdio.h> 
#define CHANGE 0
//#define CHANGE 1
int main(void){
	char a[100];
	int cnt=0;
	while((a[cnt]=getchar()) != '\n'){
		cnt++;
	}
	
	#if CHANGE==1 
		for(int index=0;index<cnt;index++){
			if(a[index]>='A' && a[index]<='Z'){
				char b=a[index]+32;	
				putchar(b);
			}
			else if(a[index]>='a' && a[index]<='z'){
				char b=a[index]-32;
				putchar(b);
			}
			else
				putchar(a[index]);
		}
	#elif CHANGE==0
		for(int index=0;index<cnt;index++){
			putchar(a[index]);
		}
	#endif
		
	return 0;
}
