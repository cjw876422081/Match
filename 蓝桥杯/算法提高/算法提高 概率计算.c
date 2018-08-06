/*
问题描述
　　生成n个∈[a,b]的随机整数，输出它们的和为x的概率。
输入格式
　　一行输入四个整数依次为n，a，b，x，用空格分隔。
输出格式
　　输出一行包含一个小数位和为x的概率，小数点后保留四位小数
样例输入
2 1 3 4
样例输出
0.3333
数据规模和约定
　　对于50%的数据，n≤5.
　　对于100%的数据，n≤100,b≤100.
*/
#include<stdio.h>   
double dp[101][10001];
double jisuan( int , int , int , int );
int main( void ) 
{  
	int n, a, b, x;  
    scanf("%d%d%d%d", &n, &a, &b, &x);  
    printf("%.4lf\n",jisuan( n , a , b , x ));  
    return 0;  
}   
double jisuan( int n , int a , int b, int x)
{ 
	dp[0][0] = 1 ;  
    int  i , j  , k ;  
    for( i = 1 ; i <= n ; i ++ )
	 {  
        for( j = 0 ; j <= x ; j ++) 
		{  
            for( k = a ; k <= b ; k ++) 
			{  
                if(j >= k) 
				{
                	dp[i][j] += dp[i-1][j-k] / ( b - a + 1) ;  
				}
            }  
        }  
    }   
    return dp[n][x];
}
