#include<stdio.h>
#define SUM a+b
#define DIF a-b
#define SWAP(a,b)  a=a+b,b=a-b,a=a-b             //a=b,b=aû�� 
int main() 
{
    int a,b;
    printf("Input two integers a, b:");
    scanf("%d%d", &a,&b);
    printf("\nSUM=%d\nthe difference between square of a and square of b is:%d",SUM, (SUM)*(DIF));  //SUM��DIFҪ������ 
    SWAP(a,b);
    printf("\n\nNow a=%d,b=%d\n",a,b);
    return 0;
}

