/*
��������
������дһ����lcm������������������С��������
��������
һ��������ĿҪ������뷶����
����

3 5
�������
����������������Ӧ�������
����
���ݹ�ģ��Լ��
��������������ÿһ�����ķ�Χ��
����������������С��65536��

*/ 
#include <stdio.h>
int qiu_zdgys(int ,int );

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",(m*n)/qiu_zdgys(n,m)) ;
    return 0;
}
int qiu_zdgys(int n,int m)
{
	if(n % m == 0)
	{
		return m;
	}
	return qiu_zdgys(m,n % m);
}
