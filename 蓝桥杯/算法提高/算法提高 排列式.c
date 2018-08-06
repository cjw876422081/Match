/*
����7254��һ����Ѱ����������Ϊ�����Ա�ʾΪ7254 = 39 x 186�����ʽ����1~9ÿ���������ó���һ��
����������������Ĳ�ͬ��ʽ�ӣ�������������Ϊ����ͬ��ʽ�ӣ�
�������С��������������ͬ�ģ���С�ĳ�����С���������
�����ʽ
����ÿһ�����һ��ʽ�ӣ�ʽ���еĵȺ�ǰ��ո񡢳˺ţ�����ĸx����ǰ��ո�
������С�ĳ���д��ǰ��
�������
�����е�ʽ���ڽ���л����һ�����£�
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

