#include <stdio.h>
#include <string.h>
void initialize()
{
	FILE* fp0 = fopen("source.txt", "w+");
	char str0[] = "May you have enough happiness to make you sweet, enough trials to make you strong, enough sorrow to keep you human, enough hope to make you happy? Always put yourself in others' shoes. If you feel that it hurts you, it probably hurts the other person, too.";
	fputs(str0, fp0);
	fclose(fp0);
}

int main(void){
    initialize();
	FILE* fp=fopen("source.txt","rw+");
	char str[100];
	char target[10],key[10];
	scanf("%s%s",target,key);
	
	char strtmp[1000]={'\0'};
	int cnt=0;
	int cnt2=0;
	char tmpchar[2]={'\0'};
	int flag;
	while(fscanf(fp,"%s",str)!=EOF){
		flag=0;
		if(str[strlen(str)-1]==','||str[strlen(str)-1]=='.'||str[strlen(str)-1]=='!'||str[strlen(str)-1]=='?'){
			tmpchar[0]=str[strlen(str)-1];             //Ä¨·ûºÅ 
			str[strlen(str)-1]='\0';
			flag=1;
		}
			
		if(strcmp(str,target)==0){
			strcat(strtmp,key);
			cnt++;
			if(flag)                                  //·ûºÅ»¹Ô­ 
				strcat(strtmp,tmpchar);
			strcat(strtmp," ");
		}
		else{
			strcat(strtmp,str);
			if(flag)
				strcat(strtmp,tmpchar);
			strcat(strtmp," ");
		}
		cnt2++;
	}
	
	printf("%d\n",cnt);
	rewind(fp);
	fputs(strtmp, fp);
	fclose(fp);
	
	FILE* _fp=fopen("source.txt","rw+");
	int index=0;	
	while(index<cnt2){
		fscanf(_fp,"%s",str);
		printf("%s",str);
		printf(" ");
		index++;
	}
	fclose(_fp);
	
	return 0;
}
