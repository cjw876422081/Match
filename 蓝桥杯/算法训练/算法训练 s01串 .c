	/*问题描述
　　s01串初始为"0"
　　按以下方式变换
　　0变1，1变01
输入格式
　　1个整数(0~19)
输出格式
　　n次变换后s01串
样例输入
    3                  
样例输出
    101
数据规模和约定
    0~19*/
#include<stdio.h>
#include<string.h> 
void shuchu( char * , char * , int  , int ) ;
int main(void) 
{
	int n;
	scanf("%d",&n);
	char s1[1000000] = "1" , s2[1000000] = "01"; 
	shuchu( s1 , s2 , n ,  1 );
	return 0;
} 

void shuchu( char * s1 , char * s2 , int n , int i )
{
	if( n == 0 )
	{
		putchar('0');
		return ;
	}
	if( n == 1 )
	{
		puts(s1);
		return ;
	}
	if( i == n )
	{
		puts( s1 );
		return ;
	}
	shuchu( s2 , strcat( s1 , s2 ) , n ,  i + 1 ); 
}
