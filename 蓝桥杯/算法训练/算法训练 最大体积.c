/*
问题描述
　　每个物品有一定的体积（废话），不同的物品组合，
	装入背包会战用一定的总体积。假如每个物品有无限件可用，
	那么有些体积是永远也装不出来的。为了尽量装满背包，
	附中的OIER想要研究一下物品不能装出的最大体积。
	题目保证有解，如果是有限解，保证不超过2，000，000，000
　　如果是无限解，则输出0
输入格式
　　第一行一个整数n（n<=10），表示物品的件数
　　第2行到N+1行: 每件物品的体积(1<= <=500)
输出格式
　　一个整数ans，表示不能用这些物品得到的最大体积。
样例输入
3
3
6
10
样例输出
17
*/
#if 1
#include<stdio.h>
#define MAX (100000)
void Input( int [] , int );
int gcd( int , int ); 
int q_max( int [] , int );
int p_num( int [] , int );
int main(void)
{
	int n ; 
	scanf("%d" ,& n ) ; 
	int sz[n] ; 
	Input( sz , n ) ; 
	printf("%d\n", q_max( sz , n ));
	return 0 ; 
}
int p_num( int sz[] , int n)
{
	int temp = sz[0] , i ;
    for ( i = 1 ; i < n ; i ++ )
    {
        temp = gcd(temp, sz[i]);
    }
    return temp;
}
int q_max( int sz[] , int n)
{
	int v_max[MAX] = { 0 } ; 
	if( p_num( sz , n ) == 1 )
	{
		v_max[0] = 1 ; 
		int i ; 
		for( i = 0 ; i < n ; i ++ )
		{
			int j ; 
			for( j = sz[i] ;j <=MAX ; j ++ )
			{
				if(v_max[j - sz[i]] == 1 )
				{
					v_max[j] = 1 ; 
				} 
			}
		}
	}
	int i ; 
	for( i = MAX ; i >= 0; i -- )
    {
        if (v_max[i] == 0 )
        {
            return i ;
        }
    }
    return 0 ;  
	
}
int gcd( int a , int b)
{
	return  a%b == 0 ? b : gcd( b , a % b ) ; 
}
void Input( int sz[] , int n)
{
	int i ;
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d" , &sz[i] );
	}
} 
#endif
