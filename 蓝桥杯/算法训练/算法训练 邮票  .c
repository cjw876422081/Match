/*问题描述
　　给定一个信封，有N（1≤N≤100）个位置可以贴邮票，每个位置只能贴一张邮票。
我们现在有M(M<=100)种不同邮资的邮票，面值为X1,X2….Xm分（Xi是整数，1≤Xi≤255），每种都有N张。
　　显然，信封上能贴的邮资最小值是min(X1, X2, …, Xm)，最大值是 N*max(X1, X2, …,　　Xm)。
由所有贴法得到的邮资值可形成一个集合（集合中没有重复数值），要求求出这个集合中是否存在从1到某个值的连续邮资序列，输出这个序列的最大值。
　　例如，N=4，M=2，面值分别为4分，1分，于是形成1，2，3，4，5，6，7，8，9，10，12，13，16的序列，
而从1开始的连续邮资序列为1，2，3，4，5，6，7，8，9，10，所以连续邮资序列的最大值为10分。
输入格式
　　第一行：最多允许粘贴的邮票张数N；第二行：邮票种数M；第三行：空格隔开的M个数字，表示邮票的面值Xi。
注意：Xi序列不一定是大小有序的！
输出格式
　　从1开始的连续邮资序列的最大值MAX。若不存在从1分开始的序列（即输入的邮票中没有1分面额的邮票），
则输出0.
样例输入
样例一：
4
2
4 1
样例二：
10
5
2 4 6 8 10
样例输出
样例一：
10
样例二：
0
20
10
1 14 101 116 144 168 178 228 242 247

*/
#include<stdio.h>  
void shuru( int [] , int );
void shuchu( int [], int );
int q_max( int [] , int );
void chushihua( int [] , int );
void jisuan(int [] , int [] , int , int ,int  );
void fr_yp( int [] , int [] , int , int  );
int main( void ) 
{  
	int n , m , max ; 
	scanf("%d%d" ,& n , & m ) ;
	int sz[m] ;  
	shuru( sz ,  m );
	max = q_max( sz , m ) ;
	int cf[ n * max + 1] ; 
	chushihua( cf , n * max + 1 );
	cf[0] = 1 ;
	jisuan( cf , sz , n , m , max );
    shuchu( cf , n * max + 1 );
	return 0;  
}  
void chushihua( int cf[] , int n)
{
	int i ; 
	for(i = 0 ; i < n ; i ++ )
	{
		cf[i] = 0 ; 
	}	
}
void jisuan(int cf[] , int sz[] , int n , int m , int max )
{
	int i ; 
	for( i = 0 ; i < n ; i ++ )
	{
		int  j ; 
		for( j = i * max ; j >= 0 ; j -- )
		{
			if( cf[j] == 1 )
			{
				fr_yp( cf , sz , m , j );
			}
		}
	}
}
void fr_yp( int cf[] , int sz[] , int m , int cs )
{
	int i ; 
	for( i = 0 ; i < m ; i ++)
	{
		cf[cs + sz[i]] = 1 ; 
	}
}
int q_max( int sz [] , int n)
{
	int i , max = 0 ; 
	for( i = 0 ; i < n ; i ++ )
	{
		if( sz[i] > sz[max])
		{
			max = i ; 
		}
	}
	return sz[max] ; 
}
void shuchu( int sz[] , int n  )
{
	int i ; 
	for(i = 0 ; i < n ; i ++ )
	{
		if( sz[i] == 0 )
		{
			printf("%d\n" , i - 1);
			return ; 
		}
	}
}

void shuru( int sz[] , int n)
{
	int i ;
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d", & sz[i]);
	}
}
