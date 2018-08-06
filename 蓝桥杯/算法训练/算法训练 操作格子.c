/*
问题描述
有n个格子，从左到右放成一排，编号为1-n。
共有m次操作，有3种操作类型：
1.修改一个格子的权值，
2.求连续一段格子权值和，
3.求连续一段格子的最大值。
对于每个2、3操作输出你所求出的结果。
输入格式
第一行2个整数n，m。
接下来一行n个整数表示n个格子的初始权值。
接下来m行，每行3个整数p,x,y，p表示操作类型，p=1时表示修改格子x的权值为y，p=2时表示求区间[x,y]内格子权值和，p=3时表示求区间[x,y]内格子最大的权值。
输出格式
有若干行，行数等于p=2或3的操作总数。
每行1个整数，对应了每个p=2或3操作的结果。
样例输入
4 3
1 2 3 4
2 1 3
1 4 3
3 1 4
样例输出
6
3
数据规模与约定
对于20%的数据n <= 100，m <= 200。
对于50%的数据n <= 5000，m <= 5000。
对于100%的数据1 <= n <= 100000，m <= 100000，0 <= 格子权值 <= 10000。
*/
#if 1 
#include<stdio.h>
typedef
struct
{
	int left ; 
	int right ; 
	int  n  ;
	int sum ; 
}Gz_t ; 
int main(void)
{
	int n , m ; 
	scanf("%d%d" , & n , & m ) ;
	Gz_t sz[100000]; 
	Input( )
	return 0 ; 
}
#endif
