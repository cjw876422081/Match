/*问题描述
　　“两只小蜜蜂呀，飞在花丛中呀……”
　　话说这天天上飞舞着两只蜜蜂，它们在跳一种奇怪的舞蹈。用一个空间直角坐标系来描述这个世界，
那么这两只蜜蜂初始坐标分别为(x1,y1,z1)，(x2,y2,z2)　　。
在接下来它们将进行n次飞行，第i次飞行两只蜜蜂分别按照各自的速度向量飞行ti个单位时间。
对于这一现象，玮玮已经观察了很久。他很想知道在蜜蜂飞舞结束时，两只蜜蜂的距离是多少。
现在他就求教于你，请你写一个程序来帮他计算这个结果。
输入格式
　　第一行有且仅有一个整数n，表示两只蜜蜂将进行n次飞行。
　　接下来有n行。
　　第i行有7个用空格分隔开的整数ai,bi,ci,di,ei,fi,ti　　，表示第一只蜜蜂单位时间的速度向量为(ai,bi,ci) ，
第二只蜜蜂单位时间的速度向量为(di,ei,fi) ，它们飞行的时间为ti 。
　　最后一行有6个用空格分隔开的整数x1,y1,z1,x2,y2,z2，如题所示表示两只蜜蜂的初始坐标。
输出格式
　　输出仅包含一行，表示最后两只蜜蜂之间的距离。保留4位小数位。
样例输入
Sample 1
1
1 1 1 1 -1 1 2
3 0 1 2 0 0
Sample 2
3
1 1 1 1 -1 1 2
2 1 2 0 -1 -1 2
2 0 0 -1 1 1 3
3 0 1 2 0 0
样例输出
Sample 1
4.2426
Sample 2
15.3948*/
#if 1 
#include<stdio.h>
#include<math.h>
void Input( int [] , int [] ,int  , int [] ,int []);
double jisuan( int [] , int [] ); 
int main(void)
{
	int  n ; 
	int xi[3] = { 0 }, yi[3] ={ 0 };
	int x[3] = { 0}  , y[3] = { 0 } ; 
	scanf("%d" ,& n ) ;
	Input( xi , yi , n  , x , y );
	printf("%.4lf" , jisuan( x ,  y)) ; 
 	return 0 ; 
}
double jisuan( int x[] , int y[] )
{
	int x_t = abs( x[0] - y[0] ) ; 
	int y_t = abs( x[1] - y[1] ) ;
	int z_t = abs( x[2] - y[2] ) ;
	return sqrt( x_t*x_t + y_t * y_t + z_t*z_t ) ; 
}
void Input( int xi[] , int yi[] ,int  n, int x[] ,int y[])
{
	int i , j  , t ; 
	for( i = 0 ; i < n ; i ++ )
	{
		for( j = 0 ; j < 3 ; j ++ )
		{
			scanf("%d" , &xi[j] );
		}
		for( j = 0 ; j < 3 ; j ++ )
		{
			scanf("%d" , &yi[j] );
		}
		scanf("%d" , & t) ;
		for( j = 0 ; j < 3 ; j ++ )
		{  
            x[j] += xi[j] * t ;  
            y[j] += yi[j] * t ;  
        } 
	}
	int tmp ;
    for( i = 0 ; i < 3 ; i ++ )
	{  
        scanf("%d",  & tmp ) ;  
        x[i] += tmp ;  
    }  
    for( i = 0 ; i < 3 ; i ++ )
	{  
        scanf("%d", & tmp ) ;  
        y[i] += tmp ;  
    }  
}
#endif
