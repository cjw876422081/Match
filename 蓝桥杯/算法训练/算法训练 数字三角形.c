/*
��������
������ͼ��.��������ʾ����һ�����������Ρ� ���һ���������Ӷ����׵�ĳ����һ��·
��������ʹ��·�������������ֵ��ܺ����
������ÿһ��������б�����»���б�������ߣ�
������1��������������100��
�������������е�����Ϊ����0��1����99��

����.
������ͼ��.��������
�����ʽ
�����ļ������ȶ������������ε�������

������������������������
�����ʽ
��������ܺͣ�������
��������
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
�������
30
*/ 
#include<stdio.h>
void shuru( int [][128] , int  );
int jisuan( int [][128] , int   );
int max( int , int );
int main( void )
{
	int hs; 
	scanf("%d",&hs);
	int sz[128][128]; 
	shuru( sz , hs );
	printf("%d\n",jisuan( sz, hs ));
	return 0 ; 
}
int max( int a, int b)
{
	return a > b ? a : b ; 
}
int jisuan( int sz[][128] , int  n )
{
	int i , j , sum = 0  ; 
	for(i = 1 ; i <= n ; i ++ )
	{
		for( j = 1 ; j <= i ; j ++ )
		{
			sz[i][j] += max(sz[i-1][j] , sz[i-1][j-1]);
			if( sum < sz[i][j] )
			{
				sum = sz[i][j];
			}  
		}
	}
	return sum ; 
}
void shuru( int sz[][128] , int n )
{
	int i , j ; 
	for(i = 1 ; i <= n ; i ++ )
	{
		for( j = 1 ; j <= i ; j ++ )
		{
			scanf("%d", &sz[i][j]);
		}
	}
	sz[0][0] = 0 ; 
	sz[0][1] = 0 ;
} 
