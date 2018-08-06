/*
问题描述
　　给两组数，各n个。
　　请调整每组数的排列顺序，使得两组数据相同下标元素对应相乘，然后相加的和最小。要求程序输出这个最小值。
　　例如两组数分别为:1 3　　-5和-2 4 1

　　那么对应乘积取和的最小值应为：
　　(-5) * 4 + 3 * (-2) + 1 * 1 = -25
输入格式
　　第一个行一个数T表示数据组数。后面每组数据，先读入一个n，接下来两行每行n个数，每个数的绝对值小于等于1000。
　　n<=1000,T<=10
输出格式
　　一个数表示答案。
样例输入

2
3
1 3 -5
-2 4 1
5
1 2 3 4 5
1 0 1 0 1


样例输出

-25
6


*/
#include <stdio.h>  
void paixu( int [] , int , int ) ; 
void shuru( int [] , int [] , int *);
void shuchu( int [] , int [] , int );
int main( void )  
{  
    int T ;  
    int s1[1000] , s2[1000];   
    scanf("%d",& T ) ;  
    while( T -- > 0 )  
    {  
        int n ; 
		shuru( s1 , s2 , &n ) ; 
        paixu( s1 , 0 , n - 1 );  
        paixu( s2 , 0 , n - 1 );
		shuchu( s1 , s2  , n );  
    }  
    return 0;  
}  
void shuchu( int s1[] , int s2[] , int p_n)
{
	int i , sum = 0 ; 
    for( i = 0 ; i < p_n ; i ++)  
    {  
        sum += s1[i] * s2[p_n - 1 - i ];  
    }  
    printf("%d\n",sum);  
}
void shuru( int s1[] , int s2[] , int * p_n)
{
    scanf("%d" , p_n) ; 
	int i ;  
    for(i = 0 ; i < * p_n ; i ++ )  
    {  
        scanf("%d" , & s1[i]);  
    }  
    for(i = 0 ; i < * p_n ; i ++ )  
    {  
        scanf("%d" , & s2[i]);  
    }  
}
void paixu( int sz[] , int  left , int  right)
{
	if( left  >=  right )
	{
		return ;
	}
	int i = left ; 
	int j = right ; 
	int key = sz[left];
	while( i < j )
	{
		while( i < j  && key <= sz[j])
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
	paixu( sz, left , i - 1 );
	paixu( sz , i + 1 , right);

}

