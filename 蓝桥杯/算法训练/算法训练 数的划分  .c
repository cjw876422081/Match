/*
问题描述
　　将整数n分成k份，且每份不能为空，任意两份不能相同(不考虑顺序)。
　　例如：n=7，k=3，下面三种分法被认为是相同的。
　　1，1，5; 1，5，1; 5，1，1;
　　问有多少种不同的分法。
输入格式
　　n，k
输出格式
　　一个整数，即不同的分法
样例输入
7 3
样例输出
4 {四种分法为：1，1，5;1，2，4;1，3，3;2，2，3;}
数据规模和约定
　　6<n<=200，2<=k<=6
*/
#include<stdio.h>
int tongji( int [][7] , int , int );
int main( void )
{
	int n , k ;
	scanf("%d%d" ,& n , & k ) ; 
	int sz[201][7]={0};
	printf("%d", tongji( sz , n , k )) ;  
	return 0 ; 
}
int tongji( int sz[][7] , int n , int k)
{
	int i , j ;
	sz[0][0] = 1;
    for( i = 1;i <= n ; i ++ )
	{
		sz[i][1] = 1 ;
	} 
    for( i = 1 ; i <= n ; i ++ )
    {
        for( j = 1 ; j <= k ; j ++ )
        {
            if(i >= j)
			{
				sz[i][j] = sz[i-j][j] +sz[i-1][j-1];
			} 
        }
    }		
    return sz[n][k];
}
    

