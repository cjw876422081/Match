/*
��������
�����˿������򣺹����˿������飬���˿��ƽ�������
	����ԭ�����£����ִ�С������2-10��J��Q��K��A��
	��ɫ��С�����Ƿ��飨diamond����÷����club�������ң�heart�������ң�spade����
	�����ƱȽ�ʱ�ȿ����֣�������ͬʱ����ɫ��Ҫ���������˿��ƽ��д�С��������
�������������ƣ���ʾ����2������3������3������A��÷��J���� 2 s 3 h 3 s A d J c
����������ӦΪ��2 s 3 h 3 s J c A d
���鳤�ȹ̶�Ϊ5��
�������
����������������Ӧ�������
����
���ݹ�ģ��Լ��
��������������ÿһ�����ķ�Χ��
*/
#include<stdio.h>
typedef
	struct
	{
		char sz;
		char hs;
	}PM;
void shuru( PM [] , int  );
void shuchu( PM [] , int  );
void paixu( PM [] , int  );
int q_shu( char );
int q_hs( char );
void huan( PM * , PM *);
int main( void )
{
	PM pkp[5];
	shuru( pkp , 5);
	paixu( pkp , 5 );
	shuchu( pkp, 5 );
	return 0 ;
}
void huan( PM * a , PM * b)
{
	PM tmp = * a ; 
	* a =  * b ; 
	* b = tmp ; 
}
int q_hs( char  c )
{
	char hs[5]={'d','c','h','s'};  
	int i ;
    for (i = 0 ;i < 4;i ++)  
    {  
        if ( hs[i] == c)  
        {  
            return i ;  
        }  
    }  
}
int q_shu( char  c )
{
	char num[14]={'2','3','4','5','6','7','8','9','10','J','Q','K','A'};  
	int i ;
    for (i = 0 ;i < 13 ;i ++)  
    {  
        if (num[i] == c)  
        {  
            return i ;  
        }  
    }  
}
void paixu( PM pkp[] , int n)
{
	int i , j ; 
	for( i = 0 ; i < n ; i ++ )
	{
		for( j = 0 ; j < n - i - 1 ; j ++ )
		{
			int s1 = q_shu(pkp[j].sz ) ; 
			int s2 = q_shu(pkp[j+1].sz ) ;
			if( s1 > s2 )
			{
				huan( &pkp[j] , &pkp[j+1] );
			}
			if( s1 == s2 )
			{
				if( q_hs(pkp[j].hs) > q_hs( pkp[j+1].hs) )
				{
					huan( &pkp[j] , &pkp[j+1] );
				}
			}
		}
	}
}
void shuchu( PM pkp[] , int n)
{
	int i ; 
	for(i = 0 ; i < n ; i ++)
	{
		printf("%c%c ", pkp[i].sz ,pkp[i].hs);
	}
}
void shuru( PM pkp[] , int n)
{
	int i ; 
	for(i = 0 ; i < n ; i ++)
	{
		scanf("%c%c", &pkp[i].sz ,&pkp[i].hs);
	}
}
