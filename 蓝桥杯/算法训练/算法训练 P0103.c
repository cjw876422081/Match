/*
  
　　从键盘输入一个大写字母，要求改用小写字母输出。
输入
　　A
输出
　　a
*/ 
#include <stdio.h>

int main(void)
{
	char c;
	scanf("%c",&c);
	printf("%c",c^32) ;
    return 0;
}

