#include <stdio.h>

int isPerfect(int x)
{
    int y,s;
    for(s=0,y=1;y<x;y++)
    {    if(!(x%y))
            s+=y;
    }
    if(s==x)
        return 1;
	else
		return 0;
}
void PrintPerfect(int x){
	int a[10000]={0};
	int cnt=0;
	for(int i=1;i<x;i++){
		if(!(x%i))	a[cnt++]=i;
	}
	for(int tmp=0;tmp<cnt;tmp++){
		if(tmp!=cnt-1) printf("%d+",a[tmp]);
		else printf("%d\n",a[tmp]);
	}
}
int main()
{
    int a;
    for(a=1;a<=10000;a++) /*遍历所有数*/
        if(isPerfect(a))
        { 
		    printf("%d=",a);
			PrintPerfect(a);
		}
    return 0;
}

