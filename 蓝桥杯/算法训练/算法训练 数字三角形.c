/*
问题描述
　　（图３.１－１）示出了一个数字三角形。 请编一个程序计算从顶至底的某处的一条路
　　径，使该路径所经过的数字的总和最大。
　　●每一步可沿左斜线向下或右斜线向下走；
　　●1＜三角形行数≤100；
　　●三角形中的数字为整数0，1，…99；

　　.
　　（图３.１－１）
输入格式
　　文件中首先读到的是三角形的行数。

　　接下来描述整个三角形
输出格式
　　最大总和（整数）
样例输入
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
样例输出
30
*/ 
#include<stdio.h>
void shuru( int [][128] , int  );
int jisuan( int [][128] , int   );
int max( int , int );
int main( void )
{
	int hs; 
	scanf("%d",&hs);
	int sz[128][128]; 
	shuru( sz , hs );
	printf("%d\n",jisuan( sz, hs ));
	return 0 ; 
}
int max( int a, int b)
{
	return a > b ? a : b ; 
}
int jisuan( int sz[][128] , int  n )
{
	int i , j , sum = 0  ; 
	for(i = 1 ; i <= n ; i ++ )
	{
		for( j = 1 ; j <= i ; j ++ )
		{
			sz[i][j] += max(sz[i-1][j] , sz[i-1][j-1]);
			if( sum < sz[i][j] )
			{
				sum = sz[i][j];
			}  
		}
	}
	return sum ; 
}
void shuru( int sz[][128] , int n )
{
	int i , j ; 
	for(i = 1 ; i <= n ; i ++ )
	{
		for( j = 1 ; j <= i ; j ++ )
		{
			scanf("%d", &sz[i][j]);
		}
	}
	sz[0][0] = 0 ; 
	sz[0][1] = 0 ;
} 
