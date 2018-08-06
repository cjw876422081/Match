/*


问题描述
　　求出区间[a,b]中所有整数的质因数分解。
输入格式
　　输入两个整数a，b。
输出格式
　　每行输出一个数的分解，形如k=a1*a2*a3...(a1<=a2<=a3...，k也是从小到大的)(具体可看样例)
样例输入
3 10
样例输出
3=3
4=2*2
5=5
6=2*3
7=7
8=2*2*2
9=3*3
10=2*5
提示
　　先筛出所有素数，然后再分解。
数据规模和约定
　　2<=a<=b<=10000

*/
#include<stdio.h>
void shuchu( int , int );
int main(void)
{
	int a , b ;
	scanf("%d%d" , & a , & b );
	while( a  <= b )
	{
		printf("%d=" , a);
		shuchu( a ,2);
		putchar('\n');
		a++;
	} 
	return 0;
}
void shuchu( int  n , int ys )
{
	if( n % ys != 0 )
	{
		shuchu( n  , ys +1);
		return ;
	} 
	printf("%d",ys);
	if( n / ys !=1)
	{
		putchar('*');
		shuchu( n / ys  , ys);
	}
}
