/*��������
����2016.4.5�Ѹ��´��⣬��ǰ�ĳ�����Ҫ�����ύ��
��������
��������һ���ٷ��Ƴɼ�T�����仮��Ϊ��������ȼ�֮һ��
����90~100ΪA��80~89ΪB��70~79ΪC��60~69ΪD��0~59ΪE
�������ڸ���һ���ļ�inp���ļ��а������ɰٷ��Ƴɼ����ɼ�����������100��������ͳ������ȼ��ε����������ҳ����������Ǹ��ȼ��Σ����մӴ�С��˳������ö��������˳ɼ�����֤�������ĵȼ�ֻ��һ������Ҫ�������ָ���ļ�oup�С�
�����ʽ
��������0~100�����������ÿո����
�����ʽ
������һ��Ϊ5�����������ֱ��ʾA,B,C,D,E����ȼ��ε�����
�����ڶ���һ������������ʾ�������ĵȼ���������
����������һ�����ɸ��ÿո����������������ʾ���������Ǹ��ȼ��������˵ķ��������Ӵ�С��˳�������
��������
10
100 100 85 77 55 61 82 90 71 60
�������
2 3 2 2 1
3
85 82 80

*/
#include<stdio.h>
void shuru( int , int [] , int []);
void shuchu( int , int [] , int []);
void cunru( int [] , int [] , int  , int  , int * );
int q_tou( int );
int q_wei( int );
void paixu( int [] , int );
void huan( int * , int * );
void sc_sz( int [] , int );
int main( void )
{
	int n ;
	scanf("%d", &n );
	int sz[n] , gs[5] = {0}  ; 
	shuru( n , sz , gs );
	shuchu( n , sz , gs);
	return 0 ; 
}
void sc_sz( int sz[] , int n)
{
	int i ; 
	for( i = 0 ; i < n ; i ++ )
	{
		printf("%d " , sz[i]);
	}
}
void huan( int * a, int * b)
{
	int tmp = * a ; 
	* a = * b;
	* b = tmp ;  
}
void paixu( int sz[] , int n)
{
	int i , j ;
	for( i = 0 ; i < n ; i ++ )
	{
		for( j = 0 ; j < n - i -1 ; j ++ )
		{
			if( sz[j] < sz[j+1] )
			{ 
				huan( sz + j , sz + j + 1);
			}
		}
	}
}
int q_wei( int n )
{
	switch( n )
	{
		case 0 :return 100;
		case 1 :return 89;
		case 2 :return 79;
		case 3 :return 69;
		case 4 :return 59;
	}
	
}
int q_tou( int n )
{
	switch( n )
	{
		case 0 :return 90;
		case 1 :return 80;
		case 2 :return 70;
		case 3 :return 60;
		case 4 :return 0;
	}
	
}
void shuchu( int n , int sz[] , int gs[] )
{
	int i , xb = 0 , tmp = gs[0] ; 
	for( i = 0 ; i < 5 ; i ++ )
	{
		printf("%d " , gs[i] );
		if( tmp < gs[i] )
		{
			tmp = gs[i] ; 
			xb = i ;
		}
	}
	printf("\n%d\n" , tmp ) ;
	int cf[10000] , ws = 0 ;
	cunru( cf , sz , n , xb , &ws );
	paixu( cf , ws );
	sc_sz( cf , ws);
}
void cunru( int cf[] , int sz[] , int n , int  xb , int * p_ws )
{
	int i , tou = q_tou( xb ) , wei = q_wei( xb );
	for( i = 0 ; i < n ; i ++ )
	{
		if( tou <= sz[i] && sz[i] <= wei )
		{
			cf[* p_ws] = sz[i] ; 
			++ * p_ws ; 
		}
	}
}
void shuru( int n , int sz[] , int gs[])
{
	int i ;
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d" , &sz[i]);
		if( sz[i] >= 0 && sz[i] < 60)
		{
			gs[4] ++ ; 
		}
		if( sz[i] >= 60 && sz[i] < 70)
		{
			gs[3] ++ ; 
		}
		if( sz[i] >= 70 && sz[i] < 80)
		{
			gs[2] ++ ; 
		}
		if( sz[i] >= 80 && sz[i] < 90)
		{
			gs[1] ++ ; 
		}
		if( sz[i] >= 90 && sz[i] <= 100)
		{
			gs[0] ++ ; 
		}
	}
}
