/*��������
����ũ��Լ��ĸţ���ǲ�����õ��߹ǡ�����ͨ��ũ��Լ��������ũҵ�������ÿ���߹��ϵ������ϳ����ǡ�
ũ��Լ��ȷ���������򷽵��������������߹ǣ�����Ϊ���ұ߿�ʼ�����߹ǣ�ÿ�λ�ʣ�µ��߹��ϵ����ֶ����һ��������
�����������ĸ��߹ǵ����ֱַ��ǣ�7 3 3 1����ôȫ���߹��ϵ����� 7331��������
�����߹� 733�������������߹� 73 ����������Ȼ,���һ���߹� 7 Ҳ��������7331 ���������� 4 ������������
����дһ������Ը������߹ǵ���Ŀ N (1<=N<=8),������е���������������1��������һ��������
�����ʽ
����������һ�а���N��
�����ʽ
������˳���������Ϊ N ����������,ÿ��һ����
��������
4
�������
2333
2339
2393
2399
2939
3119
3137
3733
3739
3793
3797
5939
7193
7331
7333
7393*/
#include<stdio.h>
void shuchu( int [] , int [] , int );
void jisuan( int , int , int  ,int []);
int panduan( int );
int main( void )
{
	int n ; 
	scanf("%d", & n );
	int sz1[4] = { 2 , 3 , 5 , 7 };
	int sz2[4] = { 1 , 3 , 7 , 9 };
	shuchu( sz1 , sz2 , n );
	return 0 ; 
}
int panduan( int n )
{
	int i ;
	if( n == 2 )
	{
		return 1 ; 
	} 
	if( n % 2 == 0 )
	{
		return 0 ; 
	} 
	for( i = 3 ; i * i <= n ; i += 2 )
	{
		if( n % i == 0 )
		{
			return 0 ; 
		}
	}
	return 1 ; 
}
void jisuan( int tmp , int k , int  n , int sz2[])
{
	if( k >= n - 1 )
	{
		printf("%d\n", tmp );
		return ;
	}
	int i ; 
	for( i = 0 ; i < 4 ; i ++ )
	{
		int shu = tmp * 10  + sz2[i] ; 
		if( panduan( shu ))
		{
			jisuan( shu , k + 1 , n  , sz2 );
		}
	}
}
void shuchu( int sz1[] , int sz2[] , int n )
{
	int i , tmp ;
	for( i = 0 ; i < 4 ; i ++ )
	{
		tmp = sz1[i] ;
		if( n == 1 )
		{
			printf("%d", tmp );
		}
		else
		{
			jisuan( tmp , 0 , n , sz2 );
		}
	}
}
