/*
问题描述
对于长度为5位的一个01串，每一位都可能是0或1，一共有32种可能。它们的前几个是：
00000
00001
00010
00011
00100
请按从小到大的顺序输出这32种01串。
输入格式
本试题没有输入。
输出格式
输出32行，按从小到大的顺序每行一个长度为5的01串。
样例输出
00000
00001
00010
00011
<以下部分省略>

*/ 
#include <stdio.h>
#include<stdlib.h>

void Ouput( int [] , int   ) ; 
int main(void) 
{
	int sz[5] = { 0 } ; 
//	FILE * fp = fopen ("cai.txt" , "w") ; 
	Ouput( sz , 0  ) ; 
	//fclose( fp ) ; 
	return 0;
}
void Ouput( int sz[] , int  i  )
{ 
	if(i == 5 )
	{

		int j ; 
		for( j = 0 ; j < 5 ; j ++ )
		{
			printf("%d" ,sz[j] ) ; 
		//	fprintf( fp , "%d" , sz[j] ) ;
		}
		//fputc('\n', fp); 
		putchar('\n') ; 
		return ; 
	}
	for( sz[i] = 0 ; sz[i] < 2 ; sz[i] ++ )
	{
		Ouput( sz  , i + 1   ) ;

	} 
} 
