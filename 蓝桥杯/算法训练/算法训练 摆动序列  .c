/*问题描述
　　如果一个序列满足下面的性质，我们就将它称为摆动序列：
　　1. 序列中的所有数都是不大于k的正整数；
　　2. 序列中至少有两个数。
　　3. 序列中的数两两不相等；
　　4. 如果第i – 1个数比第i – 2个数大，则第i个数比第i – 2个数小；
	如果第i – 1个数比第i – 2个数小，
    则第i个数比第i – 2个数大。
　　比如，当k = 3时，有下面几个这样的序列：
　　1 2
　　1 3
　　2 1
　　2 1 3
　　2 3
　　2 3 1
　　3 1
　　3 2
　　一共有8种，给定k，请求出满足上面要求的序列的个数。
输入格式
　　输入包含了一个整数k。（k<=20）
输出格式
　　输出一个整数，表示满足要求的序列个数。
样例输入
3
样例输出
8*/
#include<stdio.h>
#include<stdbool.h>

void shuru( int [] , int );
void pailie( int [] , int , int , int * );
void huan( int * , int * );
bool panduan( int [] , int );

int main(void)
{
	int n , sz[100] = {0}, gs = 0;
	scanf("%d", &n); 
	shuru( sz , n );
 	pailie( sz , 0 , n , &gs );
 	printf("%d\n", gs);
	return 0;
} 

bool panduan( int sz[] , int i )
{
	if(  i < 2 )
	{
		return true;
	}
	if( sz[i-1] > sz[i-2] && sz[i] < sz[i-2] )
	{
		return true;
	}
	if( sz[i-1] < sz[i-2] && sz[i] > sz[i-2] )
	{
		return true;
	}
	return false;
}

void huan( int * a , int * b )
{
	int tmp = * a;
	* a = * b;
	* b = tmp;
}

void pailie( int sz[] , int cs , int n , int * p_gs )
{
	if( cs == n )
	{
		return ;
	}
	int i;
	for( i = cs ; i < n ; i ++ )
	{
		huan( &sz[cs] , &sz[i] );
		if( panduan( sz , cs ) == true )
		{
			if( cs >= 1 )
			{
				++ * p_gs;
			}
			pailie( sz , cs + 1 , n , p_gs );
		}
		huan( &sz[cs] , &sz[i] );
	}
}

void shuru( int sz[] , int n )
{
	int i;
	for( i = 0 ; i < n ; i ++ )
	{
		sz[i] = i + 1 ;  
	}
}

