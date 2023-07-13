#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char tmp;
	int flag=0;
	while((tmp=getchar())!='!'){
		if(tmp==' '){
			if(!flag){
			flag=1;
			printf("%c",tmp);
			}
			else continue;
		}
		else{
			flag=0;
			printf("%c",tmp);
		}	
	}
	printf("!");
	return 0;
}
