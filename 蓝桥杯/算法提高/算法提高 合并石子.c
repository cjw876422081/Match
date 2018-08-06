/*
��������
������һ��ֱ������n��ʯ�ӣ�ÿ����һ����������ÿ�ο��Խ��������ڵ�ʯ�Ӻϲ����ϲ���������ѵ��м�λ�ã��ϲ��ķ���Ϊ����ʯ�ӵ��������������ʯ�Ӻϲ���һ�ѵ���С���ѡ�
�����ʽ
���������һ�а���һ������n����ʾʯ�ӵĶ�����
����������һ�У�����n����������˳�����ÿ��ʯ�ӵĴ�С ��
�����ʽ
�������һ����������ʾ�ϲ�����С���ѡ�
��������
5
1 2 3 4 5
�������
33
���ݹ�ģ��Լ��
����1<=n<=1000, ÿ��ʯ������1�ţ����10000�š�
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
	for( i = 3 ; i <= n ; ++ i )//���� 
	{
		for( j = 0 ; j <= n - i  ; ++ j )//���� 
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
