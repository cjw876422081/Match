/*
问题描述
　　有一个箱子容量为V（正整数，0＜＝V＜＝20000），同时有n个物品（0＜n＜＝30），每个物品有一个体积（正整数）。
　　要求n个物品中，任取若干个装入箱内，使箱子的剩余空间为最小。
输入格式
　　第一行为一个整数，表示箱子容量；
　　第二行为一个整数，表示有n个物品；
　　接下来n行，每行一个整数表示这n个物品的各自体积。
输出格式
　　一个整数，表示箱子剩余空间。
　　样例输入
24
6
8
3
12
7
9
7
样例输出


*/
#include<stdio.h>
int q_min( int , int );
int max( int , int );
int main( void )
{
	int v , n ; 
	scanf("%d%d" , &v , &n );
	printf("%d" ,q_min( v , n  ));	
	return 0 ; 
}
int max( int a, int  b)
{
	return a > b ? a : b ;  
}
int q_min( int v , int n )
{
	int i , j , sz[30] = { 0 } , dp[20000] = { 0 }; 
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d" ,&sz[i] );
		for( j = v ; j >= sz[i] ; j -- )
		{
			dp[j] = max( dp[j] , dp[j - sz[i]] + sz[i]);
		}
	}
	return v - dp[v-1] ; 
}
