/*��������
����쳲��������д�Ҷ��ǳ���Ϥ�����Ķ����ǣ�

����f(x) = 1 .... (x=1,2)
����f(x) = f(x-1) + f(x-2) .... (x>2)

�������ڸ��������� n �� m������ϣ�������
����f(1) + f(2) + ... + f(n) ��ֵ�������ֵ���ܷǳ����������ǰ����� f(m) ȡģ��
������ʽ����
���������������Ȼ�ܴ�������Ҫ�ٶ� p ��ģ��
�����ʽ
��������Ϊһ���ÿո�ֿ������� n m p (0 < n, m, p < 10^18)
�����ʽ
�������Ϊ1����������ʾ��
��������
2 3 5
�������
0
��������
15 11 29
�������
*/
#include<stdio.h>
long long q_shu( long long );
void  shuchu( long long , long long , long long );
int main( void )
{	
	long long n , m  , p ;
	scanf("%lld%lld%lld", &n , &m, &p );
	shuchu( n, m, p );
	return 0 ; 
} 
long long q_shu( long long n )
{
	if( n == 1 || n == 2 )  
	{  
		return 1 ;  
	}  
	return q_shu( n - 1) + q_shu( n - 2 ) ; 
}
void  shuchu( long long n, long long m, long long p)
{
	long long  i  , sum = 0 ; 
	for(i = 1 ; i <= n ; i ++)
	{
		sum += q_shu( i );
	} 
	printf("%d\n", (sum % q_shu( m )) % p );
}
