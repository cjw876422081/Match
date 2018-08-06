/*��������
��������һ������ΪN�����У�A1, A2, ... AN���������һ��������������Ai,
	 Ai+1, ... Aj(i <= j)֮����K�ı��������Ǿͳ��������[i, j]��K�����䡣
����������������ܹ��ж��ٸ�K��������
�����ʽ
������һ�а�����������N��K��(1 <= N, K <= 100000)
��������N��ÿ�а���һ������Ai��(1 <= Ai <= 100000)
�����ʽ
�������һ������������K���������Ŀ��
��������
5 2
1
2
3
4
5
�������
6*/
#if 1
#include<stdio.h>
void Input( long long [] , int ) ; 
void Output( long long [] , long long [], int , int);
int main(void)
{
	int n , k ;
	scanf("%d%d", &n , & k ) ; 
	long long sz[100002] = { 0 } ;
	long long bk[100002] = { 0 } ; // ��������һ������[l,r]�ĺ;���sum[r]-sum[l-1] 
	Input( sz , n ) ;
	Output( sz , bk , n  , k ) ; 
	return 0 ; 
}
void Output( long long sz[] , long long bk[] , int n , int k )
{
	sz[0] %= k ; 
	long long sum = 0 , i ; 
	for(  i = 0 ; i < n ; i ++ )
	{
		sz[i] = (sz[i] + sz[i-1]) % k ; 
	}
	for(  i = 0 ; i < n ; i ++ )
	{
		sum += bk[sz[i]]++ ;  
	}
	printf("%lld\n" , sum + bk[0] ) ; 
}
void Input( long long sz[] , int n)
{
	int i ; 
	for( i = 0 ; i < n ; i ++  )
	{
		scanf("%d" , &sz[i] ) ;
	}
}
#endif
