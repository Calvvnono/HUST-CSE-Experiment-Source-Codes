#include <stdio.h>
void task0();
void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void scheduler(char a[],int size);
void execute(char a[],int size); 

int main(void){
	char a[100];
	scanf("%s",a);
	int cnt=0;
	while(a[cnt]!='\0'){
		cnt++;
	}
	scheduler(a,cnt);
	return 0;
}

void task0(){
	printf("task0 is called!\n");
}
void task1(){
	printf("task1 is called!\n");
}
void task2(){
	printf("task2 is called!\n");
}
void task3(){
	printf("task3 is called!\n");
}
void task4(){
	printf("task4 is called!\n");
}
void task5(){
	printf("task5 is called!\n");
}
void task6(){
	printf("task6 is called!\n");
}
void task7(){
	printf("task7 is called!\n");
}
void scheduler(char a[],int size){
	execute(a,size);
} 
void execute(char a[],int size){
	int index;
	int x;
	for(index=0;index<size;index++){
		x=a[index]-'0';
		switch(x){
			case 0: task0(); break;
			case 1: task1(); break;
			case 2: task2(); break;
			case 3: task3(); break;
			case 4: task4(); break;
			case 5: task5(); break;
			case 6: task6(); break;
			case 7: task7(); break;
		}
	}
}
