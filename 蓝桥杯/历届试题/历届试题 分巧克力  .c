/*问题描述
　　儿童节那天有K位小朋友到小明家做客。小明拿出了珍藏的巧克力招待小朋友们。
　　小明一共有N块巧克力，其中第i块是Hi x Wi的方格组成的长方形。
　　为了公平起见，小明需要从这 N 块巧克力中切出K块巧克力分给小朋友们。切出的巧克力需要满足：
　　1. 形状是正方形，边长是整数
　　2. 大小相同
　　例如一块6x5的巧克力可以切出6块2x2的巧克力或者2块3x3的巧克力。
　　当然小朋友们都希望得到的巧克力尽可能大，你能帮小Hi计算出最大的边长是多少么？
输入格式
　　第一行包含两个整数N和K。(1 <= N, K <= 100000)
　　以下N行每行包含两个整数Hi和Wi。(1 <= Hi, Wi <= 100000)
　　输入保证每位小朋友至少能获得一块1x1的巧克力。
输出格式
　　输出切出的正方形巧克力最大可能的边长。
样例输入
2 10
6 5
5 6
样例输出
2
数据规模和约定
　　峰值内存消耗（含虚拟机） < 256M
　　CPU消耗 < 1000ms
*/
#include<stdio.h>
void input(  int n  , int [][2]);
int jisuan(  int n  , int [][2] , int );
long long  cakes( int , int [][2] , int );
int max( int , int );
int main( void )
{
	int n , k ; 
	scanf("%d%d" ,&n , &k );
	int cake[n][2] ;
	input( n , cake ) ;
	printf("%d" , jisuan( n , cake , k ));
	return 0 ; 
}
int  max( int a , int b )
{
	return a > b ? a : b ;
}
long long  cakes( int bc , int sz[][2] , int n )
{
	int i ;
	long long  sum = 0 ; 
	for( i = 0 ; i < n ; i ++ )
	{
		sum += (sz[i][0]/bc)*(sz[i][1]/bc);
	}
	return sum ; 
}
int jisuan(  int n  , int sz[][2] , int k )
{
	int left  = 1 , right = 100000 , mid , ans = 0 ;
	while( left < right - 1 )
	{
		mid = ( left + right ) / 2 ; 
		if( k > cakes( mid , sz , n ))
		{
			right = mid ; 
		} 
		else
		{
			left = mid ; 
			ans = max( ans , mid );
		}
	}
	return ans ; 

}
void input(  int n  , int sz[][2])
{
	int i ;
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d%d" ,&sz[i][0] , &sz[i][1]);
	}
}
