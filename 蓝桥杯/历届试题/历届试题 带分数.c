/*
100 可以表示为带分数的形式：100 = 3 + 69258 / 714。
还可以表示为：100 = 82 + 3546 / 197。
注意特征：带分数中，数字1~9分别出现且只出现一次（不包含0）。
类似这样的带分数，100 有 11 种表示法。
输入格式
从标准输入读入一个正整数N (N<1000*1000)
输出格式
程序输出该数字用数码1~9不重复不遗漏地组成带分数表示的全部种数。
注意：不要求输出每个表示，只统计有多少表示法！
样例输入1
100 
样例输出1
11 
样例输入2
105 
样例输出2
6 
*/ 
#include <stdio.h>
void xuanze( int [] , int  , int , int * ) ;
int panduan( int [] , int ) ;
void sc_pd( int [] , int * , int ) ;
int q_shu( int [] , int ) ;

int main(void)
{
	int n;
	scanf("%d", &n );
	int cs = 0;
	int sz[9] ;
	xuanze(sz , 0  , n , &cs);
	printf("%d", cs );
	return 0;
}
int q_shu(int sz[] , int n )
{
	int shu = 0 ;
	while( n -- > 0 )
	{
		shu *= 10 ;
		shu += * sz ;
		sz ++ ;
	}
	return shu;
}
void sc_pd(int sz[] , int * p_cs , int n)
{
	int i , j ;
	for( i = 0 + 1 ; i < 9 ; i ++ )
	{
		for( j = i + 1 ; j < 9 ; j ++ )
		{
			int s1 = q_shu( sz ,i );
			int s2 = q_shu(sz+ i ,j - i);
			int s3 = q_shu(sz+j,9 - j);
			if( s2 % s3 == 0 && s1 + s2 / s3 == n )
			{
				++ * p_cs;
			}
		}		
	}
}
int panduan(int sz[] , int k)
{
	int i;
	for( i = 0 ; i < k ; i ++ )
	{
		if( sz[i] == sz[k] )
		{
			return 0;
		} 
	}
	return 1;
}
void xuanze(int sz[] ,int i , int n , int * p_cs)
{
	if ( i == 9 )
	{
		sc_pd( sz , p_cs , n );
		return ;
	}
	for( sz[i] = 1 ; sz [i] <= 9 ; sz[i] ++ )
	{
		if( panduan( sz , i ) )
		{
			xuanze(sz , i + 1 , n , p_cs );
		}
	}
}
