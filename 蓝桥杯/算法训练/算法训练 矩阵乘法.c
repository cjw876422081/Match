/*
问题描述
　　输入两个矩阵，分别是m*s，s*n大小。输出两个矩阵相乘的结果。
输入格式
　　第一行，空格隔开的三个正整数m,s,n（均不超过200）。
　　接下来m行，每行s个空格隔开的整数，表示矩阵A（i，j）。
　　接下来s行，每行n个空格隔开的整数，表示矩阵B（i，j）。
输出格式
　　m行，每行n个空格隔开的整数，输出相乘後的矩阵C（i，j）的值。
样例输入
2 3 2
1 0 -1  
1 1 -3
0 3
1 2 
3 1
样例输出
-3 2
-8 2

5 2 10
7 3
9 3
3 9
9 6
9 4
9 5 2 8 7 0 1 5 6 3
1 9 9 4 4 3 9 1 8 1

提示
矩阵C应该是m行n列，其中C(i,j)等于矩阵A第i行行向量与矩阵B第j列列向量的内积。
例如样例中C(1,1)=(1,0,-1)*(0,1,3) = 1 * 0 +0*1+(-1)*3=-3
*/
#include<stdio.h>
void shuru( int m , int s , int n, int [][s] ,int [][n] );
void jisuan( int m , int s , int n, int [][s] ,int [][n] , int [][n] );
void shuchu( int m , int n  , int [][n]);
int main( void )
{
	int m , s , n ;
	scanf("%d%d%d" , &m , &s , &n);
	int jz1[m][s] , jz2[s][n];
	int c[m][n]; 
	shuru(  m , s , n , jz1 , jz2  );
	jisuan( m , s , n , jz1 , jz2 , c );
	shuchu( m , n , c );
	return 0 ; 
}
void jisuan( int m , int s , int n, int jz1[][s] ,int jz2[][n] , int c[][n] )
{
	int i , j , k ; 
    for( i = 0 ; i < m ; i ++)  
    {  
        for( j = 0 ; j < n ; j ++)  
        {  
        	c[i][j] = 0 ; 
            for( k = 0 ; k < s ; k ++)  
            {  
                c[i][j] += jz1[i][k] * jz2[k][j];  
            }  
        }  
    }  
}
void shuchu( int m , int n  , int c[][n])
{
	int i , j ; 
	for( i = 0 ; i < m ; i ++ )
	{
		for( j = 0 ; j < n ; j ++ )
		{
			printf("%d ", c[i][j]);
		}
		putchar('\n');
	}
}
void shuru( int m , int s , int n, int jz1[][s] ,int jz2[][n] )
{
	int i , j ; 
	for( i = 0 ; i < m ; i ++ )
	{
		for( j = 0 ; j < s ; j ++ )
		{
			scanf("%d", &jz1[i][j]);
		}
	}
	for( i = 0 ; i < s ; i ++ )
	{
		for( j = 0 ; j < n ; j ++ )
		{
			scanf("%d", &jz2[i][j]);
		}
	}
}
