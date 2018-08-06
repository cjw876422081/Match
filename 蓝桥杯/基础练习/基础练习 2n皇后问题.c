/*
基础练习 2n皇后问题
问题描述
　　给定一个n*n的棋盘，棋盘中有一些位置不能放皇后。现在要向棋盘中放入n个黑皇后
和n个白皇后，使任意的两个黑皇后都不在同一行、同一列或同一条对角线上，任意的两
个白皇后都不在同一行、同一列或同一条对角线上。问总共有多少种放法？n小于等于8。
输入格式
　　输入的第一行为一个整数n，表示棋盘的大小。
　　接下来n行，每行n个0或1的整数，如果一个整数为1，表示对应的位置可以放皇后，
如果一个整数为0，表示对应的位置不可以放皇后。
输出格式
　　输出一个整数，表示总共有多少种放法。
样例输入
4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
样例输出
2
样例输入
4
1 0 1 1
1 1 1 1
1 1 1 1
1 1 1 1
样例输出
0
*/
#include<stdio.h>
int tongji(int  , int  , int [][8] , int ,int *);
int check(int , int  ,int ,int [][8] , int );
void shuru( int , int [][8]);

int main(void)
{
    int n ,sz[8][8];
    scanf("%d",&n);
    shuru( n , sz );
    int sum=0;
    printf("%d",tongji(n , 0 , sz , 2  ,&sum));
    return 0;
}
int tongji(int n , int x , int sz[][8] , int s ,int *sum)
{
    
    if( x == n )
    {
        if( s == 2 )
		{
			tongji(n , 0, sz, 3 , sum );
		}
        else 
		{
			++ *sum ;
		}
        return 0;
    }
    int i ;
    for(i = 0 ; i < n ; i ++)
    {
        if(sz[x][i] != 1)
		{
			continue;
		}
        if(check(n , x , i , sz , s ))
		{
			sz[x][i]=s;
		}
        else 
		{
			continue;	
		}
        tongji(n , x+1 , sz , s ,sum );
        sz[x][i]=1;
    }
    return * sum;
} 
int check(int  n , int x ,int y ,int sz[][8] , int s)
{
    int i , j;
    for( i = x-1 ; i >= 0 ; i --)
    {
        if(sz[i][y] == s)
		{
			return 0;
		}
    }
    for(i=x-1,j = y-1 ; i >= 0 && j >= 0; i -- , j --)
    {
        if(sz[i][j] == s)
		{
			return 0;
		}
    }
    for(i = x-1,j = y+1;i >= 0 && j < n ; i -- , j ++)
    {
        if( sz[i][j]== s)
        {
        	return 0;
		}
    }
    return 1;
}
void shuru( int  n , int sz[][8])
{
	int i , j ;
	for( i = 0 ; i < n ; i ++)
    {
        for( j = 0 ; j < n ; j ++)
        {
            scanf("%d",&sz[i][j]);
        }
    }
}
