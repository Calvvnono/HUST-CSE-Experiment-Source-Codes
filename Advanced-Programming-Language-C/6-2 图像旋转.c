#include <stdio.h> 

void rotation(int *p,int m,int n);
	
int main(void){
	int m,n;
	scanf("%d %d",&m,&n);
	int num[m][n];
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&num[i][j]);
		}
	}

	rotation(num[0],m,n);
	
	return 0;
}
	
void rotation(int *p,int m,int n){
	int x,y;
	for(x=n-1;x>=0;x--){             //从右往左，从上往下打印 
		for(y=0;y<m;y++){
			if(y==0)
				printf("%d",*(p+y*n+x));
			else
				printf(" %d",*(p+y*n+x));
		}
		if(x==0)
			break;
		else
			printf("\n");
	}
}











