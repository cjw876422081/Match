/*
问题描述
　　在一条直线上有n堆石子，每堆有一定的数量，每次可以将两堆相邻的石子合并，合并后放在两堆的中间位置，合并的费用为两堆石子的总数。求把所有石子合并成一堆的最小花费。
输入格式
　　输入第一行包含一个整数n，表示石子的堆数。
　　接下来一行，包含n个整数，按顺序给出每堆石子的大小 。
输出格式
　　输出一个整数，表示合并的最小花费。
样例输入
5
1 2 3 4 5
样例输出
33
数据规模和约定
　　1<=n<=1000, 每堆石子至少1颗，最多10000颗。
*/
#include<stdio.h>

#define min(a,b) (a<b?a:b)
#define N (1005) 
#define INF ( 1<<30)
void shuru( int, int sz[]);
int min_price( int , int sz[] );
void cs_dp( int , int dp[N][N]);
int miv( int , int );
int main( void )
{
	int  n ; 
	scanf("%d" ,& n ) ;
	int sz[N] ; 
	shuru( n , sz );
	printf("%d\n" , min_price( n , sz ));
	return 0 ; 
}

int min_price( int n , int sz[] )
{
	int i , j , k ;
	static int dp[N][N] ={0};
	static int sum[N][N] ={0};  
	for( i = 0 ; i < n ; i ++ )
	{	                                  
		sum[i][i] = sz[i];
	}
	for( i = 0 ; i < n ;  i ++ )
	{	                               
		for( j = i + 1 ; j < n ;  j ++ )
		{
			sum[i][j] = sum[i][j-1] + sz[j];
		}
	}
	for( i = 0 ; i < n ; i ++ )
	{
		dp[i][i+1] = sum[i][i+1]; 
	} 
	for( i = 3 ; i <= n ; ++ i )//区间 
	{
		for( j = 0 ; j <= n - i  ; ++ j )//个数 
		{
			int end = i + j - 1 ; 
			int m_price = INF ;
			for( k = j ; k < end ; ++ k )
			{
				int tmp = dp[j][k] + dp[k+1][end] ;
				m_price = min( tmp , m_price ) ;
			}
			dp[j][end] = m_price + sum[j][end] ; 
		}
	}
	return dp[0][n-1] ; 
}

void shuru( int n , int sz[N])
{
	int i  ; 
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d" ,&sz[i] );
	}	
}
