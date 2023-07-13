#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int IsFlower(int a,int k);
int main(void){
	int k[100];
	int whatever=0;
	while(1){
		scanf("%d",&k[whatever]);
		if(k[whatever]==0)	break;
		whatever++;
	}
	int Storage[100000];
	
	int no=0;
	while(k[no]!=0){
		int index=0;
		int cnt;
		for(cnt=pow(10,k[no]-1);cnt<pow(10,k[no]);cnt++){
			if(IsFlower(cnt,k[no]))
				Storage[index++]=cnt;
		}
		
		if(k[no]==3)	printf("%d位的水仙花数共有%d个",k[no],index);
		if(k[no]==4)	printf("%d位的四叶玫瑰数共有%d个",k[no],index);
		if(k[no]==5)	printf("%d位的五角星数共有%d个",k[no],index);
		if(k[no]==6)	printf("%d位的六合数共有%d个",k[no],index);
		if(k[no]==7)	printf("%d位的北斗星数共有%d个",k[no],index);
		if(k[no]==8)	printf("%d位的八仙数共有%d个",k[no],index);

		for(int i=0;i<index;i++){
			if(i!=index-1)	
				printf("%d,",Storage[i]);
			else  
				printf("%d\n",Storage[i]);
		}
		no++;
	}
	
	return 0;
}

int IsFlower(int a,int k){
	int flag=0;
	int r;
	int tmp=a;
	int sum=0;
	while(tmp>0){
		r=tmp%10;
		tmp /= 10;
		sum += pow(r,k);
	}
	if(sum==a){
		flag=1;
	}
	return flag;
}
