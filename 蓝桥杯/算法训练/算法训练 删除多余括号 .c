/*问题描述
　　从键盘输入一个含有括号的四则运算表达式，要求去掉可能含有的多余的括号，结果要保持原表达式中变量和运算符的相对位置不变，且与原表达式等价,不要求化简。另外不考虑'+'　　'-'用作正负号的情况，即输入表达式不会出现(+a)或(-a)的情形。
输入格式
　　表达式字符串，长度不超过255,　　并且不含空格字符。表达式中的所有变量都是单个小写的英文字母, 运算符只有加+减-乘*除/等运算符号。
输出格式
　　去掉多余括号后的表达式
样例输入

样例一：
a+(b+c)-d
样例二：
a+b/(c+d)
样例三：
(a*b)+c/d
样例四：
((a+b)*f)-(i/j)
样例输出
样例一：
a+b+c-d
样例二：
a+b/(c+d)
样例三：
a*b+c/d
样例四：
(a+b)*f-i/j
*/ 
#if 1 
#include<string.h>
void Output( char [] ) ;
int Solve( char [] , int ) ;  
int pd( char [] ,  int , int );
int main(void)
{
	char zf[256]; 
	gets( zf );
	Solve( zf , 0  ); 
	Output( zf ) ;  
	return 0 ; 
}
int pd( char zf[] , int left, int right )
{
	int i , leftAcount ;
    if( zf[ left - 1 ] == '-')
	{    

        i = left;
        leftAcount = 1;
        while( ++ i < right)
		{
            if(zf[i] == '(') 
			{
				leftAcount ++;
			}
            if(zf[i] == '+' && leftAcount == 1) 
			{
				return 0;
		    } 
        }
    }
    if( zf[ left - 1 ] == '/')
	{
		return 0;    	
	} 
    if(zf[ left - 1 ] != '*' && zf[ left - 1 ] != '/' && zf[ right + 1 ] != '*' && zf[ right + 1 ] != '/')
	{
	   return 1;
	} 


    i = left ;
    leftAcount = 1;
    while(++i < right)
	{
        if(zf[i] == '(') 
		{
			leftAcount ++;
		}
        if(zf[i] == '*' && leftAcount == 1)
		{
			return 1;	
		}  
    }


    return 0;
}
int Solve( char zf[]  , int i  ) 
{
	int left , right ; 
	while( zf[i] != '\0')
	{
		if( zf[i] == ')')
		{
			return i ; 
		}
		if( zf[i] == '(')
		{
			left = i ; 
			right = Solve( zf , i + 1  ) ;
			i = right ;  
			if( pd( zf , left , right ))
			{
				zf[left] = ' ' ;
				zf[right] = ' ' ;  
			}
		}
		i ++ ; 	
	} 
}
void Output( char zf[] ) 
{
	int i = 0 ;   
	while( zf[ i ] != '\0')
	{
		
        if(zf[i] != ' ')
		{
            putchar(zf[i]);
        }
        i ++ ; 
    }
}
#endif 
