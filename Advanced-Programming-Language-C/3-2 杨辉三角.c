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
 
    /* 填充二维数组 */
    for(i = 0; i < LINE_MAXIMUM; i++) //行数
    {
        for(j = 0; j <= i; j++)    //每行的列数（第n行的数字有n项）
        {
            if(j == 0 || j == i)   //每行第一列和最后一列为1
                a[i][j] = 1;
            else                   //每个数等于它上方两数之和
                a[i][j] = a[i - 1][j - 1]+ a[i - 1][j];
        }
    }
 
    /* 打印杨辉三角（等腰） */
    for(i = 0; i < LINE_MAXIMUM; i++)
    {
        //在数字前打印空格，最后一行空格数为0
        for(k = 1; k <= 3*(LINE_MAXIMUM-1)-2*i; k++)
            printf(" ");
        for(j = 0; j <= i; j++)
            printf("%-4d", a[i][j]);
        printf("\n");
    }
    return 0;
}
