/*
��������
��������һ��������n�����n!��ֵ��
��������n!=1*2*3*��*n��
�㷨����
����n!���ܴܺ󣬶�������ܱ�ʾ��������Χ���ޣ���Ҫʹ�ø߾��ȼ���ķ�����ʹ��һ������A����ʾһ��������a��A[0]��ʾa�ĸ�λ��A[1]��ʾa��ʮλ���������ơ�
������a����һ������k��Ϊ������A��ÿһ��Ԫ�ض�����k����ע�⴦����Ӧ�Ľ�λ��
�������Ƚ�a��Ϊ1��Ȼ���2����3�����˵�nʱ�����õ���n!��ֵ��
�����ʽ
�����������һ��������n��n<=1000��
�����ʽ
�������n!��׼ȷֵ��
��������
10
�������
3628800
*/ 
#include <stdio.h>
void shuru(int [], int,int);
void jinwei(int [], int);
void shuchu(int [], int);

int main(void)
{
	int n;
	scanf("%d",&n);
	int a[3000]={1};
	shuru(a,3000,n);
	shuchu(a ,3000); 
    return 0;
}
void shuchu(int a[], int n)
{

	while( a[-- n] == 0 )
	{
	}
	while( n >= 0 )
	{
		printf("%d", a[n --] );
	}
	putchar('\n');
}

void jinwei(int a[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]>9)
		{
			a[i+1]+=a[i]/10;
			a[i]%=10;
		}
	}
}

void shuru(int a[], int n,int k)
{
	int i;
	for(i=1;i<=k;i++)
	{
		int j;
		for(j=0;j<n;j++)
		{
			a[j]*=i;
		}
		jinwei(a, n);
	}
}
