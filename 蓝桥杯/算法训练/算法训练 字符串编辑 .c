/*
问题描述
　　从键盘输入一个字符串（长度<=40个字符），并以字符 ’.’ 结束。编辑功能有：
　　1 D：删除一个字符，命令的方式为： D a 其中a为被删除的字符，例如：D s 表示删除字符 ’s’ ，若字符串中有多个 ‘s’，则删除第一次出现的。
　　2 I：插入一个字符，命令的格式为：I a1 a2 其中a1表示插入到指定字符前面，a2表示将要插入的字符。
	例如：I s d 表示在指定字符 ’s’ 的前面插入字符 ‘d’ ，若原串中有多个 ‘s’ ，则插入在最后一个字符的前面。
　　3 R：替换一个字符，命令格式为：R a1 a2 其中a1为被替换的字符，a2为替换的字符，若在原串中有多个a1则应全部替换。
　　在编辑过程中，若出现被改的字符不存在时，则给出提示信息。
输入格式
　　输入共两行，第一行为原串(以’.’结束)，第二行为命令（输入方式参见“问题描述” 。
输出格式
　　输出共一行，为修改后的字符串或输出指定字符不存在的提示信息。
样例输入
This is a book.
D s
样例输出
Thi is a book.
输入输出样例解释
　　命令为删去s，第一个在字符中出现的s在This中，即得到结果。
*/
#if 1
#include<stdio.h>

void Input( char [] , int * );
void Solve( char ,  char [] , int ) ;
void in_zf( char [] , int   );
void de_zf( char [] , int   );
void re_zf( char [] , int  );

int main(void)
{
	char zf[1000];
	int ws = 0 ; 
	Input( zf , &ws );
	char ml ; 
	scanf(" %c" , &ml ) ;
	Solve( ml ,  zf  , ws ) ; 
	return 0 ; 
}
void in_zf( char zf[] , int  ws  )
{
	char a1 , a2 ; 
	scanf(" %c %c" , & a1 , &a2 ) ;
	int i , j = 100; 
    for( i = ws - 1 ; i >= 0 ; i -- )
	{
        if( zf[i] == a1 )
		{ 
		 	j=i;
		 	break;
		}  
	} 
    for( i = 0 ; i < ws ; i ++ )  
    {  
       if(i == j )
	   {
	   	 printf("%c", a2 ); 
	   } 
       printf("%c",zf[i]);  
    }   
	 
}
void de_zf( char zf[] , int ws )
{
	char ch ; 
	int i , bj = 0 ;
	scanf(" %c" , &ch );
	for( i = 0 ; i < ws ; i ++ )
	{
		if( zf[i] != ch || bj == 1)
		{
			printf("%C" , zf[i]) ; 
		}
		else
		{
			bj = 1 ; 
		}
	} 
}
void re_zf( char zf[] , int ws )
{
	char a1 , a2 ; 
	scanf(" %c %c" , & a1 , &a2 ) ;
	int i ; 
    for( i = 0 ; i < ws ; i ++ )
	{
		if( zf[i] == a1 )
		{
			printf("%c", a2 );
		}  
		else
		{
			printf("%c",zf[i]);
		}   
	}  

}
void Solve( char ml , char zf[] , int  ws )
{
	switch( ml )
	{
		case 'D':de_zf( zf , ws  ) ;
		break;
		case 'I':in_zf( zf , ws  ) ; 
		break;
		case 'R':re_zf( zf , ws  ) ;
		break;
		
	}
}

void Input( char zf[] , int * ws )
{
	char c ; 
	while( (c = getchar()) != '.')
	{
		zf[*ws] = c ; 
		++ * ws ;  
	}
	zf[*ws] = '.' ; 
	++ * ws ;  
}
#endif
