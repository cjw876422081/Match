/*
��������
����ɨ����Ϸ��һ������ɣ����ڸ������ɸ�n��m�ĵ�������������ÿ��������ÿ����Ԫ�����ڵ�Ԫ���ڵ��׵ĸ�����ÿ����Ԫ�������8�����ڵĵ�Ԫ��
``` 0<n,m<=100
�����ʽ
��������������ɸ����󣬶���ÿ�����󣬵�һ�а�����������n��m���ֱ��ʾ��������������������
	������n��ÿ�а���m���ַ�����ȫ�����á�.����ʾ���е���������'*'��ʾ����n=m=0ʱ���������
�����ʽ
�������ڵ�i�����������ڵ�����һ�����ӡ��ţ���Field #i:��,��������n���У������'.'Ӧ����λ����Χ�ĵ����������档
�����ÿ�������������һ�����и�����
��������
4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0
�������
Field #1:
*100
2210
1*10
1110

Field #2:
**100
33200
1*100
��ע����������֮��Ӧ����һ�����У�����oj�ĸ�ʽ�����ﲻ����ʾ������
���ݹ�ģ��Լ��
����0<n,m<=100


*/
#include<stdio.h>
void shuru( char [][101] , int , int );
void shuchu( char [][101] , int , int , int );
int q_zwls( char [][101] , int , int , int , int );
int main( void )
{
	int gs = 0 ; 
	while( 1 )
	{
		int n , m  ; 
		char lq[101][101] ; 
		scanf("%d%d" ,& n , & m );
		if( n == 0 && m == 0 )
		{
			break ; 
		}
		gs ++ ;
		shuru( lq , n , m );
		shuchu( lq , n  , m , gs );
	}
	return 0 ; 
}
int q_zwls( char lq[][101] , int h , int  l, int n , int m)
{
	int i , j , sum = 0 ;
	for( i = h - 1 ; i <= h + 1 ; i ++ )
	{
		for( j = l- 1 ; j <= l + 1 ; j ++ )
		{
			if( i >= 0 && i < n && j >= 0  && j < m )
			{
				if( lq[i][j] == '*')
				{
					sum ++ ; 
				}
			}
		}
	}
	return sum ; 
}
void shuchu( char lq[][101] , int n , int m , int gs )
{
	int i , j ; 
	printf("Field #%d:\n" , gs ); 
	for( i = 0 ; i < n ; i ++ )
	{
		for( j = 0 ; j < m ; j ++ )
		{
			if( lq[i][j] == '*')
			{
				printf("%c", lq[i][j]);
			}
			else
			{
				printf("%d", q_zwls( lq , i , j , n , m ));
			}
			
		}
		putchar('\n');
	}
	putchar('\n');
}
void shuru( char lq[][101] , int n , int m )
{
	int i , j ;
	for( i = 0 ; i < n ; i ++ )
	{
		getchar();
		for( j = 0 ; j < m ; j ++ )
		{
			scanf("%c", &lq[i][j]);
		}
	}
}
