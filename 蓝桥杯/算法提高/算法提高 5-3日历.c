/*问题描述
　　已知2007年1月1日为星期一。设计一函数按照下述格式打印2007年以后（含）某年某月的日历，
	2007年以前的拒绝打印。为完成此函数，设计必要的辅助函数也是必要的。
样例输入
一个满足题目要求的输入范例。
例：

2050 3
样例输出
与上面的样例输入对应的输出。
例：
*/
/*
Calendar 2050 - 03
---------------------
Su Mo Tu We Th Fr Sa
---------------------
       1  2  3  4  5
 6  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30 31
---------------------*/
#include<stdio.h>
void shuchu( int , int );
int js_day( int , int  ); 
int main( void )
{
	int year , month ;
	scanf("%d%d",&year, &month );
	shuchu( year, month );
	return 0 ; 
} 
int js_day( int year, int  month )
{
	int i , day = 0 ; 
	for( i = 2007 ; i < year ;i ++ )
	{
	
		if( (i % 4 == 0 && i %100 != 0)||(  i%400 == 0 ) )
		{
			day ++ ;
		}
		day += 365 ;
	} 
	int yfts[12] = {31 ,28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
	for( i = 0 ; i < month - 1 ; i ++ )
	{
		
		if((year % 4 == 0 && year %100 != 0)||( year %400 == 0 ) )
		{
			if( i == 2 )
			{
				day ++ ; 
			} 
		}
		day += yfts[i] ; 
	}
	return day ;
}
void shuchu( int year , int month )
{
	printf("Calendar %d - %02d\n", year , month );
	printf("---------------------\n");  
    printf(" Su Mo Tu We Th Fr Sa\n");  
    printf("---------------------\n"); 
	int i , day = js_day( year , month )  ;
	i = day % 7 ;
	while( i -- >= 0 )
	{
		printf("   ");
	} 
	int j , xq = day % 7 + 1 ;
	int d[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	for( j = 1 ; j <= d[month] ;  j ++ )
	{
		printf("%3d",j);
		if( xq % 7 == 6 && j != d[month] ) 
		{
			printf("\n");
		}
		xq ++ ; 
	} 
	if((year % 4 == 0 && year %100 != 0)||( year %400 == 0 ) )
	{
		if( month == 2  )
		{
			printf("%3d", j ); 
		} 
	}
	printf("\n---------------------\n");
}
