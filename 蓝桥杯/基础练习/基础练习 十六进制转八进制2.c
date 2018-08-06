/*问题描述
　　给定n个十六进制正整数，输出它们对应的八进制数。

输入格式
　　输入的第一行为一个正整数n （1<=n<=10）。
　　接下来n行，每行一个由0~9、大写字母A~F组成的字符串，表示要转换的十六进制正整数，每个十六进制数长度不超过100000。

输出格式
　　输出n行，每行为输入对应的八进制正整数。

　　【注意】
　　输入的十六进制数不会有前导0，比如012A。
　　输出的八进制数也不能有前导0。

样例输入
2
39
123ABC

样例输出
　　71
　　4435274

　　【提示】
　　先将十六进制数转换成某进制数，再由某进制数转换成八进制。
*/
#include <stdio.h>
void shuru(int [] , int *) ;
int q_shu( char );
void shuchu( int [] , int );
void q_tw( int * , int * , int );
int q_zhi(int [] , int );
void sc_wb( int [] , int );
int main(void)
{
	int n;
	scanf("%d\n",&n);
	while(n-- > 0)
	{
		int sz[100000] ,ws=0;
		shuru( sz , &ws);
		shuchu( sz , ws );
	}
    return 0;
}
void sc_wb( int s[] , int n)
{
	while( n-- > 0)
	{
		printf("%04o",q_zhi( s , 3));
		s += 3 ;
	}
}
int q_zhi(int s[] , int n)
{
	int zhi = 0 ; 
	while(n-- > 0 )
	{
		zhi *= 16 ;
		zhi += * s++; 
	}
	return zhi;
}
void q_tw( int * tou , int * wei, int ws)
{
	* tou = ws % 3; 
	if( * tou == 0 )
	{
		* tou = 3;
	}
	* wei = ws - * tou; 
}
void shuchu( int s[] , int ws)
{
	int tou , wei ;
	q_tw(&tou , &wei , ws);
	printf("%o",q_zhi( s , tou ));
	sc_wb( s + tou , wei /3 );
	putchar('\n'); 
}
int q_shu( char c)
{
	if('A' <= c && c <='Z')
	{
		return c-'A'+10;
	}
	return c-'0';
}
void shuru(int s[] , int * ws )   
{
	char c;
	while((c=getchar()) != '\n')
	{
		s[*ws]=q_shu( c );
		++ *ws;
	}
}
