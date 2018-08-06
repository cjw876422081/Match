/*
棋盘多项式
问题描述
　　八皇后问题是在棋盘上放皇后，互相不攻击，求方案。变换一下棋子，
	还可以有八车问题，八马问题，八兵问题，八王问题，注意别念反。在这道题里，棋子换成车，
	同时棋盘也得换，确切说，是进行一些改造。比如现在有一张n*n的棋盘，
	我们在一些格子上抠几个洞，这些洞自然不能放棋子了，会漏下去的。另外，一个车本来能攻击和它的同行同列。
	现在，你想想，在攻击的过程中如果踩到一个洞，便会自取灭亡。故，车的攻击范围止于洞。
　　此题，给你棋盘的规模n，以及挖洞情况，求放k个车的方案数(k从0到最多可放车数)
输入格式
　　第一行一个整数n表示棋盘大小
　　接下来n行，每行n个用空格隔开的数字0或1，0的形状表示洞，1表示没有洞
输出格式
　　若干行，第i行表示放i个车的方案数
样例输入
3
1 0 1
1 1 1
1 0 1
样例输出
7
12
4 
数据规模和约定
　　n<=8
*/
#include <stdio.h>  

void shuru( int [][8] , int  );
void shuchu( int [][8] , int  );
void tongji();
int main( void ) 
{  
    int n , sz[8][8];  
    scanf( "%d", & n ) ;
    shuru( sz ,  n ) ;
    shuchu( sz , n ) ;
    return 0;  
}  
void tongji( )
{
	if( p_h < p_n )
	{
		if( qzs == fqs )
		{
			++ * p_gs;
			return ;
		} 
		int i ; 
		for( i = wx ; i < p_n ; i ++ )
		{
			if( sz[p_h][i] =)
		}
	}
}
void shuchu( int sz[][8] , int n )
{
	int i , gs;
	for( i = 0 ; i < n ; i ++ )
	{
		gs =  0;   
		tongji( );
		if( gs != 0 )
		{
			printf("%d\n", gs );
		}
	} 
}
void shuru( int sz[][8] , int n )
{
	int i , j ;
	for( i = 0 ; i < n ; i ++ )
	{  
        for( j = 0 ; j < n ; j ++ )
		{  
            scanf( "%d", &sz[i][j] );  
        }  
    }  
}
