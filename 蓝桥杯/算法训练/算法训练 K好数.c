/*
如果一个自然数N的K进制表示中任意的相邻的两位都不是相邻的数字，那么我们就说这个数是K好数。
求L位K进制数中K好数的数目。例如K = 4，L = 2的时候，所有K好数为11、13、20、22、30、31、33 共7个。
由于这个数目很大，请你输出它对1000000007取模后的值。
输入格式

输入包含两个正整数，K和L。
输出格式
输出一个整数，表示答案对1000000007取模后的值。
样例输入
4 2
样例输出
7
数据规模与约定
对于30%的数据，KL <= 106；
对于50%的数据，K <= 16， L <= 10；
对于100%的数据，1 <= K,L <= 100。
*/
#include<stdio.h> 
#define mod (1000000007)
int tongji( int [][100] , int  , int );
int main( void )
{
	int k , l ; 
	scanf("%d%d" , &k , &l);
	int sz[100][100]={0};
	printf("%d\n" , tongji( sz , k , l ));
	return 0 ; 
}

int tongji( int sz[][100] , int k , int l )
{

	int i , j , shu , sum = 0 ; // i 数字有几位 ， j 首位放j的情况数 
	for(j = 0 ; j < k ; j ++ )
	{
		sz[0][j] = 1 ; 
	}
	for(i = 1 ; i < l ; i ++ )
	{
		for( j = 0 ; j < k ; j ++ )
		{
			for( shu = 0 ; shu < k ; shu ++ )
			{
				if(shu != j - 1 && shu != j + 1 )//本位相邻的两位都不是相邻的数字
                {  
                    sz[i][j] += sz[i-1][shu];  
                    sz[i][j] %= mod ;  
                }  
			}
			
		}
	}
	for( i = 1 ; i < k ; i ++)  
    {  
        sum += sz[l-1][i] ;  
        sum %= mod ;  
    }  
    return sum ;  
}
