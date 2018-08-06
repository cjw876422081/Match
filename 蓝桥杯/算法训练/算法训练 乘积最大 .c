/*
问题描述
　　今年是国际数学联盟确定的“2000——世界数学年”，又恰逢我国著名数学家华罗庚先生诞辰90周年。
在华罗庚先生的家乡江苏金坛，组织了一场别开生面的数学智力竞赛的活动，你的一个好朋友XZ也有幸得以参加。
活动中，主持人给所有参加活动的选手出了这样一道题目：
　　设有一个长度为N的数字串，要求选手使用K个乘号将它分成K+1个部分，找出一种分法，
使得这K+1个部分的乘积能够为最大。
　　同时，为了帮助选手能够正确理解题意，主持人还举了如下的一个例子：
　　有一个数字串：312， 当N=3，K=1时会有以下两种分法：
　　3*12=36
　　31*2=62
　　这时，符合题目要求的结果是：31*2=62
　　现在，请你帮助你的好朋友XZ设计一个程序，求得正确的答案。
输入格式
　　程序的输入共有两行：
　　第一行共有2个自然数N，K（6≤N≤40，1≤K≤6）
　　第二行是一个长度为N的数字串。
输出格式
　　输出所求得的最大乘积（一个自然数）。
　　样例输入
4 2
1231
样例输出
62
*/
#include<stdio.h>
#include<math.h>
void zhuanhuan( int [] , char [] , int );
long long jisuan( int [] , int , int  );
long long mc_10( int ) ; 
int main( void )
{
	int n , k ;
	scanf("%d%d\n",&n ,&k );
	char zf[42];
	int sz[40];
	gets( zf );
	zhuanhuan( sz , zf , n );
	printf("%lld\n", jisuan( sz , n , k ));
	return 0;
}
long long mc_10( int n )
{
	int x = 1 ;
	while( n -- )
	{
		x *= 10 ;
	}
	return x ; 
}
long long jisuan( int sz[] , int n , int k )
{
	long long max = 0 ;
	int i , j ;  
	if( k == 0 )
	{
		for( i = 0 ; i < n ; i ++ )
		{
			max += sz[i] * mc_10( n - 1 - i ); 
		} 
	}
	else 
	{
		for ( i = 0 ; i <= n - k ; i ++ )     
        {  
            int num = 0;                                    
            long long jg = 0;           
            for ( j = n - i - 1; j < n ; j ++ )      
            {  
                num += sz[j] * mc_10( n - j - 1); 
            }  
            jg = num * jisuan( sz , n - i - 1 , k - 1);  
            max = jg > max ? jg : max ;  
        }  
	}
	return max ; 
}
void zhuanhuan( int sz[] , char zf[] , int n)
{
	int i ; 
	for( i = 0 ; i < n ; i ++ )
	{
		sz[i] = zf[i] - '0' ; 
	}
}
