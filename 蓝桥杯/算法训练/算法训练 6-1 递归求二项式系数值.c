/*
��������
��������
һ��������ĿҪ������뷶����
3 10
�������
����������������Ӧ�������
���ݹ�ģ��Լ��
��������������ÿһ�����ķ�Χ��
�������������int��ʾʱ���������
*/

#include<stdio.h>
int ditui( int , int );
int main(void )
{
	int n , m ;
	scanf("%d%d", &n , &m);
	printf("%d",ditui( n , m));
	return 0;
} 
int ditui( int n , int  m )
{
	if( n == 0 || n == m)
	{
		return 1;
	}
	return ditui( n , m - 1)+ditui( n - 1 , m - 1);
}
