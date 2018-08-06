/*��������
��������N*N�ķ���ͼ(N<=10),���ǽ����е�ĳЩ����������������,�������ķ��������������0��
����ĳ�˴�ͼ�����Ͻǵ�A ��(1,1)�����������������ߣ�Ҳ���������ߣ�ֱ���������½ǵ�B��(N,N)�����߹���·�ϣ�������ȡ�߷����е�����ȡ�ߺ�ķ����н���Ϊ����0����
�������˴�A�㵽B �㹲�����Σ����ҳ�2��������·����ʹ��ȡ�õ���֮��Ϊ���
�����ʽ
��������ĵ�һ��Ϊһ������N����ʾN*N�ķ���ͼ������������ÿ��������������ǰ������ʾλ�ã���������Ϊ��λ�������ŵ�����
һ�е�����0��ʾ���������
�����ʽ
����ֻ�����һ����������ʾ2��·����ȡ�õ����ĺ͡�
��������
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
�������
����67
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

