/*
��������
����ÿ����Ʒ��һ����������ϻ�������ͬ����Ʒ��ϣ�
	װ�뱳����ս��һ���������������ÿ����Ʒ�����޼����ã�
	��ô��Щ�������ԶҲװ�������ġ�Ϊ�˾���װ��������
	���е�OIER��Ҫ�о�һ����Ʒ����װ������������
	��Ŀ��֤�н⣬��������޽⣬��֤������2��000��000��000
������������޽⣬�����0
�����ʽ
������һ��һ������n��n<=10������ʾ��Ʒ�ļ���
������2�е�N+1��: ÿ����Ʒ�����(1<= <=500)
�����ʽ
����һ������ans����ʾ��������Щ��Ʒ�õ�����������
��������
3
3
6
10
�������
17
*/
#if 1
#include<stdio.h>
#define MAX (100000)
void Input( int [] , int );
int gcd( int , int ); 
int q_max( int [] , int );
int p_num( int [] , int );
int main(void)
{
	int n ; 
	scanf("%d" ,& n ) ; 
	int sz[n] ; 
	Input( sz , n ) ; 
	printf("%d\n", q_max( sz , n ));
	return 0 ; 
}
int p_num( int sz[] , int n)
{
	int temp = sz[0] , i ;
    for ( i = 1 ; i < n ; i ++ )
    {
        temp = gcd(temp, sz[i]);
    }
    return temp;
}
int q_max( int sz[] , int n)
{
	int v_max[MAX] = { 0 } ; 
	if( p_num( sz , n ) == 1 )
	{
		v_max[0] = 1 ; 
		int i ; 
		for( i = 0 ; i < n ; i ++ )
		{
			int j ; 
			for( j = sz[i] ;j <=MAX ; j ++ )
			{
				if(v_max[j - sz[i]] == 1 )
				{
					v_max[j] = 1 ; 
				} 
			}
		}
	}
	int i ; 
	for( i = MAX ; i >= 0; i -- )
    {
        if (v_max[i] == 0 )
        {
            return i ;
        }
    }
    return 0 ;  
	
}
int gcd( int a , int b)
{
	return  a%b == 0 ? b : gcd( b , a % b ) ; 
}
void Input( int sz[] , int n)
{
	int i ;
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d" , &sz[i] );
	}
} 
#endif
