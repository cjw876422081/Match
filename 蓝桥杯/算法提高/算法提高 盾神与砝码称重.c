/*
 ��������
������һ�죬���������������з�����һ����ƽ�������ƽ����֣�
��n����õ����룬����û�����롣����Ϊ���ķ����˷ܲ��ѣ�������׼��ȥ��һ���Լ��Ķ�����
��׼������m����Ʒȥ�ơ�������ǣ�����һ���֪����m����Ʒ�����������������뿴�������ƽ�ܲ��ܳƳ���Щ��Ʒ������
���Ƕ�����΢����1�����Ժ�;����������̫�����ˣ����ǾͶ������㡣
�����ʽ
������һ��Ϊ��������n��m��
�����ڶ���Ϊn��������ʾ��n�������������
����������Ϊm��������ʾ��m����Ʒ��������
�����ʽ
�������m�У����ڵ�i�У������i����Ʒ�ܱ��Ƴ������YES�������NO��
��������
4 2
1 2 4 8
15 16
�������
YES
NO
��������
4 1
10 7 1 19
6
�������
YES
���ݹ�ģ��Լ��

����1<=n<=24, 1<=m<=10.
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
