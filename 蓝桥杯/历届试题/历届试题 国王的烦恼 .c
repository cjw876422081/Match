/*
��������
����C����n��С����ɣ�Ϊ�˷���С��֮�����磬C����С���佨����m�����ţ�ÿ��������������С����
	����С������ܴ��ڶ��������ӡ�Ȼ�������ں�ˮ��ˢ����һЩ���������Ų���ʹ�õ�Σ�ա�
�����������С��������д��Ŷ�����ʹ�ã���������С���Ͳ���ֱ�ӵ����ˡ�Ȼ����
	ֻҪ������С���ľ�����ͨ���������Ż���������С�����ൽ����ǾͻᰲȻ����
	���ǣ����ǰһ������С��֮�仹�з������Ե����һ��ȴ���ܵ����ˣ������Ǿͻ�һ���顣
��������C���Ĺ����Ѿ�֪����ÿ������ʹ�õ�������������������Ͳ���ʹ���ˡ���������֪�������ǻ��ж�������п��顣
�����ʽ
��������ĵ�һ�а�����������n, m���ֱ��ʾС���ĸ������ŵ�������
����������m�У�ÿ����������a, b, t���ֱ��ʾ����������a�ź�b������С������ʹ��t�졣С���ı�Ŵ�1��ʼ������
�����ʽ
�������һ����������ʾ�����ǻΌ���������
��������
4 4
1 2 2
1 3 2
2 3 1
3 4 3
�������
2
����˵��
������һ���2��3֮����Ų���ʹ�ã���Ӱ�졣
�����ڶ����1��2֮�䣬�Լ�1��3֮����Ų���ʹ�ã������ǻΌ�顣
�����������3��4֮����Ų���ʹ�ã������ǻΌ�顣
���ݹ�ģ��Լ��
��������30%�����ݣ�1<=n<=20��1<=m<=100��
��������50%�����ݣ�1<=n<=500��1<=m<=10000��
��������100%�����ݣ�1<=n<=10000��1<=m<=100000��1<=a, b<=n�� 1<=t<=100000��
*/
#if 1
#include<stdio.h>
typedef
	struct
	{
		int a ;
		int b ;
		int day ;  
	}Qiao_t ;
	
void Input( Qiao_t [] , int ) ; 
void qsort( Qiao_t [] , int , int ) ; 
void cs_way( int [] , int  ); 
int jisuan( int [] , Qiao_t [] , int ); 
int pd( int ,  int  , int []) ; 
int pbj( int ,  int [] ) ; 

int main(void)
{
	int n , m ; 
	scanf("%d%d" , & n , & m ) ;
	Qiao_t sz[100001];
	Input( sz , m ) ; 
	qsort( sz , 0 ,  m - 1 ) ;
	int way[10001] = { 0 } ; 
	cs_way( way , n ) ; 
	printf("%d\n" , jisuan( way , sz  , m )) ; 
	 /*
	int i ; 
	for( i = 0 ; i < m  ; i ++ )
	{
		printf("%d %d %d\n" ,sz[i].a , sz[i].b , sz[i].day  ); 
	}*/
	return 0 ;
}

int pbj( int n ,  int bj[] )
{
	if( bj[n] == n )
	{
		return n ; 
	}
	return  bj[n] = pbj( bj[n] , bj ) ; 
}
int pd( int a,  int b , int way[])
{
	a = pbj( a , way) ; 
	b = pbj( b , way) ; 
	if( a !=  b )
	{
		way[a] = b ; 
		return 1 ;
	}
	return 0 ; 
}
int jisuan( int way[] , Qiao_t sz[] , int  m )
{
	int i , sum = 0 , p = -1 ; 
	for( i = 0 ; i < m ; i ++ )
	{
		if( pd( sz[i].a , sz[i].b  , way ) && p != sz[i].day )
		{
			sum ++ ; 
			p= sz[i].day ; 
		}  
	}
	return sum ; 
}
void cs_way( int way[] , int n )
{
	int i  ;
	for( i = 0 ; i <  n ; i ++ )
	{
		way[i] = i ; 
	} 
}
void qsort( Qiao_t sz[] , int left , int  right )
{
	if( left >= right )
	{
		return ; 
	}
	int i = left , j = right ; 
	Qiao_t key = sz[left] ;
	while( i < j )
	{
		while( i < j && key.day >= sz[j].day )
		{
			j -- ; 
		}
		sz[i] = sz[j] ; 
		while(  i < j && key.day <= sz[i].day )
		{
			i ++ ; 
		}
		sz[j] = sz[i] ; 
	 } 
	 sz[i] = key ; 
	 qsort( sz , left , i - 1 ) ; 
	 qsort( sz  , i + 1 , right ) ; 
	 
}

void Input( Qiao_t sz[] , int  m )
{
	int i ; 
	for( i = 0 ; i < m  ; i ++ )
	{
		scanf("%d%d%d" , &sz[i].a , & sz[i].b , & sz[i].day ) ; 
	}
}
#endif
