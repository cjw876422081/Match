/*
��������
����Torry��Сϲ����ѧ��һ�죬��ʦ����������2��3��5��7����������������������TorryͻȻ�뵽һ�����⣬
ǰ10��100��1000��10000�����������ĳ˻��Ƕ����أ�����������������ʦ����ʦ�ס�ˣ�һʱ�ش𲻳�����
����Torry�����ڻ��̵��㣬�������ǰn�������ĳ˻������������ǵ���ŽӴ���̲��ã�TorryֻҪ����������ģ��50000��ֵ��
�����ʽ
����������һ��������n������n<=100000��
�����ʽ
�������һ�У���ǰn�������ĳ˻�ģ50000��ֵ
������
1
�������
2
*/
#include<stdio.h>  
#include<stdbool.h>

long long jisuan(  int );
bool pd_zs( int );
int main( void )  
{  
    int n;  
    scanf("%d",&n);  
    printf("%lld\n",jisuan( n ));  
    return 0;  
}
long long jisuan(  int  n )
{
	int sum = 0 , i = 2 ;
	long long shu = 1  ;
	while(sum < n)  
    {  
        if(pd_zs( i ) == true )  
        {  
            shu = shu * i % 50000;  
            sum ++ ;  
        }  
        i ++ ;  
    }  
    return shu ;
}  
bool pd_zs( int  n)  
{  
	int i ; 
    for( i = 2 ; i * i <= n ; i ++)  
    {  
        if( n % i == 0 ) 
		{
			return false ;  
		} 
            
    }  
    return true;  
}  
