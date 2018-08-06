/*
��������
����w�����һ����ֲ԰�����ֳ� m * n ��С���ӣ���������m�У��ϱ�����n�У���ÿ������������һ��ϸ�ֲ�
��������ֲ���и��ص㣬���ĸ����ܻ������ϱ�����������չ���Ӷ�����һ�����ӵ�ֲ��ϳ�Ϊһ�塣


����������Ǹ�������ЩС���Ӽ������������������˵�����԰��һ���ж�����ϸ�ֲ����
�����ʽ
������һ�У���������m��n���ÿո�ֿ�����ʾ���ӵ�������������1<m,n<1000����
����������һ�У�һ������k����ʾ���滹��k������(0<k<100000)
����������k�У�������������a��b����ʾ���Ϊa��С���Ӻͱ��Ϊb��С���Ӻϸ��ˡ�
�������ӵı��һ��һ�У����ϵ��£������ұ�š�
�������磺5 * 4 ��С���ӣ���ţ�
����1 2 3 4
����5 6 7 8
����9 10 11 12
����13 14 15 16
����17 18 19 20
��������
5 4
16
2 3
1 5
5 9
4 8
7 8
9 10
10 11
11 12
10 14
12 16
14 18
17 18
15 19
19 20
9 13
13 17
�������
5
����˵��
������ϸ�����ο���ͼ
*/
#include<stdio.h>
void Input( int ,int , int , int [] ) ; 
void union_find( int , int , int [] ) ; 
void Output( int , int , int [] ) ;
int find( int , int []) ; 
int main(void)
{
	int m , n , k ; 
	scanf("%d%d%d" , & m , & n , & k ) ;
	static int sz[1000001] ;  
	Input( m , n  , k  , sz ) ; 
	Output( m , n , sz ) ; 
	return 0 ; 
}
void Output( int m , int n, int sz[] )
{
	int i , sum = 0 ;
	for( i = 0 ; i < m * n ; i ++ )
	{
		if( sz[i] == i )
		{
			sum ++ ; 
		}
	}
	printf("%d\n" , sum ) ; 
}
int find( int s, int sz[])
{
	while( s != sz[s] )
	{
		s = sz[s] ; 
	}
}
void Input( int m , int n , int k , int sz[] )
{
	int i , x , y ;
	for( i = 0 ; i < m *n ; i ++ )
	{
		sz[i] = i  ; 
	}
	for( i = 0 ;  i < k ; i ++ )
	{
		scanf("%d%d" , & x , & y ) ; 
		union_find( --x , --y , sz ) ; 
	}
}
void union_find( int x , int y , int sz[] )
{
	x = find( x , sz );
	y = find( y , sz );
	if( x != y )
	{
		sz[x] = y ; 
	}
}
