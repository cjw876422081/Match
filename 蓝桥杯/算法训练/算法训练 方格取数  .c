/*问题描述
　　设有N*N的方格图(N<=10),我们将其中的某些方格中填入正整数,而其他的方格中则放入数字0。
　　某人从图的左上角的A 点(1,1)出发，可以向下行走，也可以向右走，直到到达右下角的B点(N,N)。在走过的路上，他可以取走方格中的数（取走后的方格中将变为数字0）。
　　此人从A点到B 点共走两次，试找出2条这样的路径，使得取得的数之和为最大。
输入格式
　　输入的第一行为一个整数N（表示N*N的方格图），接下来的每行有三个整数，前两个表示位置，第三个数为该位置上所放的数。
一行单独的0表示输入结束。
输出格式
　　只需输出一个整数，表示2条路径上取得的最大的和。
样例输入
8
2 3 13
2 6 6
3 5 7
4 4 14
5 2 21
5 6 4
6 3 15
7 2 14
0 0 0
样例输出
　　67
*/


#include<stdio.h>

void input( int n , int sz[n+1][n+1]   );
int max_he(int n , int sz[n+1][n+1]  );
int  max( int a , int b );
void csh_dp( int n ,int dp[n+1][n+1][n+1][n+1] ) ;
void csh_sz( int n , int sz[n+1][n+1]   );
int main( void )
{
	int n ; 
	scanf("%d", &n );
	int sz[n+1][n+1];
	input(n , sz);
	printf("%d\n" , max_he(  n , sz )) ; 
	return  0 ; 
}
void csh_sz( int n , int sz[n+1][n+1]   )
{
	int i , j ; 
	for( i = 0 ; i <= n  ; i ++ )
	{
		for( j = 0 ; j <= n ; j ++ )
		{
			sz[i][j] = 0 ; 
		}
	}
}
void csh_dp( int n ,int dp[n+1][n+1][n+1][n+1] )
{
	int i , j ,  h , k ;
	for(i = 0 ;i <= n ; i ++ )  
    {  
        for( j = 0 ;j <= n ;j ++)  
        {  
            for( h = 0 ; h <= n ; h ++ )  
            {  
                for( k = 0 ; k <= n ; k ++)  
                {  
 					dp[i][j][h][k] = 0 ;
                }  
            }  
        }  
    }  
}
int  max( int a , int b )
{
	return a > b ? a : b ; 
}
int max_he(int n , int sz[n+1][n+1]  )
{ 
	int i , j ,  h , k ;
	int dp[n+1][n+1][n+1][n+1]; 
	csh_dp( n , dp ) ;
    for( i = 1 ;i <= n ; i ++ )  
    {  
        for( j = 1 ; j <= n ; j ++)  
        {  
            for( h = 1 ; h <= n ; h ++)  
            {  
                for( k = 1 ; k <= n ; k ++ )  
                {  
                    int tmp1 = max(dp[i-1][j][h-1][k],dp[i][j-1][h][k-1]);
                    int tmp2 = max(dp[i][j-1][h-1][k],dp[i-1][j][h][k-1]);
                    dp[i][j][h][k] = max(tmp1,tmp2) + sz[i][j];  
                    if(i != h && j != k)
					{
						dp[i][j][h][k] += sz[h][k]; 	
					} 
                }  
            }  
        }  
    }  
    return dp[n][n][n][n];
}

void input( int n , int sz[n+1][n+1]  )
{
	int i , j ; 	
	csh_sz( n , sz );
	while( n -- >= 0 )
	{
		int s;
		scanf("%d%d%d" , & i , & j , & s ) ; 
		if( i == 0 && j == 0 && s == 0 )
		{
			break ; 
		}
		sz[i][j] = s ; 
	} 
}

