/*
问题描述
　　小明正在整理一批历史文献。这些历史文献中出现了很多日期。
小明知道这些日期都在1960年1月1日至2059年12月31日。令小明头疼的是，
这些日期采用的格式非常不统一，有采用年/月/日的，有采用月/日/年的，还有采用日/月/年的。
更加麻烦的是，年份也都省略了前两位，使得文献上的一个日期，存在很多可能的日期与其对应。


　　比如02/03/04，可能是2002年03月04日、2004年02月03日或2004年03月02日。


　　给出一个文献上的日期，你能帮助小明判断有哪些可能的日期对其对应吗？
输入格式
　　一个日期，格式是"AA/BB/CC"。 (0 <= A, B, C <= 9)
输出格式
　　输出若干个不相同的日期，每个日期一行，格式是"yyyy-MM-dd"。多个日期按从早到晚排列。
样例输入
02/03/04
样例输出
2002-03-04
2004-02-03
2004-03-02
数据规模和约定
　　峰值内存消耗（含虚拟机） < 256M
　　CPU消耗 < 1000ms




　　请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。


　　注意：
　　main函数需要返回0;
　　只使用ANSI C/ANSI C++ 标准;
　　不要调用依赖于编译环境或操作系统的特殊函数。
　　所有依赖的函数必须明确地在源文件中 #include <xxx>
　　不能通过工程设置而省略常用头文件。


　　提交程序时，注意选择所期望的语言类型和编译器类型。
*/
#include<stdio.h>
void shuchu( int , int , int );
int check( int , int , int );
int main( void )
{
	int y , m , d , zf ;
	scanf("%d%c%d%c%d", & y , &zf, & m , &zf,& d);
	shuchu( y , m , d );
	return 0 ; 
}
int check( int y, int m, int d)
{
	if( d == 29 && m == 2 )
	{
		if( (y % 4 == 0 && y %100 != 0)||( y %400 == 0 ))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

}
void shuchu( int y, int m, int d)
{
	int year , month , day ; 
	for( year = 1960 ; year < 2060 ; year ++ )
	{
		for( month = 1 ; month < 13 ; month ++ )
		{
			for( day = 1 ; day < 32 ; day ++ )
			{
				if( year%100 == y && month == m && day == d)
				{
					if( check( year , month , day))
					{
						printf("%d-%02d-%02d\n", year , month , day );
					}
				}
				if( month == y &&  day== m && year%100 == d && y != d )
				{
				 	printf("%d-%02d-%02d\n", year , month , day );
				} 
				if(day == y && month == m && year%100 == d && m != y)
				{
				 	printf("%d-%02d-%02d\n", year , month , day );
				}
			}
		}
	}
}
