#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char a[100];
	int cnt=0;
	while((a[cnt]=getchar()) != EOF){
		cnt++;
	}
	for(int index=0;index<cnt;index++){
		if(a[index]>='A' && a[index]<='Z'){
			char b=a[index]+32;	
			putchar(b);
		}
		else 
			putchar(a[index]);
	}
	return 0;
}

