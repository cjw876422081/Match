/*
��������
��һ�� n ���ڵ����������ÿ���ڵ㶼��һ��������Ȩֵ�����һ���㱻ѡ���ˣ�
��ô�����Ϻ������ڵĵ㶼���ܱ�ѡ����ѡ���ĵ��Ȩֵ������Ƕ��٣�
�����ʽ
��һ�а���һ������ n ��
��������һ�а��� n ������������ i ������������� i ��Ȩֵ��
������һ�� n-1 �У�ÿ���������ϵ�һ���ߡ�
�����ʽ
���һ������������ѡ���ĵ��Ȩֵ�͵����ֵ��
��������
5
1 2 3 4 5
1 2
1 3
2 4
2 5
�������
12
����˵��
ѡ��3��4��5�ŵ㣬Ȩֵ��Ϊ 3+4+5 = 12 ��
���ݹ�ģ��Լ��
����20%�����ݣ� n <= 20��
����50%�����ݣ� n <= 1000��
����100%�����ݣ� n <= 100000��
Ȩֵ��Ϊ������1000����������
*/
#include<stdio.h>
#define N (100002)
typedef
struct
{
	int to ; 
	int next ;
}Tree ;  
void Input_f( int [][2] , int );
void Input_s( Tree [] , int [] , int , int * );
void add( Tree []  ,int [] , int , int  , int * ); 
void Cs_date ( int [][2] , int [] , int );
void Tree_max( int [][2] ,Tree []  ,int [] , int , int );
int max( int , int ) ;   
int main(void)
{
	int sz[N][2] ;
	int head[N]; 
	Cs_date(  sz , head , N );  
	int n , m = 0 ; 
	scanf("%d" , & n ) ; 
	Input_f( sz , n   ) ;
	Tree tree[N] ; 
	Input_s( tree , head , n - 1 , &m) ; 
	Tree_max( sz , tree , head , 1 , -1 ); 
	int ans= max(sz[1][0], sz[1][1]) ; 
    printf("%d\n", ans );
	return 0 ; 
}
int max( int a, int b)
{
	return a > b ? a : b ; 
}
void Tree_max( int sz[][2], Tree tree[]  ,int head[] , int x , int pre )
{
	int i ; 
	for( i = head[x]; i != -1 ; i = tree[i].next )
	{
		int v = tree[i].to ; 
		if( pre == v)
		{
			continue;	
		}
        Tree_max(sz , tree , head ,v, x);
        sz[x][1] += sz[v][0];
       	sz[x][0] += max(sz[v][0], sz[v][1]); 
	}
	
}
void add( Tree tree[] , int head[] , int f , int t , int * m )
{
	tree[ * m].to = t ;
	tree[ * m].next = head[f] ; 
	head[f] =  * m  ; 
	++ * m  ; 
	tree[ * m].to = f ;
	tree[ * m].next = head[t] ; 
	head[t] = *m  ; 
	++ *m  ;
}
void Cs_date (int sz[][2] , int head[] , int n )
{
	int i , j ; 
	for( i = 0 ; i < n ; i ++ )
	{
		head[i] = -1 ; 
		for( j = 0 ; j < 2 ; j ++ )
		{
			sz[i][j] = 0 ; 
		}
	}

}
void Input_s( Tree tree[] , int head[] , int n , int * m )
{
	int i ; 
	for( i = 1 ; i <= n ; i ++ )
	{
		int tmp1 , tmp2 ; 
		scanf("%d%d", &tmp1 , &tmp2 );
		add( tree , head , tmp1 , tmp2 , m ) ; 
	} 
}
void Input_f( int sz[][2] , int n )
{
	int i ; 
	for( i = 1 ; i <= n ; i ++ )
	{
		scanf("%d" , & sz[i][1] ) ; 
	}
}
