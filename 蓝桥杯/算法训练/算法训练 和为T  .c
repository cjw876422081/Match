/*
问题描述
　　从一个大小为n的整数集中选取一些元素，使得它们的和等于给定的值T。每个元素限选一次，不能一个都不选。
输入格式
　　第一行一个正整数n，表示整数集内元素的个数。
　　第二行n个整数，用空格隔开。
　　第三行一个整数T，表示要达到的和。
输出格式
　　输出有若干行，每行输出一组解，即所选取的数字，按照输入中的顺序排列。
　　若有多组解，优先输出不包含第n个整数的；若都包含或都不包含，优先输出不包含第n-1个整数的，依次类推。
　　最后一行输出总方案数。
样例输入
5
-7 -3 -2 5 9
0
样例输出
-3 -2 5
-7 -2 9
2
数据规模和约定
　　1<=n<=22
　　T<=maxlongint
　　集合中任意元素的和都不超过long的范围
*/
#if 1 
#include<stdio.h>
void Input( int , int [] ) ;
void Output( int [] , int ); 
void dfs( int [],int [], int , int , int , long long ,int * ) ; 
int main(void)
{
	int n ; 
	scanf("%d", & n  ); 
	int sz[30]={0} ; 
	Input( n , sz );
	long long t ; 
	scanf("%lld" , & t );
	int count = 0 , num[30]={0} ; ; 
	dfs( sz ,num ,n - 1 , 0 , 0 ,  t , &count) ; 
	printf("%d\n" , count) ; 
	return 0 ; 
}
void dfs( int sz[] , int num[] ,int tmp1, int tmp2, int sum ,long long  t ,int *count)
{
	if( tmp1 < 0 )
	{
		return ; 
	}
	dfs( sz ,num ,tmp1 -1 , tmp2 , sum , t , count) ; 
	
	num[tmp2] = sz[tmp1] ; 
	sum += num[tmp2] ;
	if( sum == t)
	{
		++ *count ; 
		Output( num ,tmp2 );
	} 	
	dfs( sz , num , tmp1 -1 , tmp2 + 1 , sum , t , count) ;
}
void Output( int sz[] , int n )
{
	int i ; 
	for( i = n ; i >= 0 ; i -- )
	{
		printf("%d%c" , sz[i] , i == 0 ? '\n':' ') ; 
	}
}
void Input( int n , int sz[] )
{
	int i ; 
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d" , & sz[i] );
	}
} 
#endif
