/*
��������
����ƽ�������������Σ����ǵı�ƽ����ֱ������ϵ��X���Y�ᡣ����ÿ�����Σ����Ǹ�������һ����Զ�������꣬����������������εĽ��������
�����ʽ
����������������У�ÿ������һ�����Ρ�
������ÿ���У��������ε�һ����Զ�������꣬ÿ��������궼����������ֵ������10^7��ʵ����ʾ��
�����ʽ
�������������һ��ʵ����Ϊ���������������С������λ��
��������
2 2 4 4
1 1 3 3

�������
1.00
*/ 
#include<stdio.h>
double xz_max( double , double );
double xz_min( double , double );
void shuchu( double ,double ,double ,double );
int main(void)
{  
    double x1 , y1 , x2 , y2 ;    
    double x3 , y3 , x4 , y4 ;    
    double dx1,dy1;       
	double dx2,dy2; 	 
    scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);  
    scanf("%lf%lf%lf%lf",&x3,&y3,&x4,&y4);  
    dx1 = xz_max(xz_min(x1,x2),xz_min(x3,x4));  
    dy1 = xz_max(xz_min(y1,y2),xz_min(y3,y4));  
    dx2 = xz_min(xz_max(x1,x2),xz_max(x3,x4));  
    dy2 = xz_min(xz_max(y1,y2),xz_max(y3,y4));  
    shuchu( dx1 , dy1 , dx2 , dy2 );
    return 0;  
} 
void shuchu( double p_m1,double p_n1 , double p_m2 , double p_n2)
{
	if( p_m2 > p_m1 && p_n2 > p_n1)
	{
		printf("%.2lf\n",(p_m2 - p_m1)*(p_n2 - p_n1));  	
	}  
    else
	{
		printf("0.00\n");
	}  
}
double xz_max( double a , double b)
{
	return a > b ? a : b;
}  
double xz_min( double a , double  b)
{
	return a < b ? a : b ;
} 
