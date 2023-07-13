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
void SelectionSort(struct node* head,int length,int order,float average[]);
void BubbleSort(struct node* head,int length,int order,float average[]);
void StaticSwap(struct node* head,int l,int r,float average[]);

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
				End->p=NULL;
			}
		}
	}

	float average[n];
	int whatever;
	struct node *other=(struct node*)malloc(sizeof(struct node));
	other=head->p;
	for(whatever=0;whatever<n;whatever++){
		average[whatever]=((other->who).a[0]+(other->who).a[1]+(other->who).a[2]+(other->who).a[3])/4.0;
		other=other->p;
	}

	scanf("%d",&status);
	if(status==6){
		int x,y;
		scanf("%d %d",&x,&y);
		printf("完成了%d位同学的成绩输入\n",n);
		if(y==0)
			SelectionSort(head,n,x,average);
		else if(y==1)
			BubbleSort(head,n,x,average);
	}
	return 0;
}

void SelectionSort(struct node* head,int length,int order,float average[]){
	struct node *l=(struct node *)malloc(sizeof(struct node));
	struct node *r=(struct node *)malloc(sizeof(struct node));
	if(order==0){
		int min;
		for(l=head->p;l!=NULL;l=l->p){
			min=l->i;
			for(r=l;r!=NULL;r=r->p){
				if(average[r->i]<average[min])
					min=r->i;
			}
			StaticSwap(head,l->i,min,average);
		}
	}
	else if(order==1){
		int max;
		for(l=head->p;l!=NULL;l=l->p){
			max=l->i;
			for(r=l;r!=NULL;r=r->p){
				if(average[r->i]>average[max])
					max=r->i;
			}
			StaticSwap(head,l->i,max,average);
		}
	}

	struct node *last=(struct node*)malloc(sizeof(struct node));
	last=head->p;
	while(1){
		printf("%s %s %.2f\n",(last->who).num,(last->who).name,average[last->i]);
		if(last->p==NULL)	break;
		last=last->p;
	}
}

void BubbleSort(struct node* head,int length,int order,float average[]){
	struct node *l=(struct node *)malloc(sizeof(struct node));
	struct node *r=(struct node *)malloc(sizeof(struct node));
	if(order==0){
		for(l=head->p;l!=NULL;l=l->p){
			for(r=head->p;r!=NULL;r=r->p){
				if(average[r->i]>average[r->i+1])
					StaticSwap(head,r->i,r->i+1,average);
			}
		}
	}
	else if(order==1){
		for(l=head->p;l!=NULL;l=l->p){
			for(r=head->p;r!=NULL;r=r->p){
				if(average[r->i]<average[r->i+1])
					StaticSwap(head,r->i,r->i+1,average);
			}
		}
	}

	struct node *last=(struct node*)malloc(sizeof(struct node));
	last=head->p;
	while(1){
		printf("%s %s %.2f\n",(last->who).num,(last->who).name,average[last->i]);
		if(last->p==NULL)	break;
		last=last->p;
	}
}

void StaticSwap(struct node* head,int l,int r,float average[]){
	struct node *left=(struct node *)malloc(sizeof(struct node));
	struct node *right=(struct node *)malloc(sizeof(struct node));
	for(left=head->p; ;left=left->p){
		if(left->i==l)
			break;
	}
	for(right=head->p; ;right=right->p){
		if(right->i==r)
			break;
	}

	char TempNum[100],TempName[100];
	float TempAverageGrade;

	strcpy(TempNum,(left->who).num);
	strcpy((left->who).num,(right->who).num);
	strcpy((right->who).num,TempNum);

	strcpy(TempName,(left->who).name);
	strcpy((left->who).name,(right->who).name);
	strcpy((right->who).name,TempName);

	TempAverageGrade=average[l];
	average[l]=average[r];
	average[r]=TempAverageGrade;
}






















