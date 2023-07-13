#include<stdio.h>
#include<math.h>
#include<stdbool.h>
int rank[15];//pos列i行 
bool vis[15];//标记第i行是否走过
int n,cnt=0; //全局
void dfs(int pos){
	if(pos==n+1){
		bool flag=true;
		for(int i=1;i<=n;i++){
			bool flag2=true;
			for(int j=i+1;j<=n;j++){//枚举任意两个皇后 
				if(abs(i-j)==abs(rank[i]-rank[j])){//两个皇后处于一条对角线 
					flag=false;
					flag2=false;
					break;
				}
			}
			if(flag2==false)	break;//如果一个填满情况对角线有两个或以上，则直接跳出循环 
		}
		if(flag)	cnt++;
		return;
	}
	for(int i=1;i<=n;i++){//枚举每一行 
		if(vis[i]==false){//第i行没走过 
			rank[pos]=i;//pos列在i行 
			vis[i]=true;
			dfs(pos+1);//递归下一列 
			vis[i]=false;
		}
	}
}
int main(){
    int d;
	scanf("%d",&n);
	dfs(1);//从第一列开始枚举 
	if(cnt!=0)
        printf("%d",cnt);
    else
        printf("无解");
	return 0;
}
