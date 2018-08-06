/*
问题描述
　　对于给定整数数组a[],寻找其中最大值，并返回下标。
输入格式
　　整数数组a[],数组元素个数小于1等于100。输出数据分作两行：第一行只有一个数，表示数组元素个数；第二行为数组的各个元素。
输出格式
　　输出最大值，及其下标
样例输入
3
3 2 1
样例输出
3 0
*/
#include<stdio.h>
void shuru( int [] , int );
void shuchu( int [] , int );
int main(void)
{
	int sz[128];
	int n ; 
	scanf("%d", &n );
	shuru( sz , n );
	shuchu( sz , n );
	return 0 ; 
} 
void shuchu( int sz[] , int n)
{
	int i , max = sz[0] , xb = 0 ;
	for( i = 0 ; i < n ; i ++ )
	{
		if( max <  sz[i])
		{
			max = sz[i];
			xb = i ;
		}
	}
	printf("%d %d\n" , max , xb );
}
void shuru( int sz[] , int n)
{
	int i ;
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d", &sz[i]);
	}
}
