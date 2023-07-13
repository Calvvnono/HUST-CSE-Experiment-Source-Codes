#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include <string.h>
int IsPrime(int x); 
 
int main(void)
{
	int a[100]={0};
	int i=0;
	while((scanf("%d",&a[i]))!=EOF){
		i++;
	}

	int tmp;
	for(int index=0;index<i;index++){
		for(tmp=2;tmp<a[index];tmp++){
			if(IsPrime(tmp) && IsPrime(a[index]-tmp))
				break;
		}   
		printf("%d=%d+%d\n",a[index],tmp,a[index]-tmp);
	}
    return 0;
}

int IsPrime(int x){
	int flag=1;
	for(int cnt=2;cnt*cnt<=x;cnt++){
		if(x%cnt==0)	flag=0;
	}
	return flag;
}

