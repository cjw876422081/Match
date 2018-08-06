/*
编写函数GetReal和GetString，在main函数中分别调用这两个函数。在读入一个实数和一个字符串后，将读入的结果依次用printf输出。
　　两次输入前要输出的提示信息分别是"please input a number:\n”和"please input a string:\n"
样例输入
9.56
hello
样例输出
please input a number:
please input a string:
9.56
hello
*/
#include<stdio.h>
void GetReal( double * ); 
void GetString( char *);
int main( void )
{
	double n ;
	char zf[128];
	GetReal(&n); 
	GetString(zf);
	printf("please input a number:\n");
	printf("please input a string:\n");
	printf("%.2lf\n", n );
	printf("%s\n" , zf);
	return 0 ; 
}
void GetReal( double * n)
{
	scanf("%lf", n );
}
void GetString( char * zf)
{
	scanf("%s", zf );
}
