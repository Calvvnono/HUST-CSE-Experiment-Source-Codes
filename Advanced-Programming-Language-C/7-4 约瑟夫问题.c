#include<stdio.h>
int flag[100]={0};

void Josephus(int N,int n,int m,int pos){
	int cnt;
	if(n==1)	return;
	for(cnt=1;cnt<=m;pos++){
		pos=pos%N;
		if(flag[pos]==0)	
			cnt++;
	}
	flag[pos-1]=1; 
	if(n!=2) printf("%d ",pos);
	else printf("%d",pos);
	Josephus(N,n-1,m,pos);
}

int main(void){
	int i;
    int N,M;
    scanf("%d %d",&N,&M);
    const int n=N;
    
    Josephus(n,N,M,0);
	for(i=0;flag[i];i++)
		;
	printf("\n%d",i+1);
}
