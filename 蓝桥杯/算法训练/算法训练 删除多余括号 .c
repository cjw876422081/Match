/*��������
�����Ӽ�������һ���������ŵ�����������ʽ��Ҫ��ȥ�����ܺ��еĶ�������ţ����Ҫ����ԭ���ʽ�б���������������λ�ò��䣬����ԭ���ʽ�ȼ�,��Ҫ�󻯼����ⲻ����'+'����'-'���������ŵ��������������ʽ�������(+a)��(-a)�����Ρ�
�����ʽ
�������ʽ�ַ��������Ȳ�����255,�������Ҳ����ո��ַ������ʽ�е����б������ǵ���Сд��Ӣ����ĸ, �����ֻ�м�+��-��*��/��������š�
�����ʽ
����ȥ���������ź�ı��ʽ
��������

����һ��
a+(b+c)-d
��������
a+b/(c+d)
��������
(a*b)+c/d
�����ģ�
((a+b)*f)-(i/j)
�������
����һ��
a+b+c-d
��������
a+b/(c+d)
��������
a*b+c/d
�����ģ�
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
