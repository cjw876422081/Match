/*
��д����GetReal��GetString����main�����зֱ�����������������ڶ���һ��ʵ����һ���ַ����󣬽�����Ľ��������printf�����
������������ǰҪ�������ʾ��Ϣ�ֱ���"please input a number:\n����"please input a string:\n"
��������
9.56
hello
�������
please input a number:
please input a string:
9.56
hello
*/
#include<stdio.h>
void GetReal( double * ); 
void GetString( char *);
int main( void )
{
	double n ;
	char zf[128];
	GetReal(&n); 
	GetString(zf);
	printf("please input a number:\n");
	printf("please input a string:\n");
	printf("%.2lf\n", n );
	printf("%s\n" , zf);
	return 0 ; 
}
void GetReal( double * n)
{
	scanf("%lf", n );
}
void GetString( char * zf)
{
	scanf("%s", zf );
}
