/*
��������
����ͼ��ʾ��3 x 3 �ĸ�������д��һЩ������
+--*--+--+
|10* 1|52|
+--****--+
|20|30* 1|
*******--+
| 1| 2| 3|
+--+--+--+
��������ͼ�е��Ǻ��߼������õ��������֣�ÿ�����ֵ����ֺͶ���60��
�����Ҫ������������ж����Ը�����m x n �ĸ����е��������Ƿ���Էָ�Ϊ�������֣�ʹ����������������ֺ���ȡ�
������ڶ��ֽ��������������ϽǸ��ӵ��Ǹ���������ĸ��ӵ���С��Ŀ��
����޷��ָ����� 0��
�����ʽ
�����ȶ����������� m n �ÿո�ָ� (m,n<10)��
��ʾ���Ŀ�Ⱥ͸߶ȡ�
��������n�У�ÿ��m�����������ÿո�ֿ���ÿ������������10000��
�����ʽ
���һ����������ʾ�����н��У��������Ͻǵķָ������ܰ�������С�ĸ�����Ŀ��
��������1
3 3
10 1 52
20 30 1
1 2 3
�������1
3
��������2
4 3
1 1 1 1
1 30 80 2
1 1 1 100
�������2
10
*/
#if 1
#include<stdio.h>
void shuru( int , int m, int sz[][m] , int * );
void q_gs( int , int , int , int m ,int [][11] , int sz[][m] , int , int * , int );
int main( void )
{
	int n , m , sum = 0 ;
	scanf("%d%d", &m , &n );
	int sz[n][m]; 
	shuru( n , m , sz , &sum );
	int bj[11][11] = {0};
		bj[0][0] = 1 ;

	int gs = 100 ; 

	q_gs( 0 , 0 , n , m , bj , sz , sum/2 - sz[0][0] , &gs , 1 );
	printf("%d\n" , gs );

	return 0 ; 
}
void q_gs( int x , int y, int  n, int m ,int bj[][11] , int sz[][m] , int sum , int *gs , int bs )
{
	static int fx[4][2] = { {-1 , 0 } , { 1 , 0 } , { 0 , -1 } , { 0 , 1} };
//	printf("sum = %d number = %d \n" , sum ,  number );
	if( sum == 0 )
	{
		* gs = *gs < bs ? *gs : bs ; 
		return ; 
	}
	int i ; 
	for( i = 0 ; i < 4 ; i ++ )
	{
		int tmpx = fx[i][0] + x ; 
		int tmpy = fx[i][1] + y ;
		if( tmpx >= 0 && tmpy >= 0 && tmpx < n && tmpy < m && bj[tmpx][tmpy] == 0 )
		{
			bj[tmpx][tmpy] = 1 ;
			
			q_gs( tmpx , tmpy , n , m , bj , sz , sum - sz[tmpx][tmpy] , gs , bs + 1 ) ;
			bj[tmpx][tmpy] = 0 ; 
		}
	}
}
void shuru( int n , int m , int sz[][m] , int *sum )
{
	int i , j ;
	for( i = 0 ; i < n ; i ++ )
	{
		for( j = 0 ; j < m ; j ++ )
		{
			scanf("%d", &sz[i][j]);
			(*sum) +=sz[i][j] ;  
		}
	}
}
#endif 
