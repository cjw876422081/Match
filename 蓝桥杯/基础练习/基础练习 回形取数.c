/*
问题描述
　　回形取数就是沿矩阵的边取数，若当前方向上无数可取或已经取过，则左转90度。一开始位于矩阵左上角，方向向下。
输入格式
　　输入第一行是两个不超过200的正整数m, n，表示矩阵的行和列。接下来m行每行n个整数，表示这个矩阵。
输出格式
　　输出只有一行，共mn个数，为输入矩阵回形取数得到的结果。数之间用一个空格分隔，行末不要有多余的空格。
样例输入
3 3
1 2 3
4 5 6
7 8 9
样例输出
1 4 7 8 9 6 3 2 5
样例输入
3 2
1 2
3 4
5 6
样例输出
1 3 5 6 4 2

*/
#include<stdio.h>
void shuru( int [][200] , int , int );
void shuchu( int [][200] , int , int );
void xiangxia( int [][200],  int *   ,  int  , int , int *);
void xiangyou( int [][200],  int  ,  int * , int , int *);
void xiangshang( int [][200],  int *  ,  int  , int *);
void xiangzuo( int [][200],  int    ,  int  * , int *);
int main( void ) 
{
	int hang , lie ; 
	scanf("%d%d",&hang , &lie );
	int sz[200][200];
	shuru( sz , hang , lie );
	shuchu( sz , hang , lie );
	return 0 ;
}
void xiangzuo( int sz[][200],  int i  ,  int * j  ,int * sum)
{
	while(sz[i][-- * j] != -1 && *j >= 0 ) 
	{  
      	printf("%d " , sz[i][*j]);  
        sz[i][*j]=-1;   
        ++ *sum;   
    }  
    ++ * j; 
}
void xiangshang( int sz[][200],  int * i  ,  int  j ,int * sum)
{
	while(sz[--*i][j]!=-1 && *i >= 0)
	{  
      	printf("%d " , sz[*i][j]);  
        sz[*i][j]=-1;   
        ++ * sum; 
    }  
    ++ * i ; 
}
void xiangyou( int sz[][200],  int  i  ,  int * j , int p_l ,int * sum)
{
	while(sz[i][++ * j]!=-1 && *j < p_l)
	{  
      	printf("%d " , sz[i][*j]);  
        sz[i][*j]=-1;   
        ++ *sum;   
    }  
    -- * j; 
}
void xiangxia( int sz[][200],  int * i  ,  int  j , int p_h ,int * sum)
{
	while(sz[++ *  i][j] != -1 && * i < p_h )
	{  
        printf("%d " , sz[*i][j]);  
        sz[* i][j]=-1;   
        ++ *sum;  
    }  
    -- * i ; 
}
void shuchu( int sz[][200] , int p_h , int p_l)
{
	int sum=0, i=-1,j=0;  
   	while(sum < p_h * p_l)
	{  
		xiangxia( sz ,  &i  ,  j  , p_h , &sum ); 
    	xiangyou( sz , i , &j , p_l , &sum );
    	xiangshang( sz ,  &i  ,  j   , &sum ); 
    	xiangzuo( sz , i , &j , &sum );
   }  
}
void shuru( int sz[][200] , int p_h , int p_l)
{
	int i , j ; 
	for( i = 0 ; i < p_h ; i ++)
	{
		for( j = 0 ; j < p_l ; j ++)
		{
			scanf("%d" ,&sz[i][j]);
		}
	}
}
