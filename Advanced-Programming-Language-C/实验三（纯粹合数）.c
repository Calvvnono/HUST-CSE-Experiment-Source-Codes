#include <stdio.h>
int IsComposite(int a){
	int flag;
	int i, k;
	for(flag=0;a>0;a/=10) { 
		flag=0;              
		for(i=2,k=a>>1;i<=k;i++)            
			if (!(a%i)) {
				flag = 1;         
				break;
			}
		if(flag==0)	break;
	}
	return flag;
}

int main(void)
{ 
	int x;
	int cnt=0;
	for(x=100;x<1000;x++){
		if(IsComposite(x)==1){
			printf("%d ",x);
			cnt++;
		}
	}
	printf("\ntotal number:%d",cnt);
	return 0;
}
