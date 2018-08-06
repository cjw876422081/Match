/*
问题描述
　　元旦快到了，校学生会让乐乐负责新年晚会的纪念品发放工作。为使得参加晚会的同学所获得的纪念品价值 相对均衡，
他要把购来的纪念品根据价格进行分组，但每组最多只能包括两件纪念品，并且每组纪念品的价格之和不能超过一个给定的整数。
为了保证在尽量短的时 间内发完所有纪念品，乐乐希望分组的数目最少。
　　你的任务是写一个程序，找出所有分组方案中分组数最少的一种，输出最少的分组数目。
输入格式
　　输入包含n+2行：
　　第1行包括一个整数w，为每组纪念品价格之和的上限。
　　第2行为一个整数n，表示购来的纪念品的总件数。
　　第3~n+2行每行包含一个正整数pi (5 <= pi <= w)，表示所对应纪念品的价格。
输出格式
　　输出仅一行，包含一个整数，即最少的分组数目。
样例输入
100
9
90
20
20
30
50
60
70
80
90
样例输出
6
数据规模和约定
　　50%的数据满足：1 <= n <= 15
　　100%的数据满足：1 <= n <= 30000, 80 <= w <= 200
*/
#include<stdio.h>
void shuru( int [] , int  );
void shuchu( int [] , int , int );
void paixu( int [] , int , int );
int main( void )
{
	int w , n ,sz[30000]; 
    scanf("%d%d" , & w , & n );
    shuru( sz , n );
    paixu( sz , 0 , n - 1 );
	shuchu( sz , n , w );
    return 0;
}  
void paixu( int sz[] , int left , int  right)
{
	if( left >= right)
	{
		return ;
	}
	int i = left , j  = right ; 
	int key = sz[left] ;
	while ( i < j)
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
		sz[j] = sz[i];
	}
	sz[i] = key ;
	paixu( sz , left, i - 1 );
	paixu( sz , i + 1 , right ); 
}
void shuchu( int sz[] , int n , int p_w)
{
	int cs = 0 , i = 0 ;  
    int  j  = n - 1;  
    while(i <=  j ) 
	{  
        if(sz[i] + sz[j] <= p_w )
		{
			i ++ ;
		}
		j -- ;  
        cs ++ ;  
    }  
    printf("%d\n" , cs );
}
void shuru( int sz[] , int n)
{
	int i ; 
	for( i = 0 ; i <  n  ; i ++ )
	{
		scanf("%d", &sz[i]);
	}
    
}
