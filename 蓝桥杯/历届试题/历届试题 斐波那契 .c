/*问题描述
　　斐波那契数列大家都非常熟悉。它的定义是：

　　f(x) = 1 .... (x=1,2)
　　f(x) = f(x-1) + f(x-2) .... (x>2)

　　对于给定的整数 n 和 m，我们希望求出：
　　f(1) + f(2) + ... + f(n) 的值。但这个值可能非常大，所以我们把它对 f(m) 取模。
　　公式如下
　　但这个数字依然很大，所以需要再对 p 求模。
输入格式
　　输入为一行用空格分开的整数 n m p (0 < n, m, p < 10^18)
输出格式
　　输出为1个整数，表示答案
样例输入
2 3 5
样例输出
0
样例输入
15 11 29
样例输出
*/
#include<stdio.h>
long long q_shu( long long );
void  shuchu( long long , long long , long long );
int main( void )
{	
	long long n , m  , p ;
	scanf("%lld%lld%lld", &n , &m, &p );
	shuchu( n, m, p );
	return 0 ; 
} 
long long q_shu( long long n )
{
	if( n == 1 || n == 2 )  
	{  
		return 1 ;  
	}  
	return q_shu( n - 1) + q_shu( n - 2 ) ; 
}
void  shuchu( long long n, long long m, long long p)
{
	long long  i  , sum = 0 ; 
	for(i = 1 ; i <= n ; i ++)
	{
		sum += q_shu( i );
	} 
	printf("%d\n", (sum % q_shu( m )) % p );
}
