#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void reverse(bool seat[][5],int i,int head,int tail);
void output(int i,int head,int tail);
void Specialoutput(int i,int head,int tail);
char ParseChar(int x);

int main(void){
	bool seat[20][5]={false};
	int n;
	scanf("%d",&n);
	int order[n];
	for(int cnt=0;cnt<n;cnt++)
		scanf("%d",&order[cnt]);
		
	int i=0,j=0;
	int cnt=0;
	int flag=0;
	int tmp1;
	int tmp2;
	for(tmp1=0;tmp1<n;tmp1++){
		cnt=0;
		flag=0;
		for(i=0;i<20;i++){
			for(j=0;j<5;j++){
				if(seat[i][j]==false)
					cnt++;
				if(j==4 && cnt<order[tmp1])     //行末检验 
					cnt=0;
				if(cnt==order[tmp1]){
					flag=1;
					goto PRINT;
				}
			}
		}
		if(!flag)
			goto Selection;
		PRINT:
			if(flag){
				reverse(seat,i,j-cnt+1,j);
				output(i,j-cnt+1,j);
			}	
	}
	Selection:	
		if(!flag){             //没空位了，有空就放 
			for(tmp2=tmp1;tmp2<n;tmp2++){
				for(i=0;i<20;i++){
					for(j=0;j<5;j++){
						if(seat[i][j]==false && order[tmp2]!=0){
							order[tmp2]--;
							reverse(seat,i,j,j);
							Specialoutput(i,j,j);
							if(order[tmp2]!=0)
								printf(" ");
						}
					}
				}
			}
		}
	
	return 0;
}

void reverse(bool seat[][5],int i,int head,int tail){
	for(int index=head;index<=tail;index++){
		seat[i][index]=true;
	}
}

void output(int i,int head,int tail){
	for(int index=head;index<=tail;index++){
		if(index!=tail)
			printf("%d%c ",i+1,ParseChar(index));
		else
			printf("%d%c",i+1,ParseChar(index));
	}
	printf("\n");
}

void Specialoutput(int i,int head,int tail){
	for(int index=head;index<=tail;index++){
		if(index!=tail)
			printf("%d%c ",i+1,ParseChar(index));
		else
			printf("%d%c",i+1,ParseChar(index));
	}
}

char ParseChar(int x){
	char mark;
	switch(x){
		case 0: mark='A'; break; 
		case 1: mark='B'; break;
		case 2: mark='C'; break;
		case 3: mark='D'; break;
		case 4: mark='F'; break;
	}
	return mark;
}

