/*
��������
�������ڸ�����������a[],Ѱ���������ֵ���������±ꡣ
�����ʽ
������������a[],����Ԫ�ظ���С��1����100��������ݷ������У���һ��ֻ��һ��������ʾ����Ԫ�ظ������ڶ���Ϊ����ĸ���Ԫ�ء�
�����ʽ
����������ֵ�������±�
��������
3
3 2 1
�������
3 0
*/
#include<stdio.h>
void shuru( int [] , int );
void shuchu( int [] , int );
int main(void)
{
	int sz[128];
	int n ; 
	scanf("%d", &n );
	shuru( sz , n );
	shuchu( sz , n );
	return 0 ; 
} 
void shuchu( int sz[] , int n)
{
	int i , max = sz[0] , xb = 0 ;
	for( i = 0 ; i < n ; i ++ )
	{
		if( max <  sz[i])
		{
			max = sz[i];
			xb = i ;
		}
	}
	printf("%d %d\n" , max , xb );
}
void shuru( int sz[] , int n)
{
	int i ;
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d", &sz[i]);
	}
}
