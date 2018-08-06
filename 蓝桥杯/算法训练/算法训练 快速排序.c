/*
��������
�����������������ʹ�õ�һ������ʽ�����ڸ�����n������ɵ�һ�����飬��ʹ�ÿ�����������������
�����ָ���һ���У����ÿ��������䰴�������������
�����ʽ
������һ��һ����N��
������2~N+1��ÿ��һ��������ʾ�������С�
�����ʽ
������N�У�ÿ��һ��������ʾ�������С�
��������
5
1
4
2
3
4
�������
1
2
3
4
4
���ݹ�ģ��Լ��
������10�����ݡ�
������100%�����ݣ�N<=10^5����������Ϊ�Ǹ�������int��Χ�ڡ�
*/

#include<stdio.h>
void Input( int [] , int  ); 
void Output( int [] , int );
void qsort( int [] , int , int );
int main(void)
{
	int n ; 
	scanf("%d" , & n ) ; 
	int sz[n]; 
	Input( sz , n );
	qsort( sz , 0 , n - 1 );
	Output( sz , n ); 
	return 0 ; 
}
void qsort( int sz[] , int left , int  right)
{
	if( left >= right )
	{
		return ; 
	}
	int i = left ; 
	int j = right ; 
	int key = sz[left] ;
	while( i < j )
	{
		while( i < j && key <= sz[j])
		{
			j -- ; 
		}
		sz[i] = sz[j] ; 
		while( i < j && key >= sz[i])
		{
			i ++ ; 
		}
		sz[j] = sz[i] ; 
	} 
	sz[i] = key ; 
	qsort( sz , left , i - 1 );
	qsort( sz , i + 1 , right);

	
}
void Output( int sz[] , int n )
{
	int i;
	for( i = 0 ; i < n ; i ++ )
	{
		printf("%d\n", sz[i]); 
	}
	
}
void Input( int sz[] , int n )
{
	int i ; 
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d", & sz[i] );
	}
}

