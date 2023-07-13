#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	short a = 0x253f, b = 0x7b7d;
	char ch;
	FILE* fp1, * fp2;

	fp1 = fopen("d:\\abc1.bin", "wb+");
	fp2 = fopen("d:\\abc2.txt", "w+");
	fwrite(&a, sizeof(char), 1, fp1);
	fwrite(&b, sizeof(char), 1, fp1);
	fprintf(fp2, "%d %d", a, b);

	rewind(fp1); rewind(fp2);
	while ((ch = fgetc(fp1)) != EOF)
		putchar(ch);                        // ?%}{  3f,25,7d,7b
	putchar('\n');

	while ((ch = fgetc(fp2)) != EOF)
		putchar(ch);
	putchar('\n');

	fclose(fp1);
	fclose(fp2);
	return 0;
}
/*
（1）	请思考程序的输出结果，然后通过上机运行来加以验证。
（2）	将两处sizeof(short)均改为sizeof(char)结果有什么不同，为什么？               只存低字节 
（3）   将fprintf(fp2,"%hx %hx",a,b) 改为 fprintf(fp2,"%d %d",a,b)结果有什么不同。  十进制 
*/
