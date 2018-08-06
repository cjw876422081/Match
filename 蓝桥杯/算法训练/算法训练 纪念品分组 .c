/*
��������
����Ԫ���쵽�ˣ�Уѧ���������ָ����������ļ���Ʒ���Ź�����Ϊʹ�òμ�����ͬѧ����õļ���Ʒ��ֵ ��Ծ��⣬
��Ҫ�ѹ����ļ���Ʒ���ݼ۸���з��飬��ÿ�����ֻ�ܰ�����������Ʒ������ÿ�����Ʒ�ļ۸�֮�Ͳ��ܳ���һ��������������
Ϊ�˱�֤�ھ����̵�ʱ ���ڷ������м���Ʒ������ϣ���������Ŀ���١�
�������������дһ�������ҳ����з��鷽���з��������ٵ�һ�֣�������ٵķ�����Ŀ��
�����ʽ
�����������n+2�У�
������1�а���һ������w��Ϊÿ�����Ʒ�۸�֮�͵����ޡ�
������2��Ϊһ������n����ʾ�����ļ���Ʒ���ܼ�����
������3~n+2��ÿ�а���һ��������pi (5 <= pi <= w)����ʾ����Ӧ����Ʒ�ļ۸�
�����ʽ
���������һ�У�����һ�������������ٵķ�����Ŀ��
��������
100
9
90
20
20
30
50
60
70
80
90
�������
6
���ݹ�ģ��Լ��
����50%���������㣺1 <= n <= 15
����100%���������㣺1 <= n <= 30000, 80 <= w <= 200
*/
#include<stdio.h>
void shuru( int [] , int  );
void shuchu( int [] , int , int );
void paixu( int [] , int , int );
int main( void )
{
	int w , n ,sz[30000]; 
    scanf("%d%d" , & w , & n );
    shuru( sz , n );
    paixu( sz , 0 , n - 1 );
	shuchu( sz , n , w );
    return 0;
}  
void paixu( int sz[] , int left , int  right)
{
	if( left >= right)
	{
		return ;
	}
	int i = left , j  = right ; 
	int key = sz[left] ;
	while ( i < j)
	{
		
		while( i < j && key <= sz[j])
		{
			j -- ; 
		}
		sz[i] = sz[j] ;
		while( i < j && key >= sz[i])
		{
			i ++ ;
		}
		sz[j] = sz[i];
	}
	sz[i] = key ;
	paixu( sz , left, i - 1 );
	paixu( sz , i + 1 , right ); 
}
void shuchu( int sz[] , int n , int p_w)
{
	int cs = 0 , i = 0 ;  
    int  j  = n - 1;  
    while(i <=  j ) 
	{  
        if(sz[i] + sz[j] <= p_w )
		{
			i ++ ;
		}
		j -- ;  
        cs ++ ;  
    }  
    printf("%d\n" , cs );
}
void shuru( int sz[] , int n)
{
	int i ; 
	for( i = 0 ; i <  n  ; i ++ )
	{
		scanf("%d", &sz[i]);
	}
    
}
