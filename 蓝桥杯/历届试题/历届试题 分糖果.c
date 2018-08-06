/*问题描述
　　有n个小朋友围坐成一圈。老师给每个小朋友随机发偶数个糖果，然后进行下面的游戏：

　　每个小朋友都把自己的糖果分一半给左手边的孩子。

　　一轮分糖后，拥有奇数颗糖的孩子由老师补给1个糖果，从而变成偶数。

　　反复进行这个游戏，直到所有小朋友的糖果数都相同为止。

　　你的任务是预测在已知的初始糖果情形下，老师一共需要补发多少个糖果。
输入格式
　　程序首先读入一个整数N(2<N<100)，表示小朋友的人数。
　　接着是一行用空格分开的N个偶数（每个偶数不大于1000，不小于2）
输出格式
　　要求程序输出一个整数，表示老师需要补发的糖果数。
样例输入
3
2 2 4
样例输出
4
*/
#include<stdio.h>
void shuru( int [] , int );
int q_bftg( int [] , int );
void fentg( int [] , int );
int bufas( int [] , int );
int pd_xd( int [] , int );
int main( void )
{
	int n ; 
	scanf("%d" , &n );
	int sz[n];
	shuru( sz , n );
	printf("%d\n" , q_bftg( sz , n ));
	return 0 ; 
} 
int pd_xd( int sz[] , int n)
{
	int i;
	for( i = 0 ; i < n - 1 ; i ++ )
	{
		if( sz[i] != sz[n - 1] )
		{
			return 0;
		}
	}
	return 1 ;
}
int bufas( int sz[] , int n)
{
	int sum = 0  , i ;
	for( i = 0 ; i < n ; i ++ )
	{
		if( sz[i] % 2 != 0 )
		{
			sz[i] ++ ;
			sum ++ ;
		}
	}
	return sum ;
	
}
void fentg( int sz[] , int n)
{
	int i , shu = ( sz[0] /= 2 );
	for( i = 0 ; i < n - 1 ; i ++ )
	{
		sz[i] += sz[i + 1] / 2 ;
		sz[i + 1] /= 2 ;
	}
	sz[n - 1] += shu ;
}
int q_bftg( int sz[] , int n )
{
	int sum = 0 ; 
	do
	{
		fentg( sz , n );
		sum += bufas( sz , n  ); 
	}
	while( pd_xd( sz , n ) == 0);
	return sum ; 
}
void shuru( int sz[], int n )
{
	int i;
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d" ,&sz[i]);
	}
 } 
