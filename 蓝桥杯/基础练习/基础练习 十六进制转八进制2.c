/*��������
��������n��ʮ��������������������Ƕ�Ӧ�İ˽�������

�����ʽ
��������ĵ�һ��Ϊһ��������n ��1<=n<=10����
����������n�У�ÿ��һ����0~9����д��ĸA~F��ɵ��ַ�������ʾҪת����ʮ��������������ÿ��ʮ�����������Ȳ�����100000��

�����ʽ
�������n�У�ÿ��Ϊ�����Ӧ�İ˽�����������

������ע�⡿
���������ʮ��������������ǰ��0������012A��
��������İ˽�����Ҳ������ǰ��0��

��������
2
39
123ABC

�������
����71
����4435274

��������ʾ��
�����Ƚ�ʮ��������ת����ĳ������������ĳ������ת���ɰ˽��ơ�
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
