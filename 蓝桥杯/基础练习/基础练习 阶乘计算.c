/*
问题描述
　　输入一个正整数n，输出n!的值。
　　其中n!=1*2*3*…*n。
算法描述
　　n!可能很大，而计算机能表示的整数范围有限，需要使用高精度计算的方法。使用一个数组A来表示一个大整数a，A[0]表示a的个位，A[1]表示a的十位，依次类推。
　　将a乘以一个整数k变为将数组A的每一个元素都乘以k，请注意处理相应的进位。
　　首先将a设为1，然后乘2，乘3，当乘到n时，即得到了n!的值。
输入格式
　　输入包含一个正整数n，n<=1000。
输出格式
　　输出n!的准确值。
样例输入
10
样例输出
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
