/*
问题描述
　　任何一个正整数都可以用2进制表示，例如：137的2进制表示为10001001。
　　将这种2进制表示写成2的次幂的和的形式，令次幂高的排在前面，可得到如下表达式：137=2^7+2^3+2^0
　　现在约定幂次用括号来表示，即a^b表示为a（b）
　　此时，137可表示为：2（7）+2（3）+2（0）
　　进一步：7=2^2+2+2^0 （2^1用2表示）
　　3=2+2^0 
　　所以最后137可表示为：2（2（2）+2+2（0））+2（2+2（0））+2（0）
　　又如：1315=2^10+2^8+2^5+2+1
　　所以1315最后可表示为：
　　2（2（2+2（0））+2）+2（2（2+2（0）））+2（2（2）+2（0））+2+2（0）
输入格式
　　正整数（1<=n<=20000）
输出格式
　　符合约定的n的0，2表示（在表示中不能有空格）
样例输入
137
样例输出
2(2(2)+2+2(0))+2(2+2(0))+2(0)
样例输入
1315
样例输出
2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
提示
　　用递归实现会比较简单，可以一边递归一边输出
*/
#include <stdio.h>
void sc_2cm(int );
void zhuanhuan( int , int [] , int *);
int main (void)  
{      
    int n;    
    scanf("%d",&n);  
    sc_2cm( n );
    return 0;    
}    
void zhuanhuan( int p_n, int sz[] , int * p_ws)
{
	int sum = 0 ; 
	while( p_n != 0 )  
    {   
        if(p_n % 2 == 1)  
        {    
            sz[* p_ws ] = sum ;
            ++ * p_ws ; 
        }    
        sum ++;    
        p_n /= 2;    
    }   
}
void sc_2cm(int n)
{    
    int sz[30];
    int sum = 0 ;
	int ws = 0 ;
	int i ; 
	zhuanhuan( n , sz , &ws )   ;
    for(i = ws - 1 ; i >= 0 ; i --)  
    {    
        if(sz[i] == 0)  
        {    
            printf("2(0)");    
        }    
        else if(sz[i] == 1)  
        {    
            printf("2");    
        } 
        else if(sz[i] >= 2) 
        {    
            printf("2(");    
            sc_2cm(sz[i]);    
            printf(")");  
        }    
        if( i != 0 )
        {    
            printf("+");  
        }  
    }    
}    
