#include<stdio.h>
#define N 10
#define M 3
int flag[N]={0};

void Josephus(int n,int m,int pos){
	int cnt;
	if(n==1)	return;
	for(cnt=1;cnt<=m;pos++){
		pos=pos%N;
		if(flag[pos]==0)	
			cnt++;
	}
	flag[pos-1]=1; 
	printf("%d ",pos);
	Josephus(n-1,m,pos);
}

int main(void){
	int i;
	Josephus(N,M,0);
	for(i=0;flag[i];i++)
		;
	printf("\n%d",i+1);
}
