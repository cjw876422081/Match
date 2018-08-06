/*
问题描述
　　某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：
虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭。
由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。
　　输入导弹依次飞来的高度（雷达给出的高度数据是不大于30000的正整数），计算这套系统最多能拦截多少导弹，
	如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。
输入格式
　　一行，为导弹依次飞来的高度
输出格式
　　两行，分别是最多能拦截的导弹数与要拦截所有导弹最少要配备的系统数
样例输入
389 207 155 300 299 170 158 65
样例输出
6
2
*/
#include <stdio.h>
void shuru( int [] , int * );
void shuchu( int [] , int );
int max( int , int );
int main( void )
{
	int sz[100000] , gs = 0  ;
	shuru( sz , & gs );
	shuchu( sz ,  gs );
	return 0 ; 
}
int max( int a , int b)
{
	return a > b ? a : b ;
}
//389 207 155 300 299 170 158 65
void shuchu( int sz[] , int n )
{
	int i ,j , up[10000]={0} , down[10000]={0};
	int s1 = 0 , s2 = 0; 
    for(i = 0 ; i < n  ; i ++)  
    {  
        up[i] = 1 ; 
		down[i] = 1 ;  
        for(j = 0 ; j < i ; j ++ )  
        {  
            if(sz[i] > sz[j]) 
			{
				up[i] = max( up[i] , up[j] + 1 );
			} 
            else
			{
				down[i] = max( down[i] , down[j] + 1 ); 
			} 
                  
        }  
        s1 = max( s1 , down[i] );  
       	s2 = max( s2 , up[i] );  
    }  
    printf("%d\n%d" , s1 , s2 ) ;  	
}

void shuru( int sz[] , int * p_gs)
{
	char c ; 
	while( 1 )
	{
		scanf("%d",&sz[*p_gs]);
		++ *p_gs ; 
		if((c = getchar()) =='\n')
		{
			break ; 
		}
	}
}
