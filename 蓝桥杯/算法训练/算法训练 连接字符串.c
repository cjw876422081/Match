/*    
　　编程将两个字符串连接起来。例如country与side相连接成为countryside。
　　输入两行，每行一个字符串（只包含小写字母，长度不超过100）；输出一行一个字符串。
样例输入
country
side
样例输出
countryside
country 
side
tsing
hua
tsinghua
*/ 
#include<stdio.h>
void lian_jie(char * , char * );
int main( void )
{
	char zf1[250],zf2[101];
	scanf("%s", zf1);
	scanf("%s", zf2);
	lian_jie( zf1 , zf2 );
	puts(zf1);
	return 0;
}
void lian_jie(char * cf, char *zf )
{
	while( * cf != '\0' )
	{
		cf ++ ;
	}
	while( ( * cf  = * zf  ) != '\0' )
	{
		cf ++ ;
		zf ++ ;
	}	
}
