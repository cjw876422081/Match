/*

问题描述
　　编写一个程序，读入一组整数（不超过20个），当用户输入0时，表示输入结束。
	然后程序将从这组整数中，把第二大的那个整数找出来，并把它打印出来。
	说明：（1）0表示输入结束，它本身并不计入这组整数中。（2）在这组整数中，既有正数，也可能有负数。（3）这组整数的个数不少于2个。
　　输入格式：输入只有一行，包括若干个整数，中间用空格隔开，最后一个整数为0。
　　输出格式：输出第二大的那个整数。
　　输入输出样例
样例输入
5 8 -12 7 0

样例输出
7

*/
#include<stdio.h>
void shuru(int [] , int *) ; 
void shuchu( int [] , int );
void huan( int * ,int *);
int main(void )
{
	int sz[20+1];
	int ws = 0; 
	shuru( sz , &ws);
	shuchu(sz , ws );
	return 0;
}
void huan( int * a ,int * b)
{
	int tmp = *a ;
	*a = * b ;
	*b = tmp ;
}
void shuchu( int sz[] , int p_ws)
{
	int i ,j ; 
	for( i = 0 ; i < 2 ; i ++ )
	{
		for( j = i + 1 ; j < p_ws ; j ++ )
		{
			if( sz [i] <  sz[j])
			{
				huan( &sz[i] , &sz[j] );
			}
			
		}
	} 
	printf("%d" ,sz[1]);
}
void shuru(int sz[] , int *p_ws)
{
	int i ; 
	for( i = 0 ; scanf("%d",&sz[i]) && sz[i]!= 0 ; i ++)
	{
		++ * p_ws;
	}
}
