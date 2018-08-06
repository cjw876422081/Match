/*
问题描述
　　平面上有两个矩形，它们的边平行于直角坐标系的X轴或Y轴。对于每个矩形，我们给出它的一对相对顶点的坐标，请你编程算出两个矩形的交的面积。
输入格式
　　输入仅包含两行，每行描述一个矩形。
　　在每行中，给出矩形的一对相对顶点的坐标，每个点的坐标都用两个绝对值不超过10^7的实数表示。
输出格式
　　输出仅包含一个实数，为交的面积，保留到小数后两位。
样例输入
2 2 4 4
1 1 3 3

样例输出
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
