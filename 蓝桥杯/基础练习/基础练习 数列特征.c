/*

��������

����n�������ҳ���n���������ֵ����Сֵ���͡�
�����ʽ

��һ��Ϊ����n����ʾ���ĸ�����

�ڶ�����n������Ϊ������n������ÿ�����ľ���ֵ��С��10000��
�����ʽ
������У�ÿ��һ����������һ�б�ʾ��Щ���е����ֵ���ڶ��б�ʾ��Щ���е���Сֵ�������б�ʾ��Щ���ĺ͡�
��������
5
1 3 -2 4 5
�������
5
-2
11
���ݹ�ģ��Լ��
1 <= n <= 10000��
 
*/ 
#include <stdio.h>
void shuru(int [],int );
void paixu(int [],int );
int q_he(int [],int );

int main(void) 
{
	int n;
	scanf("%d",&n);
	int a[n];
	shuru(a , n);
	paixu(a , n);
	printf("%d\n",a[n-1]);
	printf("%d\n",a[0]);
	printf("%d\n",q_he( a , n));
	return 0;
}
int q_he(int a[],int n)
{
	int i,he=0;
	for(i=0;i<n;i++)
	{
		he+=a[i];
	}
	return he;
}

void paixu(int a[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
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
