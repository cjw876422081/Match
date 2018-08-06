/*  
�������� С�����Ŷ�  
ʱ�����ƣ�1.0s   �ڴ����ƣ�256.0MB
��������
����n ��С����վ��һ�š�����Ҫ�����ǰ���ߴӵ͵��ߵ�˳�����У�����ÿ��ֻ�ܽ���λ�����ڵ�����С���ѡ�
����ÿ��С���Ѷ���һ�������˵ĳ̶ȡ���ʼ��ʱ������С���ѵĲ����˳̶ȶ���0��
�������ĳ��С���ѵ�һ�α�Ҫ�󽻻��������Ĳ����˳̶�����1������ڶ���Ҫ���������������Ĳ����˳̶�����2���������˳̶�Ϊ3�����������ơ���Ҫ��ĳ��С���ѵ�k�ν���ʱ�����Ĳ����˳̶�����k��
�������ʣ�Ҫ������С���Ѱ��ӵ͵����Ŷӣ����ǵĲ����˳̶�֮����С�Ƕ��١�
�������������С�������һ����������˭վ��˭ǰ����û�й�ϵ�ġ�
�����ʽ
��������ĵ�һ�а���һ������n����ʾС���ѵĸ�����
�����ڶ��а��� n ������ H1 H2 �� Hn���ֱ��ʾÿ��С���ѵ���ߡ�
�����ʽ
�������һ�У�����һ����������ʾС���ѵĲ����˳̶Ⱥ͵���Сֵ��
��������
3
3 2 1
�������
9
����˵��
�������Ƚ������Ϊ3��2��С���ѣ��ٽ������Ϊ3��1��С���ѣ��ٽ������Ϊ2��1��С���ѣ�ÿ��С���ѵĲ����˳̶ȶ���3���ܺ�Ϊ9��
���ݹ�ģ��Լ��
��������10%�����ݣ� 1<=n<=10��
��������30%�����ݣ� 1<=n<=1000��
��������50%�����ݣ� 1<=n<=10000��
��������100%�����ݣ�1<=n<=100000��0<=Hi<=1000000��
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
