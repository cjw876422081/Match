/*
问题描述
利用字母可以组成一些美丽的图形，下面给出了一个例子：
ABCDEFG
BABCDEF
CBABCDE
DCBABCD
EDCBABC
这是一个5行7列的图形，请找出这个图形的规律，并输出一个n行m列的图形。
输入格式
输入一行，包含两个整数n和m，分别表示你要输出的图形的行数的列数。
输出格式
输出n行，每个m个字符，为你的图形。
样例输入
5 7
样例输出
ABCDEFG
BABCDEF
CBABCDE
DCBABCD
EDCBABC
数据规模与约定
1 <= n, m <= 26。
*/

#include<stdio.h>
void shuchu( char [][26] , int , int  );

int main(void )
{
	int n, m ;
	scanf("%d%d", &n , &m );
	char sz[100][26]={0};
	shuchu( sz ,  n , m );
	return 0;
} 
void shuchu( char sz[][26] , int n, int  m)
{
	int i , j ;
	for(i = 0 ; i < n ; i ++)
	{
		char str='A';
		for(j = i ; j < m ; j ++)
		{
        	sz[i][j] = str++;  
		}
		str='A';
       	for(j = i - 1;j >= 0;j --)  
        {  
            sz[i][j] = ++str;
        }
	}
	for(i = 0 ; i < n ; i ++)
	{
		for(j = 0 ; j < m ; j ++)
		{
			printf("%c",sz[i][j]);
		}
		putchar('\n');
	}
}
