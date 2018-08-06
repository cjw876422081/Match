/*

问题描述

给出n个数，找出这n个数的最大值，最小值，和。
输入格式

第一行为整数n，表示数的个数。

第二行有n个数，为给定的n个数，每个数的绝对值都小于10000。
输出格式
输出三行，每行一个整数。第一行表示这些数中的最大值，第二行表示这些数中的最小值，第三行表示这些数的和。
样例输入
5
1 3 -2 4 5
样例输出
5
-2
11
数据规模与约定
1 <= n <= 10000。
 
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
