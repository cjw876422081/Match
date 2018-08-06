/*
问题描述
样例输入
一个满足题目要求的输入范例。
3 10
样例输出
与上面的样例输入对应的输出。
数据规模和约定
　　输入数据中每一个数的范围。
　　例：结果在int表示时不会溢出。
*/

#include<stdio.h>
int ditui( int , int );
int main(void )
{
	int n , m ;
	scanf("%d%d", &n , &m);
	printf("%d",ditui( n , m));
	return 0;
} 
int ditui( int n , int  m )
{
	if( n == 0 || n == m)
	{
		return 1;
	}
	return ditui( n , m - 1)+ditui( n - 1 , m - 1);
}
