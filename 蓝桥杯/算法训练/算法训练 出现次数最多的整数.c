/*
问题描述
　　编写一个程序，读入一组整数，这组整数是按照从小到大的顺序排列的，它们的个数N也是由用户输入的，最多不会超过20。然后程序将对这个数组进行统计，把出现次数最多的那个数组元素值打印出来。如果有两个元素值出现的次数相同，即并列第一，那么只打印比较小的那个值。
　　输入格式：第一行是一个整数N，N? ￡? 20；接下来有N行，每一行表示一个整数，并且按照从小到大的顺序排列。
　　输出格式：输出只有一行，即出现次数最多的那个元素值。
输入输出样例
样例输入
5
100
150
150
200
250
样例输出
150
*/
#include <stdio.h>
typedef
	struct
	{
		int zs ; 
		int cs ; 
	}
	shuju_t;
void shuru(shuju_t [] , int , int *);
int q_xb(shuju_t [] , int );
int main(void)
{
	int n , gs = 0 ;
	scanf("%d" ,&n);
	shuju_t sz[n];
	if( n > 0)
	{
		shuru(sz , n , &gs);
		printf("%d" ,sz[q_xb( sz , gs )].zs);
	} 
	return 0;
}
int q_xb( shuju_t sz[] ,int  n  )
{
    int i , max = 0;  
    for(i = 0 ; i < n ; i ++)  
    {  
        if( sz[i].cs > sz[max].cs)  
        {  
            max = i ;  
        }    
    }  
    return max ; 
}
void shuru(shuju_t sz[] , int n, int * p_gs)
{
	int xb = 0 ;
	scanf("%d", & sz[xb].zs );
	sz[xb].cs = 1 ;
	while( -- n > 0 )
	{
		int shu ;
		scanf("%d" ,&shu );
		if( shu == sz[xb].zs) 
		{
			sz[xb].cs ++ ;  
		}
		else
		{
			xb ++ ;
			sz[xb].zs = shu ;
			sz[xb].cs = 1 ;
		}
	}
	*p_gs = xb + 1 ;
}

