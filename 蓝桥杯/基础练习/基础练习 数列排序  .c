/*
问题描述
　　给定一个长度为n的数列，将这个数列按从小到大的顺序排列。1<=n<=200
输入格式
　　第一行为一个整数n。
　　第二行包含n个整数，为待排序的数，每个整数的绝对值小于10000。
输出格式
　　输出一行，按从小到大的顺序输出排序后的数列。
样例输入
5
8 3 6 4 9
样例输出
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
