/*
问题描述
　　扫雷游戏你一定玩过吧！现在给你若干个n×m的地雷阵，请你计算出每个矩阵中每个单元格相邻单元格内地雷的个数，每个单元格最多有8个相邻的单元格。
``` 0<n,m<=100
输入格式
　　输入包含若干个矩阵，对于每个矩阵，第一行包含两个整数n和m，分别表示这个矩阵的行数和列数。
	接下来n行每行包含m个字符。安全区域用‘.’表示，有地雷区域用'*'表示。当n=m=0时输入结束。
输出格式
　　对于第i个矩阵，首先在单独的一行里打印序号：“Field #i:”,接下来的n行中，读入的'.'应被该位置周围的地雷数所代替。
输出的每两个矩阵必须用一个空行隔开。
样例输入
4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0
样例输出
Field #1:
*100
2210
1*10
1110

Field #2:
**100
33200
1*100
（注意两个矩阵之间应该有一个空行，由于oj的格式化这里不能显示出来）
数据规模和约定
　　0<n,m<=100


*/
#include<stdio.h>
void shuru( char [][101] , int , int );
void shuchu( char [][101] , int , int , int );
int q_zwls( char [][101] , int , int , int , int );
int main( void )
{
	int gs = 0 ; 
	while( 1 )
	{
		int n , m  ; 
		char lq[101][101] ; 
		scanf("%d%d" ,& n , & m );
		if( n == 0 && m == 0 )
		{
			break ; 
		}
		gs ++ ;
		shuru( lq , n , m );
		shuchu( lq , n  , m , gs );
	}
	return 0 ; 
}
int q_zwls( char lq[][101] , int h , int  l, int n , int m)
{
	int i , j , sum = 0 ;
	for( i = h - 1 ; i <= h + 1 ; i ++ )
	{
		for( j = l- 1 ; j <= l + 1 ; j ++ )
		{
			if( i >= 0 && i < n && j >= 0  && j < m )
			{
				if( lq[i][j] == '*')
				{
					sum ++ ; 
				}
			}
		}
	}
	return sum ; 
}
void shuchu( char lq[][101] , int n , int m , int gs )
{
	int i , j ; 
	printf("Field #%d:\n" , gs ); 
	for( i = 0 ; i < n ; i ++ )
	{
		for( j = 0 ; j < m ; j ++ )
		{
			if( lq[i][j] == '*')
			{
				printf("%c", lq[i][j]);
			}
			else
			{
				printf("%d", q_zwls( lq , i , j , n , m ));
			}
			
		}
		putchar('\n');
	}
	putchar('\n');
}
void shuru( char lq[][101] , int n , int m )
{
	int i , j ;
	for( i = 0 ; i < n ; i ++ )
	{
		getchar();
		for( j = 0 ; j < m ; j ++ )
		{
			scanf("%c", &lq[i][j]);
		}
	}
}
