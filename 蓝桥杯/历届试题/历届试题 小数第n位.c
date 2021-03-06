
/*
问题描述
　　我们知道，整数做除法时，有时得到有限小数，有时得到无限循环小数。
　　如果我们把有限小数的末尾加上无限多个0，它们就有了统一的形式。
　　本题的任务是：在上面的约定下，求整数除法小数点后的第n位开始的3位数。
输入格式
　　一行三个整数：a b n，用空格分开。a是被除数，b是除数，n是所求的小数后位置（0<a,b,n<1000000000）
输出格式
　　一行3位数字，表示：a除以b，小数后第n位开始的3位数字。
样例输入
1 8 1
样例输出
125
样例输入
1 8 3
样例输出
500
样例输入
282866 999000 6
样例输出
914
*/
#include<stdio.h>
int main( void )
{
    long long  a , b , n ;  
    scanf("%lld%lld%lld", & a ,& b , & n ); 
    a %= b ; 
	while( n - 10 > 0 ) 
	{
		a *= 1e10;
		a %= b  ;   
		n -= 10 ; 
	}
	int i ;
	for( i = 0 ; i < n + 2  ; i ++  )
	{
		a *= 10 ;
		if( i >= n - 1)
		{
			printf("%lld", a / b );
		}
		a %= b ; 
	} 
    return 0;  
} 
