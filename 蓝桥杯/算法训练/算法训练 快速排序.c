/*
问题描述
　　快速排序是最经常使用的一种排序方式，对于给定的n个数组成的一个数组，请使用快速排序对其进行排序。
　　现给定一序列，请用快速排序将其按升序排序并输出。
输入格式
　　第一行一个数N。
　　第2~N+1行每行一个数，表示给定序列。
输出格式
　　共N行，每行一个数，表示所求序列。
样例输入
5
1
4
2
3
4
样例输出
1
2
3
4
4
数据规模和约定
　　共10组数据。
　　对100%的数据，N<=10^5，所有数均为非负数且在int范围内。
*/

#include<stdio.h>
void Input( int [] , int  ); 
void Output( int [] , int );
void qsort( int [] , int , int );
int main(void)
{
	int n ; 
	scanf("%d" , & n ) ; 
	int sz[n]; 
	Input( sz , n );
	qsort( sz , 0 , n - 1 );
	Output( sz , n ); 
	return 0 ; 
}
void qsort( int sz[] , int left , int  right)
{
	if( left >= right )
	{
		return ; 
	}
	int i = left ; 
	int j = right ; 
	int key = sz[left] ;
	while( i < j )
	{
		while( i < j && key <= sz[j])
		{
			j -- ; 
		}
		sz[i] = sz[j] ; 
		while( i < j && key >= sz[i])
		{
			i ++ ; 
		}
		sz[j] = sz[i] ; 
	} 
	sz[i] = key ; 
	qsort( sz , left , i - 1 );
	qsort( sz , i + 1 , right);

	
}
void Output( int sz[] , int n )
{
	int i;
	for( i = 0 ; i < n ; i ++ )
	{
		printf("%d\n", sz[i]); 
	}
	
}
void Input( int sz[] , int n )
{
	int i ; 
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d", & sz[i] );
	}
}

