/*
��������
�����Ӽ�������һ���ַ���������<=40���ַ����������ַ� ��.�� �������༭�����У�
����1 D��ɾ��һ���ַ�������ķ�ʽΪ�� D a ����aΪ��ɾ�����ַ������磺D s ��ʾɾ���ַ� ��s�� �����ַ������ж�� ��s������ɾ����һ�γ��ֵġ�
����2 I������һ���ַ�������ĸ�ʽΪ��I a1 a2 ����a1��ʾ���뵽ָ���ַ�ǰ�棬a2��ʾ��Ҫ������ַ���
	���磺I s d ��ʾ��ָ���ַ� ��s�� ��ǰ������ַ� ��d�� ����ԭ�����ж�� ��s�� ������������һ���ַ���ǰ�档
����3 R���滻һ���ַ��������ʽΪ��R a1 a2 ����a1Ϊ���滻���ַ���a2Ϊ�滻���ַ�������ԭ�����ж��a1��Ӧȫ���滻��
�����ڱ༭�����У������ֱ��ĵ��ַ�������ʱ���������ʾ��Ϣ��
�����ʽ
�������빲���У���һ��Ϊԭ��(�ԡ�.������)���ڶ���Ϊ������뷽ʽ�μ������������� ��
�����ʽ
���������һ�У�Ϊ�޸ĺ���ַ��������ָ���ַ������ڵ���ʾ��Ϣ��
��������
This is a book.
D s
�������
Thi is a book.
���������������
��������Ϊɾȥs����һ�����ַ��г��ֵ�s��This�У����õ������
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
