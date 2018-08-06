/*
问题描述
　　相信经过这个学期的编程训练，大家对于字符串的操作已经掌握的相当熟练了。
今天，徐老师想测试一下大家对于字符串操作的掌握情况。
徐老师自己定义了1,2,3,4,5这5个参数分别指代不同的5种字符串操作，你需要根据传入的参数，按照徐老师的规定，对输入字符串进行格式转化。
　　徐老师指定的操作如下：
　　1 表示全部转化为大写字母输出，如abC 变成 ABC
　　2 表示全部转换为小写字母输出，如abC变成abc
　　3 表示将字符串整个逆序输出，如 abc 变成 cba
　　4 表示将字符串中对应的大写字母转换为小写字母，而将其中的小写字母转化为大写字母输出，如 abC变成ABc
　　5表示将全部转换为小写字母，并将其中所有的连续子串转换为对应的缩写形式输出，比如abcD 转换为a-d，
其次，-至少代表1个字母，既如果是ab，则不需要转换为缩写形式。
输入格式
　　一共一行，分别是指代对应操作的数字和字符串，两者以空格分隔，字符串全部由英文字母组成
输出格式
　　输出根据上述规则转换后对应的字符串
样例输入
5 ABcd
样例输出
a-ee
数据规模和约定
　　输入字符串长度最长为200。
*/
#include<stdio.h>
#include<string.h>
void shuchu( int , char []);
void sc_one( char [] );
void sc_two( char [] );
void sc_three( char [] );
void sc_four( char [] );
void sc_five( char [] );
int main( void )
{
	int  n ; 
	char zf[200+1]; 
	scanf("%d%s", &n , zf);
	shuchu( n , zf );
	return 0 ; 
} 
void sc_five( char zf[])
{
	char * c = zf ;
	int ws = strlen( zf ) ;  
	
	int i ; 
	for( i = 0 ; i < ws ; i ++)
	{
		if(  c[i] >= 'A' && c[i] <= 'Z')  
        {  
        	 c[i] += 32 ;
        } 
	}
	for( i = 0 ; i < ws  ; i ++ )
	{
		putchar(c[i]); 
		if( (c[i]+1) == c[i+1] && (c[i+1]+1) == c[i+2])
		{
			putchar('-');
			while(c[i+1]-c[i] == 1 && i < ws)
			{
				i ++ ; 
			}
			putchar(c[i]); 
		}
		
	}
}
void sc_four( char zf[])
{
	char * c = zf ; 
	while( * c != '\0')
	{
        putchar( * c ^ 32 );
        c ++ ;  
	} 
}
void sc_three( char zf[] )
{
	int len = strlen(zf);  
	int  j ; 
	for( j = len - 1  ; j >= 0  ;  j -- )
	{
		putchar( zf[j] ) ;
	}
}
void sc_two( char zf[] )
{
	char * c = zf ; 
	while( * c != '\0')
	{
		if( * c >= 'A' && *c <= 'Z')  
        {  
        	* c += 32 ;
        } 
		putchar( * c ); 
        c ++ ;  
	} 
	
}
void sc_one( char zf[] )
{
	char * c = zf ; 
	while( * c != '\0')
	{
		if( * c >= 'a' && *c <= 'z')  
        {  
        	* c -= 32 ;
        }  
        putchar( * c );
        c ++ ;  
	} 

}
void shuchu( int n , char zf[])
{
	if( n == 1 )
	{
		sc_one( zf );
		return ;
	}
	if( n == 2 )
	{
		sc_two( zf );
		return ;
	}
	if( n == 3 )
	{
		sc_three( zf );
		return ;
	}
	if( n == 4 )
	{
		sc_four( zf );
		return ;
	}
	sc_five( zf );
}
