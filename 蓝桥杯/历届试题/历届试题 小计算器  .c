/*
��������
����ģ������ͼ���������������ָ����ܰ�����ָ����
����1. ���֣�'NUM X'��XΪһ��ֻ������д��ĸ�����ֵ��ַ�������ʾһ����ǰ���Ƶ���
����2. ����ָ�'ADD','SUB','MUL','DIV','MOD'���ֱ��ʾ�Ӽ��ˣ�����ȡ�̣�����ȡ��
����3. ����ת��ָ�'CHANGE K'������ǰ����ת��ΪK����(2��K��36)
����4. ���ָ�'EQUAL'���Ե�ǰ����������
����5. ����ָ�'CLEAR'�������ǰ����
����ָ������¹��������
�������֣�����ָ�����������������ת��ָ����ָ�����ָ���п�����������
��������ָ�����ֵĵ�һ�����֣���ʾ������������֡����ڸ�����ָ��͸������м䲻���������ָ������ָ��
��������ָ�����ֵĵ�һ�����֣���ʾ����ֵ����������ָ��͵�һ�������м䲻���������ָ������ָ��
��������ת��ָ����ܳ������κεط�
��������������м������Ϊ�Ǹ���������С��2^63��
�����Դ�д��'A'~'Z'��ʾ10~35
�����ʽ
������1�У�1��n����ʾָ������
������2..n+1�У�ÿ�и���һ��ָ�ָ������һ����'CLEAR'��Ϊ��ʼ����������ָ�����
�����ʽ
�������θ���ÿһ��'EQUAL'�õ��Ľ��
��������
7
CLEAR
NUM 1024
CHANGE 2
ADD
NUM 100000
CHANGE 8
EQUAL
�������
2040


*/
#if 1
#include<stdio.h>
#include<stdbool.h>
#include<string.h> 

enum
{
	NUM ,  
	ADD ,
	SUB ,
	MUL ,
	DIV ,
	MOD ,
	CHANGE ,
	EQUAL ,
	CLEAR ,
};

int du_zl( void );
void du_sj( long long * , int ) ; 
int z_to_s( int ) ; 
void Output( long long , int ) ; 
void jisuan( long long * , long long , int  );
int main( void )
{
	int  n ; 
	scanf("%d" , & n ) ; 
	long long  sj1 = 0  , sj2 = 0  ; 
	int ys , t;
	int jz = 10; 
	bool sj1_cz;
	while( n -- > 0 )
	{
		switch( t = du_zl() )
		{
			case CLEAR  : sj1_cz = false ; 
						break ; 
			case NUM  	: if( sj1_cz == false )
						{
							du_sj( & sj1 , jz ) ; 
							sj1_cz = true ; 
						}
						else
						{
							du_sj( & sj2 , jz ) ; 
							jisuan( &sj1 , sj2 , ys ) ;
						
						}
						break ;
			case CHANGE : scanf("%d" ,&jz ) ; 
						break ; 
			case EQUAL  : Output( sj1  , jz ) ;
						putchar('\n') ; 
						break ; 
			default 	: ys = t ; 
						break ; 
		} 
		
	}
	return 0 ; 
}
void jisuan( long long * p_s1, long long p_s2 , int ys ) 
{
	switch( ys )
	{
		case ADD : *p_s1 += p_s2 ; 
					break ; 
		case SUB : *p_s1 -= p_s2 ;
					break ; 
		case MUL : *p_s1 *= p_s2 ; 
					break ; 
		case DIV : *p_s1 /= p_s2 ;
					break ; 
		case MOD : *p_s1 %= p_s2 ;
					break ; 
	}
}
void Output( long long  s , int jz )
{
	if(  s / jz != 0 )
	{
		Output( s / jz  , jz ) ; 
	}
	putchar( "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[ s % jz ]) ; 
}
int z_to_s( int z )
{
	if( '0' <= z && z <= '9')
	{
		return z -'0' ; 
	}
	return z - 'A' + 10 ; 
}
void du_sj( long long * p_sj , int jz )
{
	int c ; 
	while( (c= getchar()) == ' ')
	{
	}
	*p_sj = 0 ;
	do
	{
		*p_sj *= jz ;
		*p_sj += z_to_s( c ) ;  
	}
	while( (c= getchar()) != ' ' &&  c != '\n' );
}
int du_zl( void )
{
	char zl[10] ; 
	scanf("%s" , zl ) ; 
	static char *zljh[9] ={ "NUM" , "ADD" , "SUB" , "MUL" , "DIV" , "MOD" , "CHANGE" , "EQUAL" , "CLEAR" }; 
	int h ; 
	for( h = 0 ; h < 9; h ++ )
	{
		if(strcmp( zl , zljh[h]) == 0 )
		{
			return h ; 
		}
	}
} 
#endif
