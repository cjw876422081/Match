/*/*
��������
����ĳ��������������Ҫ֪��A~E����˵�������ʲô������Ҫ������ÿ����˵��һ�仰��������Ŀ�ͷ����-_-!�����˵�1������23��
˵�˼ٻ������˵�5�����˲�����˼��Ҳ˵�˼ٻ���Ϊ��ʹ�������򵥣���3��ͬ��˵�˼ٻ�������������˵�ٻ���
�����ʽ
������5�У��������α�ʾA~E˵�Ļ���
����ÿ�а���һ�����硰A>=3���������жϣ���һ����д��ĸ+��ϵ�����+һ�����֣��������ո�
������д��ĸA~E����ϵ����<��<=��=��>=��>��!=������1~5��ע�⣺�����ǡ�=�����ǡ�==����
�����ʽ
���������ж�⣬�밴���ֵ�������������У�ÿ����һ��
�������һ������������
��������
A=2
D=5
E>3
A>2
B!=1
�������
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
