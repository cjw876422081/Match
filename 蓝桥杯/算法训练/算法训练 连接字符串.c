/*    
������̽������ַ�����������������country��side�����ӳ�Ϊcountryside��
�����������У�ÿ��һ���ַ�����ֻ����Сд��ĸ�����Ȳ�����100�������һ��һ���ַ�����
��������
country
side
�������
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
