/*
��������
���������磺ax3+bx2+cx+d=0 ������һ��һԪ���η��̡������÷����и����ϵ��(a��b��c��d ��Ϊʵ��)����Լ���÷��̴���������ͬʵ��(���ķ�Χ��-100��100֮��)���Ҹ����֮��ľ���ֵ>=1��Ҫ������ʵ������
�����ʽ
�����ĸ�ʵ����a��b��c��d
�����ʽ
������С����������ͬһ�����������ʵ��(�����֮�����пո�)������ȷ��С�����2λ
��������
1 -5 -4 20
�������
-2.00 2.00 5.00
���ݹ�ģ��Լ��
����|a|��|b|��|c|��|d|<=10
*/
#include<stdio.h >
double f(double , double, double , double , double ) ; 
int main( void )
{
	double  a , b , c , d ; 
	scanf("%lf%lf%lf%lf" , & a , & b , & c ,& d );
	int x ; 
	for(x = -10000 ; x < 10000 ; x ++ )
	{            
        double x1=( x - 0.05 ) * 1.00 / 100 , x2 = ( x + 0.05 ) * 1.00 /100 ;    
        if( f( x1 , a , b, c , d ) * f( x2 , a , b, c , d) < 0 )
		{
			printf("%.2lf ", x * 1.00 / 100 );  
		}     
    }  
    printf("\n");  
	return 0 ; 
}
double f(double x , double a , double b , double c , double d )
{  
    return x * x * x + b * 1.00 / a * x * x + c * 1.00 / a * x + d * 1.00 / a ;  
}  
