/*
问题描述
　　Torry从小喜爱数学。一天，老师告诉他，像2、3、5、7……这样的数叫做质数。Torry突然想到一个问题，
前10、100、1000、10000……个质数的乘积是多少呢？他把这个问题告诉老师。老师愣住了，一时回答不出来。
于是Torry求助于会编程的你，请你算出前n个质数的乘积。不过，考虑到你才接触编程不久，Torry只要你算出这个数模上50000的值。
输入格式
　　仅包含一个正整数n，其中n<=100000。
输出格式
　　输出一行，即前n个质数的乘积模50000的值
样例输
1
样例输出
2
*/
#include<stdio.h>  
#include<stdbool.h>

long long jisuan(  int );
bool pd_zs( int );
int main( void )  
{  
    int n;  
    scanf("%d",&n);  
    printf("%lld\n",jisuan( n ));  
    return 0;  
}
long long jisuan(  int  n )
{
	int sum = 0 , i = 2 ;
	long long shu = 1  ;
	while(sum < n)  
    {  
        if(pd_zs( i ) == true )  
        {  
            shu = shu * i % 50000;  
            sum ++ ;  
        }  
        i ++ ;  
    }  
    return shu ;
}  
bool pd_zs( int  n)  
{  
	int i ; 
    for( i = 2 ; i * i <= n ; i ++)  
    {  
        if( n % i == 0 ) 
		{
			return false ;  
		} 
            
    }  
    return true;  
}  
