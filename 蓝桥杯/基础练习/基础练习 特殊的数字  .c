/*
问题描述
　　153是一个非常特殊的数，它等于它的每位数字的立方和，即153=1*1*1+5*5*5+3*3*3。编程求所有满足这种条件的三位十进制数。
输出格式
　　按从小到大的顺序输出满足条件的三位十进制数，每个数占一行。

*/ 
#include <stdio.h>
int q_lfh( int );

int main(void) 
{
	int i;
	for(i=100; i<1000; i++)
	{
		if(q_lfh(i)==i) 
		{
			printf("%d\n",i);
		}
	}
	return 0;
}

int q_lfh( int n ) 
{
	int he=0;
	do
	{
		he+=(n%10)*(n%10)*(n%10);
	}
	while((n/=10)!=0);
	return he;
}

