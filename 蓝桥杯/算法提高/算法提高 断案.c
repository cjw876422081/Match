/* 问题描述
　　公安人员审问甲、乙、丙、丁四个嫌疑犯，已确知，这四个人当中仅有一人是偷窃者，
还知道这四个人的答话，要么完全诚实，要么完全说谎。在回答公安人员的问话中：
　　甲说：“乙没有偷，是丁偷的。”
　　乙说：“我没有偷，是丙偷的。”
　　丙说：“甲没有偷，是乙偷的。”
　　丁说：“我没有偷，我用的那东西是我家里的。”
　　请根据上述四人答话，判断谁是偷窃者。
　　输入格式：无输入。
　　输出格式：输出一个字符，表示偷窃者是谁，A表示甲，B表示乙，C表示丙，D表示丁。
*/
#include<stdio.h>
void shuchu( int [] , int [] );
int pd_sc( int [], int []);
int main( void )
{
	int a[4]={0} , sz[4]={0}  ;
	shuchu( sz , a );
	return 0 ; 
}
int pd_sc( int a[] ,int  sz[])
{
	if (a[0] != 1) 
	{  
		if (!(sz[1] == 1 &&sz[3] == 0)) 
		{  
			return 0 ; 
		}  
	}  
	if (a[1] != 1) 
	{  
		if (!(sz[1] == 1 && sz[2] == 0)) 
		{  
		  	return 0 ;  
		}  
	}  
	if (a[2] != 1)
	{  
		if (!(sz[0] == 1 && sz[1] == 0))
		{  
			return 0 ; 
		}  
	}  
	return 1 ; 
}
void shuchu( int sz[] , int a[] )
{
	int i  ; 
	for( i = 0 ;  i < 4 ; i ++ )
	{
		sz[i] = 1 ;
		a[0] = sz[1] != 1 && sz[3] == 1 ; 
		a[1] = sz[1] != 1 && sz[2] == 1 ;
		a[2] = sz[0] != 1 && sz[1] == 1 ;
		a[3] = sz[3] != 1 ;
		if( pd_sc( a  , sz ))
		{
			printf("%c ", i + 'A' ); 
		}
		sz[i] = 0 ;
	}
}
