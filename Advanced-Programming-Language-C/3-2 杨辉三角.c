#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
    int i = 0, j = 0;
    int LINE_MAXIMUM;
    scanf("%d",&LINE_MAXIMUM);
    LINE_MAXIMUM+=1;
    int a[LINE_MAXIMUM][LINE_MAXIMUM];
    a[LINE_MAXIMUM][LINE_MAXIMUM] = {0};
    int k = 0;
 
    /* ����ά���� */
    for(i = 0; i < LINE_MAXIMUM; i++) //����
    {
        for(j = 0; j <= i; j++)    //ÿ�е���������n�е�������n�
        {
            if(j == 0 || j == i)   //ÿ�е�һ�к����һ��Ϊ1
                a[i][j] = 1;
            else                   //ÿ�����������Ϸ�����֮��
                a[i][j] = a[i - 1][j - 1]+ a[i - 1][j];
        }
    }
 
    /* ��ӡ������ǣ������� */
    for(i = 0; i < LINE_MAXIMUM; i++)
    {
        //������ǰ��ӡ�ո����һ�пո���Ϊ0
        for(k = 1; k <= 3*(LINE_MAXIMUM-1)-2*i; k++)
            printf(" ");
        for(j = 0; j <= i; j++)
            printf("%-4d", a[i][j]);
        printf("\n");
    }
    return 0;
}
