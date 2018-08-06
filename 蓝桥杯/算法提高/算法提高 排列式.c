/*
　　7254是一个不寻常的数，因为它可以表示为7254 = 39 x 186，这个式子中1~9每个数字正好出现一次
　　输出所有这样的不同的式子（乘数交换被认为是相同的式子）
　　结果小的先输出；结果相同的，较小的乘数较小的先输出。
输出格式
　　每一行输出一个式子，式子中的等号前后空格、乘号（用字母x代表）前后空格
　　较小的乘数写在前面
样例输出
问题中的式子在结果中会出现一行如下：
7254 = 39 x 186
*/
#include <stdio.h>
void shuchu(int [] , int , int );
int panduan( int [] , int ) ;
void sc_pd(int [] , int ) ;
int q_shu( int [] , int ) ;

int main(void)
{
	int sz[9];
	shuchu( sz , 9 , 0 );
	return 0;
}

int q_shu(int sz[] , int n)
{
	int i , shu = 0  ;
	for( i = 0 ; i < n ; i ++ )
	{
		shu *= 10 ;
		shu += sz[i] ;
	}
	return shu ;
}

void sc_pd( int sz[] , int n ) 
{
	int i , j;
	int s1 , s2 , s3 ; 
	for( i = 1 ; i < 9 ; i ++ )
	{
		for( j  = i + 1 ; j < 9 ; j ++ )
		{
			s1 = q_shu( sz , i ) ;
			s2 = q_shu( sz + i , j - i ) ;
			s3 = q_shu( sz + j  , n - j ) ;
			if( s1 == s2 * s3 && s2 < s3 )
			{
				printf("%d = %d x %d\n", s1 , s2 , s3 );
			}
		}
	}
}

int panduan(int sz[] , int n)
{
	int i;
	for( i = 0 ; i < n ; i ++ )
	{
		if( sz[i] == sz[n] )
		{
			return 0 ;
		} 
	}
	return 1;
}

void shuchu( int sz[] , int n , int s )
{
	if( s == n )
	{
		sc_pd( sz , n );
		return ;
	}
	for( sz[s] = 1 ; sz[s] < 10 ; sz[s] ++ )
	{
		if( panduan( sz , s ) == 1  )
		{
			shuchu( sz , n , s + 1 );
		}
	}
}

