/*　　
根据输入的正整数n (1　　米字形由一个(2n-1)*(2n-1)的矩阵组成，矩阵包含从大写A开始的n个字母
　　例如:n=3时，包含A,B,C；n=4时，包含A,B,C,D。
　　矩阵的正中间为n个字母中字典序最大的那个，
从这个字母开始，沿着西北、正北、东北、正西、正东、西南、正南、东南八个方向各有一条由4大写字母组成的直线。
并且直线上的字母按字典序依次减小，直到大写字母A。
　　矩阵的其它位置用英文句号．填充。

　　样例输入一
　　3

　　样例输出一
　　Ａ．Ａ．Ａ
　　．ＢＢＢ．
　　ＡＢＣＢＡ
　　．ＢＢＢ．
　　Ａ．Ａ．Ａ

　　样例输入二
　　4

　　样例输出二
　　Ａ．．Ａ．．Ａ
　　．Ｂ．Ｂ．Ｂ．
　　．．ＣＣＣ．．
　　ＡＢＣＤＣＢＡ
　　．．ＣＣＣ．．
　　．Ｂ．Ｂ．Ｂ．
　　Ａ．．Ａ．．Ａ
*/
#include<stdio.h>
void Output( int );
int draw(int , int , int ) ;
int main(void)
{
	int n ; 
	scanf("%d", &n ) ; 
	Output( 2 * n - 1  );
	return 0 ; 
}
int draw(int i, int j, int n)  
{  
    int r;  
      
    if( i > n / 2 )
	{  
        i = n - i - 1;  
    }  
    if( j > n / 2 )
	{  
        j = n - j - 1;  
    }  
    if( i == n / 2 )
	{  
        i = j;  
    }  
    if( j == n / 2 )
	{  
        j = i;  
    }  
    if( i == j )
	{  
        r = i;  
    }
	else
	{  
        r = -1;  
    }  
    return r;  
} 
void Output( int n )
{
	int i , j , k ;
	for(i = 0; i < n; i ++)
	{  
        for(j = 0; j < n; j ++)
		{  
            k = draw(i, j , n);  
            if(k < 0)
			{  
                printf(".");  
			}
			else
			{  
                printf("%c",'A' + k );  
            }  
        }  
        printf("\n");  
    }  
} 
