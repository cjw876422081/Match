/*
��������
�������ģ��������ļӡ������ˡ������ܣ������û����������������������������㡣(Ҫ��switch���)
�����ʽ
��������ֻ��һ�У��ÿո������������������������������һ����+, -, *, /֮һ��
������һ���Ǿ���ֵ������200���������������Ϊ����ʱ��������Ϊ0����һ����һ���ǵڶ���������������
�����ʽ
�������ֻ��һ�У�����һ����������ʾ��������
��������
/ 6 2
�������
3
*/
#include<stdio.h>
void shuchu( char , int , int );
int main( void )
{
	char fh; 
	int s1 , s2 ;
	scanf("%c%d%d", &fh , &s1 , &s2);
	shuchu( fh , s1 , s2 );
}
void shuchu( char c, int s1 , int  s2)
{
	switch( c )
	{
		case '+' :printf("%d" , s1 + s2);
		break ; 
		case '-' :printf("%d" , s1 - s2);
		break ;
		case '*' :printf("%d" , s1 * s2);
		break ; 
		case '/' :printf("%d" , s1 / s2);
		break ;
	}
}
