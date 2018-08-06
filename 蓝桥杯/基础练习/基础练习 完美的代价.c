/*
基础练习 完美的代价

问题描述
　　回文串，是一种特殊的字符串，它从左往右读和从右往左读是一样的。小龙龙认为回

文串才是完美的。现在给你一个串，它不一定是回文的，请你计算最少的交换次数使得该

串变成一个完美的回文串。
　　交换的定义是：交换两个相邻的字符
　　例如mamad
　　第一次交换 ad : mamda
　　第二次交换 md : madma
　　第三次交换 ma : madam (回文！完美！)
输入格式
　　第一行是一个整数N，表示接下来的字符串的长度(N <= 8000)
　　第二行是一个字符串，长度为N.只包含小写字母
输出格式
　　如果可能，输出最少的交换次数。
　　否则输出Impossible
样例输入
5
mamad
5
mamad
样例输出
3
*/
#include<stdio.h>  
#define N 8000  

void shuchu( int ,char []);
void huan( char [] , int , int );
int main(void)
{  
	int n;  
    char zf[N];
    scanf("%d%s",&n ,zf);  
    shuchu( n , zf );
    return 0;  
      
}  
void huan( char zf[] , int p_k, int p_j)
{
	int i;
	for( i = p_k ; i < p_j ; i ++ )
	{
		char tmp = zf[i];
		zf[i] = zf[i+1] ;
		zf[i+1] = tmp ; 
	}
}
void shuchu( int n ,char zf[])
{
	int i , j = n - 1 ; 
	int dzfgs = 0 , bs = 0;  
    for(i = 0 ; i <  j  ; i ++)
	{  
		int t = j ;
        while( zf[i] != zf[t] )  
		{  
            t--;  
    	}  
        if( i == t )
		{      
            dzfgs ++ ;  
            if( n % 2 == 0 || dzfgs > 1)
			{  
                printf("Impossible\n");  
                return ;  
            }  
            bs += n/2 - i ;  
            continue;   
        }  
        if( zf[i] == zf[t])
		{  
          
            bs += j - t ;  
			huan(zf , t , j );  
            j -- ;  
        }  
    }     
    printf("%d",bs);  
}
