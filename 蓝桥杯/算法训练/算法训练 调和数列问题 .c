/*��������
��������һ��ʵ��x������С��nʹ�ã�1/2+1/3+1/4+...+1/(n+1)>=x��
���������ʵ��x��֤���ڵ���0.01��С�ڵ���5.20��
����ǡ������λС������ĳ���Ҫ�ܹ�����������ݣ�����ͣ�ض���x�����x������0.00�������𰸣������˳�����
���������ʽΪ����һ��x�����һ��n card(s)������n��ʾҪ����Ĵ𰸡�
�����ʽ
������������x�ľ�����ֵ
�����ʽ
�����������n����ֵ����ʽΪn card(s)
��������
1.00
3.71
0.04
5.19
0.00
�������
3 card(s)
61 card(s)
1 card(s)
273 card(s)
*/
#if 1 
#include<stdio.h>
int jisuan( double );
int main(void)
{
	double s ; 
	while( 1 )
	{
		scanf("%lf" ,&s ) ; 
		if( s == 0.00 )
		{
			break ; 
		}
		printf("%d card(s)\n" , jisuan( s )) ; 
	}
	return 0 ;  
}
int jisuan( double  n )
{
    double sum = 0.0 ;
    int  i;   
	for( i = 2 ; i < 300 ; i ++ )
	{  
        sum += (double) (1.0/ i ) ;  
        if( sum >= n )
		{  
            return  i - 1  ; 
        }  
    }  
}
#endif
