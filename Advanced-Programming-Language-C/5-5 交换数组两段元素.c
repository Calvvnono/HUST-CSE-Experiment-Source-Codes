#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define min(a,b) (a>b)?b:a
void PartialExchange(int[],int,int,int,int,int); 
void swap(int[],int,int);
int main(void){
	int n;
	scanf("%d",&n);
	int a[n];	   
	 
	for(int what=0;what<n;what++){
		scanf("%d",&a[what]);
	} 
	 
	int l1,r1,l2,r2;
	scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
	PartialExchange(a,n,l1,r1,l2,r2);
	
	
	return 0;
}

void PartialExchange(int a[],int n,int l1,int r1,int l2,int r2){      //代码实现：先把长度相同的一段交换，再把剩下的元素逐一交换(其他个一个个挪位）
	int length=min(r1-l1+1,r2-l2+1);                 //把能对应换的长度先换掉 
	for(int x=l1,y=l2;x<l1+length && y<l2+length;x++,y++){
		swap(a,x,y);
	}
	
	int d=0;              //最终d是“剩下来要换的”元素个数 
              
	if((r1-l1)<(r2-l2)){
		int i,j;
		for(i=l2+length;i<=r2;i++){
			int tmp=a[i];
			for(j=l2+length+d;j>l1+length+d;j--)
				a[j]=a[j-1];
			a[l1+length+d]=tmp;
			d++;
		}
	}	
	
	else if ((r1-l1)>(r2-l2)){
		int i,j;
		for(i=l1+length;i<=r1;i++){
			int tmp=a[i];
			for(j=l1+length+d;j<l2+length+d-1;j++)
				a[j]=a[j+1];
			a[l2+length+d-1]=tmp;
			d++;
		}
	}
	
	else{
		//do nothing
	}
	
	for(int index=0;index<n;index++){
		if(index==n-1)
			printf("%d",a[index]);
		else
			printf("%d ",a[index]);
	}
	
} 

void swap(int a[],int l,int r){
	int tmp=a[l];
	a[l]=a[r];
	a[r]=tmp;
}
