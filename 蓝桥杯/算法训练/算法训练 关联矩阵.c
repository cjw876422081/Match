/*

问题描述
　　有一个n个结点m条边的有向图，请输出他的关联矩阵。
输入格式
　　第一行两个整数n、m，表示图中结点和边的数目。n<=100,m<=1000。
　　接下来m行，每行两个整数a、b，表示图中有(a,b)边。
　　注意图中可能含有重边，但不会有自环。
输出格式
　　输出该图的关联矩阵，注意请勿改变边和结点的顺序。
样例输入
5 9
1 2 
3 1 
1 5
2 5
2 3
2 3
3 2
4 3
5 4
样例输出
1 -1 1 0 0 0 0 0 0  
-1 0 0 1 1 1 -1 0 0
0 1 0 0 -1 -1 1 -1 0
0 0 0 0 0 0 0 1 -1
0 0 -1 -1 0 0 0 0 1

*/
#include<stdio.h>
void shuru( int n , int m , int [][m]);
void shuchu( int n , int m , int [][m]);
int main( void )
{
	int n , m ;
	scanf("%d%d",&n, &m);
	int jz[n][m];
	shuru(n , m , jz );
	shuchu( n , m , jz );
	return 0 ; 
}
void shuru( int n , int m , int jz[][m])
{
	int i , j ;
	int s1 , s2 ;
	for( i = 0 ; i < m ; i ++)
	{
		scanf("%d%d", &s1 , &s2);
		for( j = 0 ; j < n ; j ++ )
		{
			if( j == s1 - 1)
			{
				jz[j][i] = 1 ;
			}
			else
			{
				if(j == s2 - 1 )
				{
					jz[j][i] = - 1 ;
				}
				else
				{
					jz[j][i] = 0;
				}
			}
		}
	
	}
}
void shuchu( int n , int m , int jz[][m])
{
	int i , j ;
	for( i = 0 ; i < n ; i ++)
	{
		for( j = 0 ; j < m ; j ++ )
		{
			printf("%d ",jz[i][j]);
		}
		putchar('\n'); 
	}
}
