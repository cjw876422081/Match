/*
��������
������дһ�����򣬶���һ�����������������ǰ��մ�С�����˳�����еģ����ǵĸ���NҲ�����û�����ģ���಻�ᳬ��20��Ȼ����򽫶�����������ͳ�ƣ��ѳ��ִ��������Ǹ�����Ԫ��ֵ��ӡ���������������Ԫ��ֵ���ֵĴ�����ͬ�������е�һ����ôֻ��ӡ�Ƚ�С���Ǹ�ֵ��
���������ʽ����һ����һ������N��N? ��? 20����������N�У�ÿһ�б�ʾһ�����������Ұ��մ�С�����˳�����С�
���������ʽ�����ֻ��һ�У������ִ��������Ǹ�Ԫ��ֵ��
�����������
��������
5
100
150
150
200
250
�������
150
*/
#include <stdio.h>
typedef
	struct
	{
		int zs ; 
		int cs ; 
	}
	shuju_t;
void shuru(shuju_t [] , int , int *);
int q_xb(shuju_t [] , int );
int main(void)
{
	int n , gs = 0 ;
	scanf("%d" ,&n);
	shuju_t sz[n];
	if( n > 0)
	{
		shuru(sz , n , &gs);
		printf("%d" ,sz[q_xb( sz , gs )].zs);
	} 
	return 0;
}
int q_xb( shuju_t sz[] ,int  n  )
{
    int i , max = 0;  
    for(i = 0 ; i < n ; i ++)  
    {  
        if( sz[i].cs > sz[max].cs)  
        {  
            max = i ;  
        }    
    }  
    return max ; 
}
void shuru(shuju_t sz[] , int n, int * p_gs)
{
	int xb = 0 ;
	scanf("%d", & sz[xb].zs );
	sz[xb].cs = 1 ;
	while( -- n > 0 )
	{
		int shu ;
		scanf("%d" ,&shu );
		if( shu == sz[xb].zs) 
		{
			sz[xb].cs ++ ;  
		}
		else
		{
			xb ++ ;
			sz[xb].zs = shu ;
			sz[xb].cs = 1 ;
		}
	}
	*p_gs = xb + 1 ;
}

