/*��������
������n��С����Χ����һȦ����ʦ��ÿ��С���������ż�����ǹ���Ȼ������������Ϸ��

����ÿ��С���Ѷ����Լ����ǹ���һ������ֱߵĺ��ӡ�

����һ�ַ��Ǻ�ӵ���������ǵĺ�������ʦ����1���ǹ����Ӷ����ż����

�����������������Ϸ��ֱ������С���ѵ��ǹ�������ͬΪֹ��

�������������Ԥ������֪�ĳ�ʼ�ǹ������£���ʦһ����Ҫ�������ٸ��ǹ���
�����ʽ
�����������ȶ���һ������N(2<N<100)����ʾС���ѵ�������
����������һ���ÿո�ֿ���N��ż����ÿ��ż��������1000����С��2��
�����ʽ
����Ҫ��������һ����������ʾ��ʦ��Ҫ�������ǹ�����
��������
3
2 2 4
�������
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
