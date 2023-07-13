#include <stdio.h>
#include <string.h>

char* select(char a[100][100],int size);
int main(void){
	char a[100][100];
	char c;
	int i=0;
	while((c=getchar())!='\n'){
		scanf("%s",a[i]);
		i++;
	}
	
	int cnt;
	printf("%s %d",select(a,i),strlen(select(a,i)));
    return 0;
}

char* select(char a[100][100],int size){
	int i,j;
	int max;
	for(i=0;i<size;i++){
		max=i;
		for(j=i;j<size;j++){
			if(strlen(a[j])>strlen(a[max])){
				max=j;
			}
		}
		char tmp[100];
		strcpy(tmp,a[i]);
		strcpy(a[i],a[max]);
		strcpy(a[max],tmp);
	}
	return a[0];
}
