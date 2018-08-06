/*问题描述
　　给定N个物品,每个物品有一个重量W和一个价值V.你有一个能装M重量的背包.问怎么装使得所装价值最大.
每个物品只有一个.
输入格式
　　输入的第一行包含两个整数n, m，分别表示物品的个数和背包能装重量。
　　以后N行每行两个数Wi和Vi,表示物品的重量和价值
输出格式
　　输出1行，包含一个整数，表示最大价值。
样例输入
3 5
2 3
3 5
4 7
样例输出
8
数据规模和约定
　　1<=N<=200,M<=5000.
*/
#include<stdio.h>
int sz[201][5001]={0};
int tongji( int , int );
int max( int , int );
int main( void )
{
	int n , m ;
	scanf("%d%d", &n , &m );
	printf("%d" ,tongji( n , m ));
	return 0 ; 
} 
int max( int a, int b )
{
	return a > b ? a : b ;
}
int tongji( int n , int  m )
{
	int i , j ; 
    for( i = 1 ; i <= n ; i ++ ) 
	{
	    int w, v;
	    scanf("%d%d" , &w , &v ) ;
	    for( j = 1 ; j <= m; j ++ ) 
		{
	        if (j >= w)
	        {
	        	sz[i][j] = max(sz[i-1][j] , sz[i-1][j-w] + v) ;
			}
	        else
	        {
	        	sz[i][j] = sz[i-1][j];
			}
   		 }
	}
	return sz[n][m] ;
}
