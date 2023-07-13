 #include <stdio.h>
 #include <math.h>
 #include <stdlib.h>
 #include <string.h>
 
int main(void){
	unsigned long IP[100]={0};
	int cnt=0;
	while((scanf("%d",&IP[cnt]))!=EOF){  //¶Áµ½EOF½áÊø
		cnt++;
	}
	
	int ip1,ip2,ip3,ip4;
	for(int index=0;index<cnt;index++){
		ip1=IP[index]>>24;
		ip2=IP[index]>>16 & 0xff;
		ip3=IP[index]>>8 & 0xff;
		ip4=IP[index] & 0xff;
		printf("%d.%d.%d.%d\n",ip1,ip2,ip3,ip4);
	}
	return 0;
}
