/*.
�Ӽ��̶���n���������������У���д����CompactIntegers��ɾ������������ֵΪ0��Ԫ�أ�
���Ԫ���������׶��ƶ���
ע�⣬CompactIntegers������Ҫ�������鼰��Ԫ�ظ�����Ϊ������
��������ֵӦΪɾ������ִ�к��������Ԫ�ظ�����
���ɾ����������Ԫ�صĸ����������������Ԫ�ء�
��������: �������ʽ˵����5Ϊ�������ݵĸ�����3 4 0 0 2 ���Կո������5��������
5 
3 4 0 0 2
�������:�������ʽ˵����3Ϊ�������ݵĸ�����3 4 2 ���Կո������3������������
3
3 4 2
��������: 
7
0 0 7 0 0 9 0
�������:
2
7 9
��������: 
3
0 0 0
�������:
0
*/
#include<stdio.h>
void shuru( int [] , int );
int q_gs( int [] , int );
void huan( int * , int *);
void shuchu( int  , int [] );
void ydyw( int * , int * , int );
void nixu(int [] , int  );
int main( void )
{
	int n ;
	scanf("%d",&n);
	int sz[n];
	shuru( sz , n ); 
	int flgs = q_gs( sz , n );
	shuchu( flgs , sz );
	return 0 ;
}
void nixu(int sz[] , int  n)
{
	int tou , wei= n - 1 ; 
	for( tou = 0 ; tou < wei ; tou ++ )
	{
		huan( &sz[tou] , &sz[wei]);
		wei -- ;
	}
	
}
void ydyw( int * p_t , int * p_w, int  n )
{
	nixu( p_t , n );
	nixu( p_t + n , (p_w - p_t) - n );
	nixu( p_t , p_w - p_t ); 
}
void shuchu( int  p_flgs, int sz[] )
{
	printf("%d\n",p_flgs);
	while( p_flgs -- > 0 )
	{
		printf("%d " , * sz ++ );
	}
}
void huan( int *a , int * b)
{
	int tmp = * a;
	 *a = * b ;
	 * b = tmp ;  
}
int q_gs( int sz[] , int n)
{
	int tou = n , xb = n ;
	while( xb -- > 0 )
	{
		if( sz[xb] == 0 )
		{
			ydyw( &sz[xb] , &sz[tou] , 1 );
			tou -- ;
		}
	}
	 return tou ;
}
void shuru( int sz[] , int n)
{
	while( n -- > 0 )
	{
		scanf("%d", sz ++ );
	} 
}
