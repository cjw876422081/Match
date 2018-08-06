/*问题描述
　　农民约翰母牛总是产生最好的肋骨。你能通过农民约翰和美国农业部标记在每根肋骨上的数字认出它们。
农民约翰确定他卖给买方的是真正的质数肋骨，是因为从右边开始切下肋骨，每次还剩下的肋骨上的数字都组成一个质数。
　　例如有四根肋骨的数字分别是：7 3 3 1，那么全部肋骨上的数字 7331是质数；
三根肋骨 733是质数；二根肋骨 73 是质数；当然,最后一根肋骨 7 也是质数。7331 被叫做长度 4 的特殊质数。
　　写一个程序对给定的肋骨的数目 N (1<=N<=8),求出所有的特殊质数。数字1不被看作一个质数。
输入格式
　　单独的一行包含N。
输出格式
　　按顺序输出长度为 N 的特殊质数,每行一个。
样例输入
4
样例输出
2333
2339
2393
2399
2939
3119
3137
3733
3739
3793
3797
5939
7193
7331
7333
7393*/
#include<stdio.h>
void shuchu( int [] , int [] , int );
void jisuan( int , int , int  ,int []);
int panduan( int );
int main( void )
{
	int n ; 
	scanf("%d", & n );
	int sz1[4] = { 2 , 3 , 5 , 7 };
	int sz2[4] = { 1 , 3 , 7 , 9 };
	shuchu( sz1 , sz2 , n );
	return 0 ; 
}
int panduan( int n )
{
	int i ;
	if( n == 2 )
	{
		return 1 ; 
	} 
	if( n % 2 == 0 )
	{
		return 0 ; 
	} 
	for( i = 3 ; i * i <= n ; i += 2 )
	{
		if( n % i == 0 )
		{
			return 0 ; 
		}
	}
	return 1 ; 
}
void jisuan( int tmp , int k , int  n , int sz2[])
{
	if( k >= n - 1 )
	{
		printf("%d\n", tmp );
		return ;
	}
	int i ; 
	for( i = 0 ; i < 4 ; i ++ )
	{
		int shu = tmp * 10  + sz2[i] ; 
		if( panduan( shu ))
		{
			jisuan( shu , k + 1 , n  , sz2 );
		}
	}
}
void shuchu( int sz1[] , int sz2[] , int n )
{
	int i , tmp ;
	for( i = 0 ; i < 4 ; i ++ )
	{
		tmp = sz1[i] ;
		if( n == 1 )
		{
			printf("%d", tmp );
		}
		else
		{
			jisuan( tmp , 0 , n , sz2 );
		}
	}
}
