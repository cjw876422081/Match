/*
问题描述
　　同在一个高中，他却不敢去找她，虽然在别人看来，那是再简单不过的事。暗恋，是他唯一能做的事。
他只能在每天课间操的时候，望望她的位置，看看她倾心的动作，就够了。操场上的彩砖啊，
你们的位置，就是他们能够站立的地方，他俩的关系就像砖与砖之间一样固定，无法动摇。还记得当初铺砖的工人，
将整个操场按正方形铺砖（整个操场可视为R行C列的矩阵，矩阵的每个元素为一块正方形砖块），正方形砖块有两种，
一种为蓝色，另一种为红色。我们定义他和她之间的“爱情指标”为最大纯色正方形的面积，请你写一个程序求出“爱情指标”。
输入格式
　　第一行两个正整数R和C。
　　接下来R行C列描述整个操场，红色砖块用1来表示，蓝色砖块用0来表示。
输出格式
　　一个数，表示他和她之间的“爱情指标”。
样例输入
5 8
0 0 0 1 1 1 0 1
1 1 0 1 1 1 1 1
0 1 1 1 1 1 0 1
1 0 1 1 1 1 1 0
1 1 1 0 1 1 0 1
样例输出
9
数据规模和约定
　　40%的数据R,C<=10;
　　70%的数据R,C<=50;
　　100%的数据R,C<=200;
*/
#include<stdio.h>
int sz[200][200];
void shuru( int [][200] , int , int );
int tongji( int [][200] , int , int );
int panduan(int [][200] , int , int , int ) ;
int main( void )
{
	int n , m ; 
	scanf("%d%d",&n , &m);
	shuru( sz , n , m );
	printf("%d\n" , tongji( sz , n , m ));
	return 0 ; 
} 
int panduan(int sz[][200] , int x , int y , int k ) 
{
    int tmp = sz[x][y];
    int i , j ; 
    for( i = 0 ; i < k ; i ++)
	{
        for( j = 0 ; j < k ; j ++)
		{
            if(sz[ x + i ][ y + j ] != tmp )
			{
				return 0 ;	
			} 
        }
    }
    return 1 ;
}
int tongji( int sz[][200] , int n , int m )
{
	int i , j , k ; 
	int bian = 0 , max =  n > m ? n : m ;
	for( i = 0 ; i < n ; i ++) 
	{
        for( j = 0 ; j < m ; j ++) 
		{
            for( k = bian + 1 ; k < max ; k ++)
			{
				if( i + k <= n && j + k <= m ) 
				{
                    if( panduan( sz , i , j , k ) ) 
					{
						bian = k ;
					}
                }
                else 
				{
					break;
				}
			}
        }
    }
    return bian * bian ;
}
void shuru( int sz[][200] , int n , int m )
{
	int i , j ; 
	for( i = 0 ; i < n ; i ++ )
	{
		for( j = 0 ; j < m ; j ++ )
		{
			scanf("%d" ,& sz[i][j] );
		}
	}
}
