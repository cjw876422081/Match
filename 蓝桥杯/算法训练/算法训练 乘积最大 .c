/*
��������
���������ǹ�����ѧ����ȷ���ġ�2000����������ѧ�ꡱ����ǡ���ҹ�������ѧ�һ��޸���������90���ꡣ
�ڻ��޸������ļ��罭�ս�̳����֯��һ�����������ѧ���������Ļ�����һ��������XZҲ���ҵ��Բμӡ�
��У������˸����вμӻ��ѡ�ֳ�������һ����Ŀ��
��������һ������ΪN�����ִ���Ҫ��ѡ��ʹ��K���˺Ž����ֳ�K+1�����֣��ҳ�һ�ַַ���
ʹ����K+1�����ֵĳ˻��ܹ�Ϊ���
����ͬʱ��Ϊ�˰���ѡ���ܹ���ȷ������⣬�����˻��������µ�һ�����ӣ�
������һ�����ִ���312�� ��N=3��K=1ʱ�����������ַַ���
����3*12=36
����31*2=62
������ʱ��������ĿҪ��Ľ���ǣ�31*2=62
�������ڣ����������ĺ�����XZ���һ�����������ȷ�Ĵ𰸡�
�����ʽ
������������빲�����У�
������һ�й���2����Ȼ��N��K��6��N��40��1��K��6��
�����ڶ�����һ������ΪN�����ִ���
�����ʽ
�����������õ����˻���һ����Ȼ������
������������
4 2
1231
�������
62
*/
#include<stdio.h>
#include<math.h>
void zhuanhuan( int [] , char [] , int );
long long jisuan( int [] , int , int  );
long long mc_10( int ) ; 
int main( void )
{
	int n , k ;
	scanf("%d%d\n",&n ,&k );
	char zf[42];
	int sz[40];
	gets( zf );
	zhuanhuan( sz , zf , n );
	printf("%lld\n", jisuan( sz , n , k ));
	return 0;
}
long long mc_10( int n )
{
	int x = 1 ;
	while( n -- )
	{
		x *= 10 ;
	}
	return x ; 
}
long long jisuan( int sz[] , int n , int k )
{
	long long max = 0 ;
	int i , j ;  
	if( k == 0 )
	{
		for( i = 0 ; i < n ; i ++ )
		{
			max += sz[i] * mc_10( n - 1 - i ); 
		} 
	}
	else 
	{
		for ( i = 0 ; i <= n - k ; i ++ )     
        {  
            int num = 0;                                    
            long long jg = 0;           
            for ( j = n - i - 1; j < n ; j ++ )      
            {  
                num += sz[j] * mc_10( n - j - 1); 
            }  
            jg = num * jisuan( sz , n - i - 1 , k - 1);  
            max = jg > max ? jg : max ;  
        }  
	}
	return max ; 
}
void zhuanhuan( int sz[] , char zf[] , int n)
{
	int i ; 
	for( i = 0 ; i < n ; i ++ )
	{
		sz[i] = zf[i] - '0' ; 
	}
}
