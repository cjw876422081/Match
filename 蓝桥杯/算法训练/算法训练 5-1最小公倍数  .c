/*
问题描述
　　编写一函数lcm，求两个正整数的最小公倍数。
样例输入
一个满足题目要求的输入范例。
例：

3 5
样例输出
与上面的样例输入对应的输出。
例：
数据规模和约定
　　输入数据中每一个数的范围。
　　例：两个数都小于65536。

*/ 
#include <stdio.h>
int qiu_zdgys(int ,int );

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",(m*n)/qiu_zdgys(n,m)) ;
    return 0;
}
int qiu_zdgys(int n,int m)
{
	if(n % m == 0)
	{
		return m;
	}
	return qiu_zdgys(m,n % m);
}
