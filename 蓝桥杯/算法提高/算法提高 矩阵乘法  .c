/*

��������
������n�����󣬴�С�ֱ�Ϊa0*a1, a1*a2, a2*a3, ..., a[n-1]*a[n]����Ҫ������������ˣ�ֻ��ʹ�ý���ʣ���������Ҫ���ٴ����㡣
����������С�ֱ�Ϊp*q��q*r�ľ������ʱ�����������Ϊp*q*r��
�����ʽ
��������ĵ�һ�а���һ������n����ʾ����ĸ�����
�����ڶ��а���n+1��������ʾ�����ľ���
�����ʽ
�������һ����������ʾ���ٵ����������
��������
3
1 10 5 20
�������
150
���ݹ�ģ��Լ��
����1<=n<=1000, 1<=ai<=10000��

*/
#include<stdio.h>
void shuru( int [] , int );
long long q_yscs( int [], int  );
int mian( void )
{
	int n ; 
	scanf("%d",&n);
	int sz[n+1];
	shuru( sz , n+1 );
	printf("%lld" , q_yscs( sz , n+1 ));
	return 0 ; 
}
long long q_yscs( int sz[] , int n)
{

}
void shuru( int sz[] , int n)
{
	int i ;
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d",&sz[i]);
	}
}
