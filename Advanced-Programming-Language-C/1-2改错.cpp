#include <stdio.h>
int main()
{
    char c,numchar,numline;
    numchar=0;
    numline=0;
    printf("�����������ı�����������Ctrl+z������\n");
    while((c=getchar()) !=EOF)
    {
        numchar++;
        if(c=='\n')
            numline++;
    }
    printf("�ַ���:%d,",numchar++);
    printf("����:%d\n",numline);
    return 0;
}

