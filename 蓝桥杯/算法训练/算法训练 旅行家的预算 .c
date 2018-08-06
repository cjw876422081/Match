/*
问题描述
　　一个旅行家想驾驶汽车以最少的费用从一个城市到另一个城市（假设出发时油箱是空的）。
	给定两个城市之间的距离D1、汽车油箱的容量C（以升为单位）、每升汽油能行驶的距离D2、
	出发点每升汽油价格P和沿途油站数N（N可以为零），油站i离出发点的距离Di、
	每升汽油价格Pi（i=1，2，……N）。计算结果四舍五入至小数点后两位。如果无法到达目的地，
	则输出“No Solution”。
输入格式
　　第一行为4个实数D1、C、D2、P与一个非负整数N；
　　接下来N行，每行两个实数Di、Pi。
输出格式
　　如果可以到达目的地，输出一个实数（四舍五入至小数点后两位），表示最小费用；
`否则输出“No Solution”（不含引号）。
样例输入
275.6 11.9 27.4 2.8 2
102.0 2.9
220.0 2.2
样例输出
26.95
*/
#include<stdio.h>
double count_min_expense( double [] , double [] , int  ); 
int main( void )
{
	double D1 , C , D2 , P ;
	int n ;
	scanf("%lf%lf%lf%lf",&D1 , &C , &D2 , &P);
	scanf("%d",&n );
	double  distance[n+1] , price[n+1];
	double  maxv = C*D2 ; 
	int i ;
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%lf%lf",&distance[i] , &price[i]);
		if( distance[i] - distacne[i-1] > maxv &&  i > 0)
		{
			printf("No Solution\n");
		}
	}
	distance[n] = D1 ; 
	printf("%.2lf" ,count_min_expense( distance , price , n ));
	return 0;
} 
double count_min_expense( double p_d[] , double p_p[] , int n )
{
	while( )
}

