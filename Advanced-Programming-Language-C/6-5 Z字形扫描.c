#include<stdio.h>
#define SIZE 500
int arr[SIZE][SIZE];
int re[SIZE*SIZE];
 
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	
	int i, j;
	for(i = 0; i < m; i ++)
	{
		for(j = 0; j < n; j ++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	 
	int judge = 0; // 0 右上； 1左下 
	
	int x = 0, y = 0;
	for(i = 0; i < m*n; i ++)
	{
		re[i] = arr[x][y];
		if(judge == 0)	// 右上
	 	{
			if(x-1 == -1 && y+1 < n)
			{
				y ++;
				judge = 1;
			}
			else if(x+1 < m && y+1 == n)
			{
				x ++;
				judge = 1;
			}
			else
			{
				x --;
				y ++;
			}
	 		
	 	}
	 	else	// 左下 
	 	{
	 		if(x+1 < m && y-1 == -1)
			{
	 			x ++;
	 			judge = 0;
	 		}
	 		else if(x+1 == m && y+1 < n)
	 		{
	 			y ++;
	 			judge = 0;
	 		}
	 		else
	 		{
	 			x ++;
				y --;
	 		}
	 	}
	} 
	
	
	for(i = 0; i < m*n; i ++)
	{
		printf("%d ", re[i]);
	}
	
	return 0;
}

