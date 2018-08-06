/*
问题描述
　　模拟程序型计算器，依次输入指令，可能包含的指令有
　　1. 数字：'NUM X'，X为一个只包含大写字母和数字的字符串，表示一个当前进制的数
　　2. 运算指令：'ADD','SUB','MUL','DIV','MOD'，分别表示加减乘，除法取商，除法取余
　　3. 进制转换指令：'CHANGE K'，将当前进制转换为K进制(2≤K≤36)
　　4. 输出指令：'EQUAL'，以当前进制输出结果
　　5. 重置指令：'CLEAR'，清除当前数字
　　指令按照以下规则给出：
　　数字，运算指令不会连续给出，进制转换指令，输出指令，重置指令有可能连续给出
　　运算指令后出现的第一个数字，表示参与运算的数字。且在该运算指令和该数字中间不会出现运算指令和输出指令
　　重置指令后出现的第一个数字，表示基础值。且在重置指令和第一个数字中间不会出现运算指令和输出指令
　　进制转换指令可能出现在任何地方
　　运算过程中中间变量均为非负整数，且小于2^63。
　　以大写的'A'~'Z'表示10~35
输入格式
　　第1行：1个n，表示指令数量
　　第2..n+1行：每行给出一条指令。指令序列一定以'CLEAR'作为开始，并且满足指令规则
输出格式
　　依次给出每一次'EQUAL'得到的结果
样例输入
7
CLEAR
NUM 1024
CHANGE 2
ADD
NUM 100000
CHANGE 8
EQUAL
样例输出
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
