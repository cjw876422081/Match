/*
问题描述
　　为二维空间中的点设计一个结构体，在此基础上为三角形设计一个结构体。
	分别设计独立的函数计算三角形的周长、面积、中心和重心。
	输入三个点，输出这三个点构成的三角形的周长、面积、外心和重心。结果保留小数点后2位数字。
样例输出
与上面的样例输入对应的输出。
例：
数据规模和约定
　　输入数据中每一个数的范围。
　　例：doule型表示数据。
0 0
0 1
1 0

*/
#if 1 
#include<stdio.h>
#include<math.h>
typedef
struct
{
	double x ; 
	double y ; 
}Point ; 
void Input( Point [] , int );
void Output( Point [] , int ); 
double Perimeter(Point [] );
double Area(Point [] );
double External_x(Point []);  
double External_y(Point []);
double GravityOfCenter_x(Point []);
double GravityOfCenter_y(Point []);
int main(void)
{
	Point p[3] ; 
	Input( p ,  3 ); 
	Output( p ,  3 ); 
	return 0 ; 
	
}
double GravityOfCenter_y(Point p[])
{
	return (p[0].y+p[1].y+p[2].y)/3;
}
double GravityOfCenter_x(Point p[])
{
	return (p[0].x+p[1].x+p[2].x)/3;
}
double External_y(Point p[])
{
	double a=2*(p[0].x-p[1].x);
    double b=2*(p[0].y-p[1].y);
    double z=p[0].x*p[0].x-p[1].x*p[1].x+p[0].y*p[0].y-p[1].y*p[1].y;
    double a1=2*(p[2].x-p[1].x);
    double b1=2*(p[2].y-p[1].y);
    double z1=p[2].x*p[2].x-p[1].x*p[1].x+p[2].y*p[2].y-p[1].y*p[1].y;
    return ((a*z1)-(a1*z))/((a*b1)-(a1*b));
}
double External_x(Point p[])
{
	double a=2*(p[0].x-p[1].x);
    double b=2*(p[0].y-p[1].y);
    double z=p[0].x*p[0].x-p[1].x*p[1].x+p[0].y*p[0].y-p[1].y*p[1].y;
    double a1=2*(p[2].x-p[1].x);
    double b1=2*(p[2].y-p[1].y);
    double z1=p[2].x*p[2].x-p[1].x*p[1].x+p[2].y*p[2].y-p[1].y*p[1].y;
	return ((z*b1)-(z1*b))/((a*b1)-(a1*b));
}
double Area(Point p[])
{
	return (p[0].x*p[1].y+p[1].x*p[2].y+p[2].x*p[0].y-p[0].x*p[2].y-p[1].x*p[0].y-p[2].x*p[1].y)/2; 
}
double Perimeter(Point p[])
{
    double d1=sqrt(pow(p[0].x-p[1].x,2)+pow(p[0].y-p[1].y,2));
    double d2=sqrt(pow(p[1].x-p[2].x,2)+pow(p[1].y-p[2].y,2));
    double d3=sqrt(pow(p[0].x-p[2].x,2)+pow(p[0].y-p[2].y,2));
    return d1+d2+d3;
}
void Output( Point p[] , int n)
{
	printf("%.2lf\n", Perimeter(p));
   	printf("%.2lf\n",fabs(Area(p)));
    printf("%.2lf %.2lf\n",External_x(p) , External_y(p));
    printf("%.2lf %.2lf\n",GravityOfCenter_x(p),GravityOfCenter_y(p));
}


void Input( Point p[] , int n)
{
	int i ; 
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%lf%lf", &p[i].x , &p[i].y) ; 
	}
}
#endif 
