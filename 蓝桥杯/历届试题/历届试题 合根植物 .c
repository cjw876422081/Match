/*
问题描述
　　w星球的一个种植园，被分成 m * n 个小格子（东西方向m行，南北方向n列）。每个格子里种了一株合根植物。
　　这种植物有个特点，它的根可能会沿着南北或东西方向伸展，从而与另一个格子的植物合成为一体。


　　如果我们告诉你哪些小格子间出现了连根现象，你能说出这个园中一共有多少株合根植物吗？
输入格式
　　第一行，两个整数m，n，用空格分开，表示格子的行数、列数（1<m,n<1000）。
　　接下来一行，一个整数k，表示下面还有k行数据(0<k<100000)
　　接下来k行，第行两个整数a，b，表示编号为a的小格子和编号为b的小格子合根了。
　　格子的编号一行一行，从上到下，从左到右编号。
　　比如：5 * 4 的小格子，编号：
　　1 2 3 4
　　5 6 7 8
　　9 10 11 12
　　13 14 15 16
　　17 18 19 20
样例输入
5 4
16
2 3
1 5
5 9
4 8
7 8
9 10
10 11
11 12
10 14
12 16
14 18
17 18
15 19
19 20
9 13
13 17
样例输出
5
样例说明
　　其合根情况参考下图
*/
#include<stdio.h>
void Input( int ,int , int , int [] ) ; 
void union_find( int , int , int [] ) ; 
void Output( int , int , int [] ) ;
int find( int , int []) ; 
int main(void)
{
	int m , n , k ; 
	scanf("%d%d%d" , & m , & n , & k ) ;
	static int sz[1000001] ;  
	Input( m , n  , k  , sz ) ; 
	Output( m , n , sz ) ; 
	return 0 ; 
}
void Output( int m , int n, int sz[] )
{
	int i , sum = 0 ;
	for( i = 0 ; i < m * n ; i ++ )
	{
		if( sz[i] == i )
		{
			sum ++ ; 
		}
	}
	printf("%d\n" , sum ) ; 
}
int find( int s, int sz[])
{
	while( s != sz[s] )
	{
		s = sz[s] ; 
	}
}
void Input( int m , int n , int k , int sz[] )
{
	int i , x , y ;
	for( i = 0 ; i < m *n ; i ++ )
	{
		sz[i] = i  ; 
	}
	for( i = 0 ;  i < k ; i ++ )
	{
		scanf("%d%d" , & x , & y ) ; 
		union_find( --x , --y , sz ) ; 
	}
}
void union_find( int x , int y , int sz[] )
{
	x = find( x , sz );
	y = find( y , sz );
	if( x != y )
	{
		sz[x] = y ; 
	}
}
