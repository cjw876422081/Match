/*��������
������ͯ��������KλС���ѵ�С�������͡�С���ó�����ص��ɿ����д�С�����ǡ�
����С��һ����N���ɿ��������е�i����Hi x Wi�ķ�����ɵĳ����Ρ�
����Ϊ�˹�ƽ�����С����Ҫ���� N ���ɿ������г�K���ɿ����ָ�С�����ǡ��г����ɿ�����Ҫ���㣺
����1. ��״�������Σ��߳�������
����2. ��С��ͬ
��������һ��6x5���ɿ��������г�6��2x2���ɿ�������2��3x3���ɿ�����
������ȻС�����Ƕ�ϣ���õ����ɿ��������ܴ����ܰ�СHi��������ı߳��Ƕ���ô��
�����ʽ
������һ�а�����������N��K��(1 <= N, K <= 100000)
��������N��ÿ�а�����������Hi��Wi��(1 <= Hi, Wi <= 100000)
�������뱣֤ÿλС���������ܻ��һ��1x1���ɿ�����
�����ʽ
��������г����������ɿ��������ܵı߳���
��������
2 10
6 5
5 6
�������
2
���ݹ�ģ��Լ��
������ֵ�ڴ����ģ���������� < 256M
����CPU���� < 1000ms
*/
#include<stdio.h>
void input(  int n  , int [][2]);
int jisuan(  int n  , int [][2] , int );
long long  cakes( int , int [][2] , int );
int max( int , int );
int main( void )
{
	int n , k ; 
	scanf("%d%d" ,&n , &k );
	int cake[n][2] ;
	input( n , cake ) ;
	printf("%d" , jisuan( n , cake , k ));
	return 0 ; 
}
int  max( int a , int b )
{
	return a > b ? a : b ;
}
long long  cakes( int bc , int sz[][2] , int n )
{
	int i ;
	long long  sum = 0 ; 
	for( i = 0 ; i < n ; i ++ )
	{
		sum += (sz[i][0]/bc)*(sz[i][1]/bc);
	}
	return sum ; 
}
int jisuan(  int n  , int sz[][2] , int k )
{
	int left  = 1 , right = 100000 , mid , ans = 0 ;
	while( left < right - 1 )
	{
		mid = ( left + right ) / 2 ; 
		if( k > cakes( mid , sz , n ))
		{
			right = mid ; 
		} 
		else
		{
			left = mid ; 
			ans = max( ans , mid );
		}
	}
	return ans ; 

}
void input(  int n  , int sz[][2])
{
	int i ;
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d%d" ,&sz[i][0] , &sz[i][1]);
	}
}
