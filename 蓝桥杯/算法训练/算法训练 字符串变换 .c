/*
��������
�������ž������ѧ�ڵı��ѵ������Ҷ����ַ����Ĳ����Ѿ����յ��൱�����ˡ�
���죬����ʦ�����һ�´�Ҷ����ַ������������������
����ʦ�Լ�������1,2,3,4,5��5�������ֱ�ָ����ͬ��5���ַ�������������Ҫ���ݴ���Ĳ�������������ʦ�Ĺ涨���������ַ������и�ʽת����
��������ʦָ���Ĳ������£�
����1 ��ʾȫ��ת��Ϊ��д��ĸ�������abC ��� ABC
����2 ��ʾȫ��ת��ΪСд��ĸ�������abC���abc
����3 ��ʾ���ַ������������������ abc ��� cba
����4 ��ʾ���ַ����ж�Ӧ�Ĵ�д��ĸת��ΪСд��ĸ���������е�Сд��ĸת��Ϊ��д��ĸ������� abC���ABc
����5��ʾ��ȫ��ת��ΪСд��ĸ�������������е������Ӵ�ת��Ϊ��Ӧ����д��ʽ���������abcD ת��Ϊa-d��
��Σ�-���ٴ���1����ĸ���������ab������Ҫת��Ϊ��д��ʽ��
�����ʽ
����һ��һ�У��ֱ���ָ����Ӧ���������ֺ��ַ����������Կո�ָ����ַ���ȫ����Ӣ����ĸ���
�����ʽ
�������������������ת�����Ӧ���ַ���
��������
5 ABcd
�������
a-ee
���ݹ�ģ��Լ��
���������ַ��������Ϊ200��
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
