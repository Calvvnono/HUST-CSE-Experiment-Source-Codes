#include <stdio.h>
int main()
{
	char u[]="UVWXYZ";
	char v[]="xyz";
	struct T{
	int x;
	char c;
	char *t;
	}a[]={{11,'A',u},{100, 'B',v}};
	struct T *p;
	
	int flag=1;
	char tmp[100010];
	int read;
	while(flag){
		p=a;
		scanf("%s",tmp);
		read=tmp[0]-'0';
		switch(read){
			case 1: printf("%d\n\n",(++p)->x);
			break;
			case 2: printf("%d ",p++);
					printf("%c\n\n", p->c);
			break;
			case 3: printf("%c ",*p++->t);
					printf("%c\n\n",*p->t);
			break;
			case 4: printf("%c\n\n",*((++p)->t));
			break;
			case 5: printf("%c\n\n",*(++p->t));
			break;
			case 6: p=a; printf("%c\n\n",++*p->t);
			break;	
			default: flag=0;
			break;
		}
	}

	return 0;
}

