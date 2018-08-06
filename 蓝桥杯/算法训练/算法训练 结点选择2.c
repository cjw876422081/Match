/*
问题描述
有一棵 n 个节点的树，树上每个节点都有一个正整数权值。如果一个点被选择了，
那么在树上和它相邻的点都不能被选择。求选出的点的权值和最大是多少？
输入格式
第一行包含一个整数 n 。
接下来的一行包含 n 个正整数，第 i 个正整数代表点 i 的权值。
接下来一共 n-1 行，每行描述树上的一条边。
输出格式
输出一个整数，代表选出的点的权值和的最大值。
样例输入
5
1 2 3 4 5
1 2
1 3
2 4
2 5
样例输出
12
样例说明
选择3、4、5号点，权值和为 3+4+5 = 12 。
数据规模与约定
对于20%的数据， n <= 20。
对于50%的数据， n <= 1000。
对于100%的数据， n <= 100000。
权值均为不超过1000的正整数。
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
