#include <stdio.h>
#include <string.h>
void Simplify(char*);
int main(void){
	int n;
	scanf("%d",&n);
	char* p[n];
	char array[n][100];
	char t[100];
	char tmp;
	int index=0,now=0; 
	getchar();
	while(index<n){
		now=0;
		while((array[index][now]=getchar())!='\n')
			now++;
 
		array[index][now]='\0';
		p[index]=array[index];
		index++;
	}
		
	int cnt;
	for(cnt=0;cnt<n;cnt++){
		Simplify(p[cnt]);
		if(cnt!=n-1)
			printf("\n");
	}
	return 0;
}

void Simplify(char* p){
	char tmp;
	int i;
	int flag1,flag2;
	for(i=0,flag1=0,flag2=0;i<strlen(p);i++){
		if((tmp=*(p+i))==' '||(tmp=*(p+i))=='\t'){
			if(!flag1)
				continue;
		}
		flag1=1;
		if((tmp=*(p+i))==' '&&flag2==0){
			flag2=1;
			putchar(tmp);
		}
		if((tmp=*(p+i))!=' '){
			flag2=0;
			putchar(tmp);
		}
	}
}
