/*
��������
��������һ������Ϊn�����У���������а���С�����˳�����С�1<=n<=200
�����ʽ
������һ��Ϊһ������n��
�����ڶ��а���n��������Ϊ�����������ÿ�������ľ���ֵС��10000��
�����ʽ
�������һ�У�����С�����˳��������������С�
��������
5
8 3 6 4 9
�������
3 4 6 8 9

*/ 
#include <stdio.h>
void shuru(int [],int );
void paixu(int [],int );
void shuchu(int [],int );

int main(void) 
{
	int n;
	scanf("%d",&n);
	int a[n];
	shuru(a , n);
	paixu(a , n);
	shuchu(a , n);
	return 0;
}
void shuchu(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

void paixu(int a[],int n)
{
	int i , j ;
	for(i = 0 ; i < n-1 ; i ++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int tmp;
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
			
		}
	}
}

void shuru(int a[] , int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
