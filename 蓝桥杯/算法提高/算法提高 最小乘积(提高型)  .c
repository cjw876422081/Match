/*
��������
����������������n����
���������ÿ����������˳��ʹ������������ͬ�±�Ԫ�ض�Ӧ��ˣ�Ȼ����ӵĺ���С��Ҫ�������������Сֵ��
���������������ֱ�Ϊ:1 3����-5��-2 4 1

������ô��Ӧ�˻�ȡ�͵���СֵӦΪ��
����(-5) * 4 + 3 * (-2) + 1 * 1 = -25
�����ʽ
������һ����һ����T��ʾ��������������ÿ�����ݣ��ȶ���һ��n������������ÿ��n������ÿ�����ľ���ֵС�ڵ���1000��
����n<=1000,T<=10
�����ʽ
����һ������ʾ�𰸡�
��������

2
3
1 3 -5
-2 4 1
5
1 2 3 4 5
1 0 1 0 1


�������

-25
6


*/
#include <stdio.h>  
void paixu( int [] , int , int ) ; 
void shuru( int [] , int [] , int *);
void shuchu( int [] , int [] , int );
int main( void )  
{  
    int T ;  
    int s1[1000] , s2[1000];   
    scanf("%d",& T ) ;  
    while( T -- > 0 )  
    {  
        int n ; 
		shuru( s1 , s2 , &n ) ; 
        paixu( s1 , 0 , n - 1 );  
        paixu( s2 , 0 , n - 1 );
		shuchu( s1 , s2  , n );  
    }  
    return 0;  
}  
void shuchu( int s1[] , int s2[] , int p_n)
{
	int i , sum = 0 ; 
    for( i = 0 ; i < p_n ; i ++)  
    {  
        sum += s1[i] * s2[p_n - 1 - i ];  
    }  
    printf("%d\n",sum);  
}
void shuru( int s1[] , int s2[] , int * p_n)
{
    scanf("%d" , p_n) ; 
	int i ;  
    for(i = 0 ; i < * p_n ; i ++ )  
    {  
        scanf("%d" , & s1[i]);  
    }  
    for(i = 0 ; i < * p_n ; i ++ )  
    {  
        scanf("%d" , & s2[i]);  
    }  
}
void paixu( int sz[] , int  left , int  right)
{
	if( left  >=  right )
	{
		return ;
	}
	int i = left ; 
	int j = right ; 
	int key = sz[left];
	while( i < j )
	{
		while( i < j  && key <= sz[j])
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
	paixu( sz, left , i - 1 );
	paixu( sz , i + 1 , right);

}

