/*
��������

����һ������n�����������У�������a�������еĵ�һ�γ����ǵڼ�����
�����ʽ

��һ�а���һ������n��

�ڶ��а���n���Ǹ�������Ϊ���������У������е�ÿ������������10000��

�����а���һ������a��Ϊ�����ҵ�����
�����ʽ
���a�������г����ˣ��������һ�γ��ֵ�λ��(λ�ô�1��ʼ���)���������-1��
��������
6
1 9 4 8 3 9
9
�������
2
���ݹ�ģ��Լ��
1 <= n <= 1000��

*/ 
#include <stdio.h>
void shuru(int [],int );
int q_wz(int , int [],int );

int main(void) 
{
	int n;
	scanf("%d",&n);
	int a[n];
	shuru(a,n);
	int shu;
	scanf("%d",&shu);
	printf("%d",q_wz(shu,a,n));
	return 0;
	
}
int q_wz(int shu, int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==shu)
		{
			return i+1;
		}
	}
	return -1;
}

void shuru(int a[],int n)
{
	int i;
	for(i=0;i< n;i ++)
	{
		scanf("%d",&a[i]);
	}
}
