#include <stdio.h>
#include <string.h>

typedef struct{
		char name[100];
		int grade;
	}unit;
	
int BinarySearch(unit num[],int key,int size);	
void BubbleSort(unit num[],int size);   //要求是稳定排序，就用冒泡了 
void swap(unit num[],int i,int j);

int main(void){
	int status[5]={-1};
	int total;
	int cnt=0;
	int storage;
	int key;
	scanf("%d",&status[cnt++]);
	scanf("%d",&total);
	
	unit statics[total];
	for(int index=0;index<total;index++){
		scanf("%s %d",statics[index].name,&statics[index].grade);
	}
	
	scanf("%d",&status[cnt++]);
	if(status[cnt-1]==0){
		printf("%d records were input!\n",total);
	}
	else if(status[cnt-1]==2){
		BubbleSort(statics,total);
		scanf("%d",&status[cnt++]);
		
		if(status[cnt-1]==0){
			printf("%d records were input!\n",total);
			puts("Reorder finished!");
		}
		
		else if(status[cnt-1]==3){
			scanf("%d",&status[cnt++]);
			
			if(status[cnt-1]==0){
				printf("%d records were input!\n",total);
				puts("Reorder finished!");
				
				for(int index=0;index<total;index++){
					printf("%s %d\n",statics[index].name,statics[index].grade);
				}
			}
			
			else if(status[cnt-1]==4){
				scanf("%d",&key);
				scanf("%d",&status[cnt++]);
				printf("%d records were input!\n",total);
				puts("Reorder finished!");
				for(int index=0;index<total;index++){
					printf("%s %d\n",statics[index].name,statics[index].grade);
				}
				
				if((storage=BinarySearch(statics,key,total))==-1)
					printf("not found!\n");
				else
					printf("%s %d",statics[storage].name,statics[storage].grade);
			}
		}
		
		else if(status[cnt-1]==4){
				scanf("%d",&key);
				scanf("%d",&status[cnt++]);
				printf("%d records were input!\n",total);
				puts("Reorder finished!");
				
				if((storage=BinarySearch(statics,key,total))==-1)
					printf("not found!\n");
				else
					printf("%s %d",statics[storage].name,statics[storage].grade);
			}
	}
	
	return 0;
}

int BinarySearch(unit num[],int key,int size){
	int flag=0;
	int head=0,tail=size-1,mid=(head+tail)/2;
	while(head<=tail){
		if(num[mid].grade>key){
			head=mid+1;
			mid=(head+tail)/2;
		}
		else if(num[mid].grade<key){
			tail=mid-1;
			mid=(head+tail)/2;
		}
		else{
			flag=1;
			break;
		}
	}
	if(flag) 
		return mid;
	else
		return -1;  
}

void BubbleSort(unit num[],int size){
	int i,j;
	for(i=0;i<size-1;i++){
		for(j=0;j<size-i-1;j++){
			if(num[j].grade<num[j+1].grade)
				swap(num,j,j+1);
		}
	}
}

void swap(unit num[],int i,int j){            //交换名字和成绩 
	int tmp;
	tmp=num[i].grade;
	num[i].grade=num[j].grade;
	num[j].grade=tmp;
	
	char stmp[100];
	strcpy(stmp,num[i].name);
	strcpy(num[i].name,num[j].name);
	strcpy(num[j].name,stmp);
}
