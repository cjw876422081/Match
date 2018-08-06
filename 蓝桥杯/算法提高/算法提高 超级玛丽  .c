/*
问题描述
　　大家都知道"超级玛丽"是一个很善于跳跃的探险家，他的拿手好戏是跳跃，但它一次只能向前跳一步或两步。
有一次，他要经过一条长为n的羊肠小道，小道中有m个陷阱，
这些陷阱都位于整数位置，分别是a1,a2,....am，陷入其中则必死无疑。显然，如果有两个挨着的陷阱，则玛丽是无论如何也跳过不去的。
　　现在给出小道的长度n，陷阱的个数及位置。求出玛丽从位置1开始，有多少种跳跃方法能到达胜利的彼岸（到达位置n）。
输入格式
　　第一行为两个整数n,m
　　第二行为m个整数，表示陷阱的位置
输出格式
　　一个整数。表示玛丽跳到n的方案数
样例输入
4 1
2
样例输出
1
数据规模和约定
　　40>=n>=3,m>=1
　　n>m;
　　陷阱不会位于1及n上
*/
#include<stdio.h>
void shuru( int [] , int );
int tfs( int [] , int  , int );
int main( void )
{
	int n , m ;
	int sz[40] = {0};
	scanf("%d%d" , & n , & m );
	shuru( sz , m );
	printf("%d\n" , tfs( sz , n , 1 ));
	return 0 ; 
} 
int tfs( int sz[] , int n , int  i )
{
	if( i == n )
	{
		return 1 ; 
	}
	if( sz[i] == 1 || i > n )
	{
		return 0 ; 
	}
	return tfs( sz , n , i + 1) + tfs( sz , n , i + 2) ;
}
void shuru( int sz[] , int  n)
{
	int i ; 
	for( i = 1 ; i <= n ; i ++ )
	{
		int xj ; 
		scanf("%d" ,&xj); 
		sz[xj] = 1 ;
	}
	
}
