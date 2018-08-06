/*/*
问题描述
　　某场比赛过后，你想要知道A~E五个人的排名是什么，于是要求他们每个人说了一句话。（经典的开头……-_-!）得了第1名的人23，
说了假话；得了第5名的人不好意思，也说了假话；为了使求解问题简单，第3名同样说了假话。（奇数名次说假话）
输入格式
　　共5行，各行依次表示A~E说的话。
　　每行包含一个形如“A>=3”的名次判断，即一个大写字母+关系运算符+一个数字，不包含空格。
　　大写字母A~E，关系运算<、<=、=、>=、>、!=，数字1~5。注意：等于是“=”不是“==”！
输出格式
　　可能有多解，请按照字典序输出排名序列，每个解一行
　　最后一行输出解的数量
样例输入
A=2
D=5
E>3
A>2
B!=1
样例输出
ACDEB
AECBD
BADCE
BCADE
BDACE
CEADB
CEBDA
7
*/
#if 1
#include<stdio.h>
#include<stdlib.h> 
#include<string.h>  
int a , b , c , d , e ;  
void Input( char [][5] , int ) ;
void pailie(char [][6] , int *  , char [][5]) ; 
int bxt( int , int , int , int , int ) ;
int sdh( char [][5] , int , int ) ;
int panduan( char [] ) ;
int pd_tj( char ) ;
void Output( char [][6] , int ) ; 

int main(void)
{
	int xb = 0 ;  
    char ken[200][6] ; 
	char s[5][5]; 
    Input( s , 5 ) ;
    pailie( ken , & xb , s );
    Output( ken , xb ) ; 
	return 0;
}
void Output( char ken[][6] , int xb )
{
	int i , j ;
	char temp[5] ;  
    for( i = 0 ; i < xb ; i ++ )
	{  
    	for( j = i ; j < xb ; j ++ )
		{  
        	if( strcmp ( ken[i] , ken[j] ) > 0)
			{  
            	strcpy( temp , ken[i] ) ;  
            	strcpy( ken[i] , ken[j] ) ;  
            	strcpy( ken[j] , temp ) ;  
        	}  
    	}      
    }  
    for( i = 0 ; i < xb ; i ++ )
	{  
    	puts( ken[i] ) ;      
    }  
    printf( "%d\n" , xb ) ;  
}
int pd_tj(char s)
{
	if( s == 'A' )
	{
		return a;
	}
	if( s == 'B' )
	{
		return b;
	}
	if( s == 'C' )
	{
		return c;
	}
	if( s == 'D' )
	{
		return d;
	}
	if( s == 'E' )
	{
		return e;
	}
}

int panduan(char s[])
{
	if(strlen(s)==3)
	{
		if(s[1]=='=')
		{
			return pd_tj(s[0])==(s[2]-'0');
		}
		else if(s[1]=='>')
		{
			return pd_tj(s[0])>(s[2]-'0');
		}
		else
		{
			return pd_tj(s[0])<(s[2]-'0');
		}
	}
	else
	{
		if(s[1]=='>')
		{
			return pd_tj(s[0])>=(s[3]-'0');
		}
		else if(s[1]=='!')
		{
			return pd_tj(s[0])!=(s[3]-'0');
		}
		else
		{
			return pd_tj(s[0])<=(s[3]-'0');
		}
	}
}

int sdh( char s[][5] , int ren,int n)
{
	if(ren%2==0)
	{
		if(panduan(s[n]))
		{
			return 1;
		};
		return 0;
	}
	else if(ren%2==1)
	{
		if(!panduan(s[n]))
		{
			return 1;
		};
		return 0;
	}
}

int bxt(int a , int b , int c , int d , int e )
{
	if( a == b || a == c || a == d )
	{
		return 0;
	}
	if( a == e || b == c || b == d || b == e || c == d )
	{
		return 0;
	}
	if( c == e || d == e)
	{
		return 0;
	}
	return 1 ;
}

void pailie( char ken[][6] , int *xb  , char s[][5])
{
	for( a = 1 ; a < 6 ; a ++ )
	{
    	for( b = 1 ; b < 6 ; b ++ )
		{
	    	for( c = 1 ; c < 6 ; c ++)
			{
		    	for( d = 1 ; d < 6 ; d ++ )
				{
			    	for( e = 1 ; e < 6 ; e ++ )
					{
				    	if(!bxt( a , b , c , d , e ))
				    	{
				    		continue;
						}
						if(sdh( s , a , 0 ))
						{
							if(sdh( s , b , 1 ))
							{
								if(sdh( s , c ,2 ))
								{
									if(sdh( s , d ,3 ))
									{
										if(sdh( s , e , 4 ))
										{
											ken[*xb][a-1]='A';
											ken[*xb][b-1]='B';
											ken[*xb][c-1]='C';
											ken[*xb][d-1]='D';
											ken[*xb][e-1]='E';
											ken[*xb][5]='\0';
											++ * xb ;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void Input( char zf[][5] , int n )
{
	int i ;
	for( i = 0 ; i < n ; i ++ )
	{
		gets( zf[i] ) ;
	}
}
#endif
