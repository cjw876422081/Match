/*
　　编写一程序，在屏幕上输出如下内容：
　　X | X | X
　　---+---+---
　　| |
　　---+---+---
　　O | O | O
　　注意：本题请同学们严格按照图形的格式输出，对齐，其中X和O为大写，否则系统会判为错误。
*/
#include <stdio.h>
void shuchu(char *[]  , int );
int main(void) 
{
	char *zf[]={"X | X | X",
				 "---+---+---",
				 "| |",
				 "---+---+---",
				 "O | O | O",};
	shuchu( zf , sizeof zf / sizeof * zf) ;
    return 0;
}
void shuchu(char *zf[]  , int n)
{
	if( n > 0)
	{
		puts(*zf);
		shuchu(zf+1 , n-1);
	}
}
