#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include <string.h>
 
int main(void)
{

    int i;
    int j;
    for(i=100;i<1000;i++){
    	j=(i*i)/1000;
    	j=i*i-j*1000;
    	if(j==i)	
			printf("%d\n",i);
	}
   
    return 0;
}
