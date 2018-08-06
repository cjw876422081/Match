/*
问题描述
有一棵 n 个节点的树，树上每个节点都有一个正整数权值。如果一个点被选择了，那么在树上和它相邻的点都不能被选择。
求选出的点的权值和最大是多少？
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

int jd[100000][100];
void shuru( int , int [][2] );
void xieru( int , int );
int max( int , int );
void jisuan( int , int [][2], int , int );
int main( void )
{
	int n ; 
	scanf("%d", &n) ;
	int qz[n][2];
	shuru( n , qz );
	jisuan( n , qz , 1  , 0 );
	printf("%d\n", max( qz[1][0] , qz[1][1] ));
	return 0;
}
void jisuan( int n , int qz[][2] , int  i , int j )
{
	int  t , k = 0 ; 
   	while(t = jd[i][k++]) 
	{        
	    if(t != j )  
	    {    
	    	jisuan( n , qz , t , i ); 
	        qz[i][1] += qz[t][0];                    
	        qz[i][0] += max( qz[t][0] , qz[t][1]);   
	   	}  
	}  
	
}
int max( int a , int b )
{
	return a > b ? a : b ;
}
void xieru( int a , int  b )
{
	int i = 0 , j = 0 ; 
    while(jd[a][i] != 0)
	{
		i ++ ;
	}
    jd[a][i] = b ;      
    while(jd[b][j] != 0 )  
    {
    	j ++;
	}
    jd[b][j] = a ;  
}
void shuru( int n , int qz[][2] )
{
	int i ; 
    for( i = 1 ; i <= n ; i ++ ) 
	{
		scanf("%d" , & qz[i][1]);
		qz[i][0] = 0 ;
	}
	int zjd , fjd ; 
    for( i = 1 ; i < n ; i ++ )   
    {  
        scanf("%d%d" , & zjd , &fjd );  
        xieru( zjd , fjd );             
    }  
	
}
