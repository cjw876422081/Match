/*
 问题描述
　　有一天，他在宿舍里无意中发现了一个天平！这个天平很奇怪，
有n个完好的砝码，但是没有游码。盾神为他的发现兴奋不已！于是他准备去称一称自己的东西。
他准备好了m种物品去称。神奇的是，盾神一早就知道这m种物品的重量，他现在是想看看这个天平能不能称出这些物品出来。
但是盾神稍微想了1秒钟以后就觉得这个问题太无聊了，于是就丢给了你。
输入格式
　　第一行为两个数，n和m。
　　第二行为n个数，表示这n个砝码的重量。
　　第三行为m个数，表示这m个物品的重量。
输出格式
　　输出m行，对于第i行，如果第i个物品能被称出，输出YES否则输出NO。
样例输入
4 2
1 2 4 8
15 16
样例输出
YES
NO
样例输入
4 1
10 7 1 19
6
样例输出
YES
数据规模和约定

　　1<=n<=24, 1<=m<=10.
*/
#include<stdio.h>
void sr_fm( int [] , int );
void paixu( int [] , int , int );
void huan( int * , int * );
int sr_fmh( int [] , int );
int pd_fm(int [] , int  , int , int  , int  );
int main( void )
{
	int  n , m ; 
	scanf("%d%d", &n , &m);
	int fm[n] ;
	sr_fm( fm , n ); 
	paixu( fm , 0 , n - 1 );
	int fmh = sr_fmh( fm , n );
	while( m -- > 0 )
	{
		int shu ,bj = 0 ;  
        scanf("%d" , & shu ) ;  
		puts( pd_fm(fm , fmh , 0 , shu , n   ) != 0 ? "YES" : "NO" );
	}
	return 0 ; 
}
int pd_fm( int fm[] , int fmh ,  int x , int sum , int n )
{  
	if( n  >  0 )
	{
		if( sum == fmh )
		{
			return 1 ; 
		}
		if( sum > fmh )
		{
			return 0 ; 
		}
		return  pd_fm( fm , fmh - fm[x] , x + 1 , sum + fm[x] , n - 1 ) ||  
    			pd_fm( fm , fmh - fm[x] , x + 1 , sum - fm[x] , n - 1 ) ||
				pd_fm( fm , fmh - fm[x] , x + 1 , sum         , n - 1 ) ; 
	}
	return sum == 0 ; 
 
}  
int sr_fmh( int fm[] , int n  )
{
	int i , shu = 0  ;  
    for( i = 0 ; i < n ; i ++ )
	{  
        shu += fm[i]  ;
    }  
    return shu ; 
}
void huan( int * a, int * b)
{
	int tmp = *a ; 
	*a = * b; 
	* b = tmp ;
}
void paixu( int sz[] , int start , int end )
{
	if( start >= end )
	{
		return ;
	}
	int k = sz[start];
	int i = start , j = end ;
	while( i != j )
	{
		while( i < j && sz[j] <= k )
		{
			j -- ;
		}
		huan( sz + i , sz + j );
		while( i < j && sz[i] >= k )
		{
			i ++ ;
		}
		huan( sz + i , sz + j );
	}
	paixu( sz , start , i - 1 );
	paixu( sz , i + 1 , end );
}
void sr_fm( int sz[] , int n )
{
	int i ; 
	for( i = 0 ; i < n ; i ++ )
	{  
        scanf("%d", & sz[i] ) ;  
    }  
}
