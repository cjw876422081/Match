/*
问题描述
如下图所示，3 x 3 的格子中填写了一些整数。
+--*--+--+
|10* 1|52|
+--****--+
|20|30* 1|
*******--+
| 1| 2| 3|
+--+--+--+
我们沿着图中的星号线剪开，得到两个部分，每个部分的数字和都是60。
本题的要求就是请你编程判定：对给定的m x n 的格子中的整数，是否可以分割为两个部分，使得这两个区域的数字和相等。
如果存在多种解答，请输出包含左上角格子的那个区域包含的格子的最小数目。
如果无法分割，则输出 0。
输入格式
程序先读入两个整数 m n 用空格分割 (m,n<10)。
表示表格的宽度和高度。
接下来是n行，每行m个正整数，用空格分开。每个整数不大于10000。
输出格式
输出一个整数，表示在所有解中，包含左上角的分割区可能包含的最小的格子数目。
样例输入1
3 3
10 1 52
20 30 1
1 2 3
样例输出1
3
样例输入2
4 3
1 1 1 1
1 30 80 2
1 1 1 100
样例输出2
10
*/
#if 1
#include<stdio.h>
void shuru( int , int m, int sz[][m] , int * );
void q_gs( int , int , int , int m ,int [][11] , int sz[][m] , int , int * , int );
int main( void )
{
	int n , m , sum = 0 ;
	scanf("%d%d", &m , &n );
	int sz[n][m]; 
	shuru( n , m , sz , &sum );
	int bj[11][11] = {0};
		bj[0][0] = 1 ;

	int gs = 100 ; 

	q_gs( 0 , 0 , n , m , bj , sz , sum/2 - sz[0][0] , &gs , 1 );
	printf("%d\n" , gs );

	return 0 ; 
}
void q_gs( int x , int y, int  n, int m ,int bj[][11] , int sz[][m] , int sum , int *gs , int bs )
{
	static int fx[4][2] = { {-1 , 0 } , { 1 , 0 } , { 0 , -1 } , { 0 , 1} };
//	printf("sum = %d number = %d \n" , sum ,  number );
	if( sum == 0 )
	{
		* gs = *gs < bs ? *gs : bs ; 
		return ; 
	}
	int i ; 
	for( i = 0 ; i < 4 ; i ++ )
	{
		int tmpx = fx[i][0] + x ; 
		int tmpy = fx[i][1] + y ;
		if( tmpx >= 0 && tmpy >= 0 && tmpx < n && tmpy < m && bj[tmpx][tmpy] == 0 )
		{
			bj[tmpx][tmpy] = 1 ;
			
			q_gs( tmpx , tmpy , n , m , bj , sz , sum - sz[tmpx][tmpy] , gs , bs + 1 ) ;
			bj[tmpx][tmpy] = 0 ; 
		}
	}
}
void shuru( int n , int m , int sz[][m] , int *sum )
{
	int i , j ;
	for( i = 0 ; i < n ; i ++ )
	{
		for( j = 0 ; j < m ; j ++ )
		{
			scanf("%d", &sz[i][j]);
			(*sum) +=sz[i][j] ;  
		}
	}
}
#endif 
