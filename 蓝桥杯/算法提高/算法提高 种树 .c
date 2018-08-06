/*　种树
问题描述
　　A城市有一个巨大的圆形广场，为了绿化环境和净化空气，市政府决定沿圆形广场外圈种一圈树。园林部门 得到指令后，初步规划出n个种树的位置，顺时针编号1到n。并且每个位置都有一个美观度Ai，如果在这里种树就可以得到这Ai的美观度。但由于A城市土壤 肥力欠佳，两棵树决不能种在相邻的位置（i号位置和i+1号位置叫相邻位置。值得注意的是1号和n号也算相邻位置！）。
　　最终市政府给园林部门提供了m棵树苗并要求全部种上，请你帮忙设计种树方案使得美观度总和最大。如果无法将m棵树苗全部种上，给出无解信息。
输入格式
　　输入的第一行包含两个正整数n、m。
　　第二行n个整数Ai。
输出格式
　　输出一个整数，表示最佳植树方案可以得到的美观度。如果无解输出“Error!”，不包含引号。
样例输入
7 3
1 2 3 4 5 6 7
样例输出
15
样例输入
7 4
1 2 3 4 5 6 7
样例输出
Error!
数据规模和约定
　　对于全部数据，满足1<=m<=n<=30；
　　其中90%的数据满足m<=n<=20
　　-1000<=Ai<=1000
*/
#if 1
#include <stdio.h>
#include <stdlib.h>

void Input( int [] , int ) ;
void Output( int , int , int [] ) ;
int Solve( int , int , int [] , int [] , int ) ;

int main(void)  
{  
	int n , m ;
	scanf("%d%d", & n , & m ) ;
	int tree[n] ;
	Input( tree , n ) ; 
	Output( n , m , tree ) ;
    return 0;  
}

int Solve( int n , int m , int tree[] , int sz[] , int k )
{
	if( k >= n && m > 0 ) 
    {  
        return -1 ;  
    }
	int mg = 0 , i = -1 , j = -1 ;
	if( k < n && m > 0 )
	{
		if( sz[( k + 1 ) % n ] == 0 )
		{
			sz[k] = 1 ;
			i = Solve( n , m - 1 , tree , sz , k + 2 );
			sz[k] = 0 ;
		}
		j = Solve( n , m , tree , sz , k + 1 ) ;
        if( i != -1 && mg < i + tree[k]) 
		{
			mg = i + tree[ k ] ;
		} 
        if( j != -1 && mg < j ) 
		{
			mg = j ;
		} 
        if( i == -1 && j == -1) 
		{
			mg = -1 ; 
		}
	}
	return mg ;
}

void Output( int n , int m , int tree[] )
{
	if(  m > ( n / 2 ) )
	{
		printf("Error!");
		return ;
	}
	int sz[50] = { 0 } ;
	printf("%d" , Solve( n , m , tree , sz , 0 ) );
}

void Input( int tree[] , int n )
{
	int i;
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d", & tree[i] ) ;
	}
}

#endif
