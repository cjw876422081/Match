/*
��������
������һ����СΪn����������ѡȡһЩԪ�أ�ʹ�����ǵĺ͵��ڸ�����ֵT��ÿ��Ԫ����ѡһ�Σ�����һ������ѡ��
�����ʽ
������һ��һ��������n����ʾ��������Ԫ�صĸ�����
�����ڶ���n���������ÿո������
����������һ������T����ʾҪ�ﵽ�ĺ͡�
�����ʽ
��������������У�ÿ�����һ��⣬����ѡȡ�����֣����������е�˳�����С�
�������ж���⣬���������������n�������ģ����������򶼲����������������������n-1�������ģ��������ơ�
�������һ������ܷ�������
��������
5
-7 -3 -2 5 9
0
�������
-3 -2 5
-7 -2 9
2
���ݹ�ģ��Լ��
����1<=n<=22
����T<=maxlongint
��������������Ԫ�صĺͶ�������long�ķ�Χ
*/
#if 1 
#include<stdio.h>
void Input( int , int [] ) ;
void Output( int [] , int ); 
void dfs( int [],int [], int , int , int , long long ,int * ) ; 
int main(void)
{
	int n ; 
	scanf("%d", & n  ); 
	int sz[30]={0} ; 
	Input( n , sz );
	long long t ; 
	scanf("%lld" , & t );
	int count = 0 , num[30]={0} ; ; 
	dfs( sz ,num ,n - 1 , 0 , 0 ,  t , &count) ; 
	printf("%d\n" , count) ; 
	return 0 ; 
}
void dfs( int sz[] , int num[] ,int tmp1, int tmp2, int sum ,long long  t ,int *count)
{
	if( tmp1 < 0 )
	{
		return ; 
	}
	dfs( sz ,num ,tmp1 -1 , tmp2 , sum , t , count) ; 
	
	num[tmp2] = sz[tmp1] ; 
	sum += num[tmp2] ;
	if( sum == t)
	{
		++ *count ; 
		Output( num ,tmp2 );
	} 	
	dfs( sz , num , tmp1 -1 , tmp2 + 1 , sum , t , count) ;
}
void Output( int sz[] , int n )
{
	int i ; 
	for( i = n ; i >= 0 ; i -- )
	{
		printf("%d%c" , sz[i] , i == 0 ? '\n':' ') ; 
	}
}
void Input( int n , int sz[] )
{
	int i ; 
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d" , & sz[i] );
	}
} 
#endif
