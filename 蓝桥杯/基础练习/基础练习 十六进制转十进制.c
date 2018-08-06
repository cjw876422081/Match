/*
问题描述
　　从键盘输入一个不超过8位的正的十六进制数字符串，将它转换为正的十进制数后输出。
　　注：十六进制数中的10~15分别用大写的英文字母A、B、C、D、E、F表示。
样例输入
FFFF
样例输出
65535
*/ 
#include <stdio.h>
long long  q_zhi(char *);

int main(void)
{

	char zf[10];
	gets(zf);
	printf("%lld\n",q_zhi(zf));
    return 0;
}

long long  q_zhi(char *z)
{
	long long shu=0; 
	char * t=z;
	while(*t !='\0')
	{
		
		if(*t>='0'&&*t<='9')
		{
			shu+=*t-'0';
		}
		if(*t>='A'&&*t<='F')
		{
			shu+=*t-'A'+10; 
		}
		t++; 
		shu*=16;
	}	
	return shu/16;
} 

