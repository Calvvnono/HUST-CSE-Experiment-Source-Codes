#include <stdio.h>
//if°æ 
int main(void)
{
	float x,tax;
	scanf("%f",&x);
	if(x<0)
	{
		printf("error\n");
	}
	if(x<1000){tax=0;}
	else if(x>=1000&&x<2000)	tax=0.05*(x-999);
	else if(x>=2000&&x<3000)	tax=0.10*(x-1999)+1000*0.05;
	else if(x>=3000&&x<4000)	tax=0.15*(x-2999)+1000*0.1+1000*0.05;
	else if(x>=4000&&x<5000)	tax=0.20*(x-3999)+1000*0.15+1000*0.1+1000*0.05;
	else						tax=0.25*(x-4999)+1000*0.2+1000*0.15+1000*0.1+1000*0.05;
	printf("Taxofsalary %.2f",tax);
}

//switch case°æ 
/*int main(void){
	float x,tax;
	scanf("%f",&x);
	int tmp=(int)(x/1000);
	switch(tmp){
		case 0: tax=0; break;
		case 1: tax=0.05*(x-1000); break;
		case 2: tax=0.10*(x-2000)+1000*0.05; break;
		case 3: tax=0.15*(x-3000)+1000*0.1+1000*0.05; break;
		case 4: tax=0.20*(x-4000)+1000*0.15+1000*0.1+1000*0.05; break;
		default:tax=0.25*(x-5000)+1000*0.2+1000*0.15+1000*0.1+1000*0.05; break;
	}
	printf("Taxofsalary %.2f",tax);
	return 0;
}*/

