/*  
历届试题 小朋友排队  
时间限制：1.0s   内存限制：256.0MB
问题描述
　　n 个小朋友站成一排。现在要把他们按身高从低到高的顺序排列，但是每次只能交换位置相邻的两个小朋友。
　　每个小朋友都有一个不高兴的程度。开始的时候，所有小朋友的不高兴程度都是0。
　　如果某个小朋友第一次被要求交换，则他的不高兴程度增加1，如果第二次要求他交换，则他的不高兴程度增加2（即不高兴程度为3），依次类推。当要求某个小朋友第k次交换时，他的不高兴程度增加k。
　　请问，要让所有小朋友按从低到高排队，他们的不高兴程度之和最小是多少。
　　如果有两个小朋友身高一样，则他们谁站在谁前面是没有关系的。
输入格式
　　输入的第一行包含一个整数n，表示小朋友的个数。
　　第二行包含 n 个整数 H1 H2 … Hn，分别表示每个小朋友的身高。
输出格式
　　输出一行，包含一个整数，表示小朋友的不高兴程度和的最小值。
样例输入
3
3 2 1
样例输出
9
样例说明
　　首先交换身高为3和2的小朋友，再交换身高为3和1的小朋友，再交换身高为2和1的小朋友，每个小朋友的不高兴程度都是3，总和为9。
数据规模和约定
　　对于10%的数据， 1<=n<=10；
　　对于30%的数据， 1<=n<=1000；
　　对于50%的数据， 1<=n<=10000；
　　对于100%的数据，1<=n<=100000，0<=Hi<=1000000。
*/
#include <stdio.h>
typedef
	struct
	{
		int high;
		int time;
	} XPY ;

void paixu_fen( XPY [] , int , int , XPY [] );
void paixu_bing( XPY [] , int , int , int , XPY []);
long long qiu_min( XPY [] , int );
long long qiu_cs( long long );
void shuru( XPY [] , int );

int main(void)
{
	int n;
	scanf("%d", &n );
	XPY xpy[n] ;
	shuru( xpy , n );
	XPY tmp[n] ;
	paixu_fen( xpy , 0 , n - 1 , tmp );
	printf("%lld\n", qiu_min( xpy , n ) ); 
	return 0;	
}

long long qiu_cs( long long n )
{
	return (1 + n) * n / 2;
}
long long qiu_min( XPY sz[] , int n )
{
	long long sum = 0 ;
	int i ;
	for( i = 0 ; i < n ; i ++ )
	{
		sum += qiu_cs( (long long)sz[i].time ) ;
	}
	return sum ;
}

void paixu_bing( XPY sz[] , int start , int mid , int end , XPY tmp[] )
{
	int k = 0 , gs = 0;
	int left = start , right = mid + 1;
	while( left <= mid && right <= end )
	{
		if( sz[left].high <= sz[right].high )
		{
			sz[left].time += gs ;
			tmp[k ++] = sz[left ++];
		}
		else
		{
			sz[right].time += mid + 1 - left ;
			tmp[k ++] = sz[right ++];
			gs ++ ;
		}
	}
	while( left <= mid )
	{
		sz[left].time += gs ;
		tmp[k ++] = sz[left ++];
	}
	while( right <= end )
	{
		tmp[k ++] = sz[right ++];
	}
	int i;
	for( i = 0 ; i < end - start + 1 ; i ++  )
	{
		sz[start + i] = tmp[i];
	}
}

void paixu_fen( XPY sz[] , int start , int end ,  XPY tmp[] )
{
	if( start < end )
	{
		int mid = start + ( end - start ) / 2 ;
		paixu_fen( sz , start , mid , tmp );
		paixu_fen( sz , mid + 1 , end , tmp );
		paixu_bing( sz , start , mid , end , tmp );
	}
}

void shuru( XPY sz[] , int n )
{
	int i ;
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d", & sz[i].high );
		sz[i].time = 0 ;
	}
} 
