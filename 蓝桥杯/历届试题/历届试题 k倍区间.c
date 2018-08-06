/*问题描述
　　给定一个长度为N的数列，A1, A2, ... AN，如果其中一段连续的子序列Ai,
	 Ai+1, ... Aj(i <= j)之和是K的倍数，我们就称这个区间[i, j]是K倍区间。
　你能求出数列中总共有多少个K倍区间吗？
输入格式
　　第一行包含两个整数N和K。(1 <= N, K <= 100000)
　　以下N行每行包含一个整数Ai。(1 <= Ai <= 100000)
输出格式
　　输出一个整数，代表K倍区间的数目。
样例输入
5 2
1
2
3
4
5
样例输出
6*/
#if 1
#include<stdio.h>
void Input( long long [] , int ) ; 
void Output( long long [] , long long [], int , int);
int main(void)
{
	int n , k ;
	scanf("%d%d", &n , & k ) ; 
	long long sz[100002] = { 0 } ;
	long long bk[100002] = { 0 } ; // 对于任意一段区间[l,r]的和就是sum[r]-sum[l-1] 
	Input( sz , n ) ;
	Output( sz , bk , n  , k ) ; 
	return 0 ; 
}
void Output( long long sz[] , long long bk[] , int n , int k )
{
	sz[0] %= k ; 
	long long sum = 0 , i ; 
	for(  i = 0 ; i < n ; i ++ )
	{
		sz[i] = (sz[i] + sz[i-1]) % k ; 
	}
	for(  i = 0 ; i < n ; i ++ )
	{
		sum += bk[sz[i]]++ ;  
	}
	printf("%lld\n" , sum + bk[0] ) ; 
}
void Input( long long sz[] , int n)
{
	int i ; 
	for( i = 0 ; i < n ; i ++  )
	{
		scanf("%d" , &sz[i] ) ;
	}
}
#endif
