/*
100 ���Ա�ʾΪ����������ʽ��100 = 3 + 69258 / 714��
�����Ա�ʾΪ��100 = 82 + 3546 / 197��
ע���������������У�����1~9�ֱ������ֻ����һ�Σ�������0����
���������Ĵ�������100 �� 11 �ֱ�ʾ����
�����ʽ
�ӱ�׼�������һ��������N (N<1000*1000)
�����ʽ
�������������������1~9���ظ�����©����ɴ�������ʾ��ȫ��������
ע�⣺��Ҫ�����ÿ����ʾ��ֻͳ���ж��ٱ�ʾ����
��������1
100 
�������1
11 
��������2
105 
�������2
6 
*/ 
#include <stdio.h>
void xuanze( int [] , int  , int , int * ) ;
int panduan( int [] , int ) ;
void sc_pd( int [] , int * , int ) ;
int q_shu( int [] , int ) ;

int main(void)
{
	int n;
	scanf("%d", &n );
	int cs = 0;
	int sz[9] ;
	xuanze(sz , 0  , n , &cs);
	printf("%d", cs );
	return 0;
}
int q_shu(int sz[] , int n )
{
	int shu = 0 ;
	while( n -- > 0 )
	{
		shu *= 10 ;
		shu += * sz ;
		sz ++ ;
	}
	return shu;
}
void sc_pd(int sz[] , int * p_cs , int n)
{
	int i , j ;
	for( i = 0 + 1 ; i < 9 ; i ++ )
	{
		for( j = i + 1 ; j < 9 ; j ++ )
		{
			int s1 = q_shu( sz ,i );
			int s2 = q_shu(sz+ i ,j - i);
			int s3 = q_shu(sz+j,9 - j);
			if( s2 % s3 == 0 && s1 + s2 / s3 == n )
			{
				++ * p_cs;
			}
		}		
	}
}
int panduan(int sz[] , int k)
{
	int i;
	for( i = 0 ; i < k ; i ++ )
	{
		if( sz[i] == sz[k] )
		{
			return 0;
		} 
	}
	return 1;
}
void xuanze(int sz[] ,int i , int n , int * p_cs)
{
	if ( i == 9 )
	{
		sc_pd( sz , p_cs , n );
		return ;
	}
	for( sz[i] = 1 ; sz [i] <= 9 ; sz[i] ++ )
	{
		if( panduan( sz , i ) )
		{
			xuanze(sz , i + 1 , n , p_cs );
		}
	}
}
