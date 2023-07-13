#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person{
	char num[100];
	char name[100];
	int a[4];
};
struct node{
	struct person who;
	int i;
	struct node* p;
}; 

int main(void){
	struct node *head,*End;
	head=(struct node*)malloc(sizeof(struct node));
	
	int status,n;
	scanf("%d",&status);
	if(status==1){
		scanf("%d",&n);
		int cnt;
		for(cnt=0;cnt<n;cnt++){
			struct node *next=(struct node *)malloc(sizeof(struct node));
			scanf("%s %s %d %d %d %d",(next->who).num,(next->who).name,&(next->who).a[0],&(next->who).a[1],&(next->who).a[2],&(next->who).a[3]);  	 
		    if(cnt==0){
		    	next->i=cnt;
				head->p=next;
				End=head->p;
			}
			else{
				next->i=cnt;
				End->p=next;
				End=End->p;
			}
		}
		printf("完成了%d位同学的成绩输入\n",n);
	}	
	
	scanf("%d",&status);
	if(status==0)	return 0;
	else if(status==2){
		struct node *x=(struct node*)malloc(sizeof(struct node));
		x=head->p;
		while(x->p!=NULL){
			printf("%s %s %d %d %d %d\n",(x->who).num,(x->who).name,(x->who).a[0],(x->who).a[1],(x->who).a[2],(x->who).a[3]);
			x=x->p;
		}
	}
	
	else if(status==3){
		char numtosearch[100];
		char strtochange[100];
		int numtochange;
		int index;
		
		scanf("%s %d",numtosearch,&index);
		if(index==0){
			scanf("%s",strtochange);
		}
		else{
			scanf("%d",&numtochange);
		}
		
		struct node *tmp=(struct node*)malloc(sizeof(struct node));
		tmp=head->p;
		while(strcmp(((tmp->who).num),numtosearch)!=0)	
			tmp=tmp->p;
			
		if(index==0)
			strcpy((tmp->who).name,strtochange);
		else
			(tmp->who).a[index-1]=numtochange;
		printf("%s %s %d %d %d %d\n",(tmp->who).num,(tmp->who).name,(tmp->who).a[0],(tmp->who).a[1],(tmp->who).a[2],(tmp->who).a[3]);
	}
	
	else if(status==4||status==5){
		float average[n];
		int whatever;
		
		struct node *other=(struct node*)malloc(sizeof(struct node));
		other=head->p;
		for(whatever=0;whatever<n;whatever++){
			average[whatever]=((other->who).a[0]+(other->who).a[1]+(other->who).a[2]+(other->who).a[3])/4.0;
			other=other->p;
		}	
		
		struct node *last=(struct node*)malloc(sizeof(struct node));
		last=head->p;
		if(status==4)
		{
			while(1){
				printf("%s %s %.2f\n",(last->who).num,(last->who).name,average[last->i]);
				if(last->p==NULL)	break;
				last=last->p;
			}
		}
		else if(status==5){
			while(1){
				printf("%s %s %d %.2f\n",(last->who).num,(last->who).name,(last->who).a[0]+(last->who).a[1]+(last->who).a[2]+(last->who).a[3],average[last->i]);
				if(last->p==NULL)	break;
				last=last->p;
			}
		}
	}
	
	return 0;
}
