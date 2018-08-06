/*
问题描述
　　在上一季里，曾提到过质数的孤独，其实从另一个角度看，无情隔膜它们的合数全是质数的后代，
	因为合数可以由质数相乘结合而得。
　　如果一个合数由两个质数相乘而得，那么我们就叫它是质数们的直接后代。
	现在，给你一系列自然数，判断它们是否是质数的直接后代。
输入格式
　　第一行一个正整数T，表示需要判断的自然数数量
　　接下来T行，每行一个要判断的自然数
输出格式
　　共T行，依次对于输入中给出的自然数，判断是否为质数的直接后代，是则输出Yes，否则输出No
样例输入
4
3
4
6
12
样例输出
No
Yes
Yes
No
数据规模和约定
　　1<=T<=20
　　2<=要判断的自然数<=105

*/
#include <stdio.h>
int q_zs(int);
void panduan( int  );
int main(void)
{
	int n;
	scanf("%d",&n);
	int zrs;
	while(n-->0)
	{
		scanf("%d",&zrs);
		panduan( zrs );

	}
    return 0;
}
void panduan( int  zrs)
{
	int i;
	for(i = 2 ; i < zrs ; i ++)
	{
		if( zrs % i == 0 )
		{
			if(q_zs(i) == 0 && q_zs(zrs/i) == 0)
			{
				printf("Yes\n");
				return ;
			}	
		}
	}
	printf("No\n");
}

int q_zs(int n )
{
	int i, shu=0;

	for(i = 2; i < n ;i ++)
	{
		if( n % i == 0)
		{
			shu++;
		}
	}
	return shu;
}
