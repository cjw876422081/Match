/*问题描述
　　2016.4.5已更新此题，此前的程序需要重新提交。
问题描述
　　给定一个百分制成绩T，将其划分为如下五个等级之一：
　　90~100为A，80~89为B，70~79为C，60~69为D，0~59为E
　　现在给定一个文件inp，文件中包含若干百分制成绩（成绩个数不超过100），请你统计五个等级段的人数，并找出人数最多的那个等级段，按照从大到小的顺序输出该段中所有人成绩（保证人数最多的等级只有一个）。要求输出到指定文件oup中。
输入格式
　　若干0~100的正整数，用空格隔开
输出格式
　　第一行为5个正整数，分别表示A,B,C,D,E五个等级段的人数
　　第二行一个正整数，表示人数最多的等级段中人数
　　接下来一行若干个用空格隔开的正整数，表示人数最多的那个等级中所有人的分数，按从大到小的顺序输出。
样例输入
10
100 100 85 77 55 61 82 90 71 60
样例输出
2 3 2 2 1
3
85 82 80

*/
#include<stdio.h>
void shuru( int , int [] , int []);
void shuchu( int , int [] , int []);
void cunru( int [] , int [] , int  , int  , int * );
int q_tou( int );
int q_wei( int );
void paixu( int [] , int );
void huan( int * , int * );
void sc_sz( int [] , int );
int main( void )
{
	int n ;
	scanf("%d", &n );
	int sz[n] , gs[5] = {0}  ; 
	shuru( n , sz , gs );
	shuchu( n , sz , gs);
	return 0 ; 
}
void sc_sz( int sz[] , int n)
{
	int i ; 
	for( i = 0 ; i < n ; i ++ )
	{
		printf("%d " , sz[i]);
	}
}
void huan( int * a, int * b)
{
	int tmp = * a ; 
	* a = * b;
	* b = tmp ;  
}
void paixu( int sz[] , int n)
{
	int i , j ;
	for( i = 0 ; i < n ; i ++ )
	{
		for( j = 0 ; j < n - i -1 ; j ++ )
		{
			if( sz[j] < sz[j+1] )
			{ 
				huan( sz + j , sz + j + 1);
			}
		}
	}
}
int q_wei( int n )
{
	switch( n )
	{
		case 0 :return 100;
		case 1 :return 89;
		case 2 :return 79;
		case 3 :return 69;
		case 4 :return 59;
	}
	
}
int q_tou( int n )
{
	switch( n )
	{
		case 0 :return 90;
		case 1 :return 80;
		case 2 :return 70;
		case 3 :return 60;
		case 4 :return 0;
	}
	
}
void shuchu( int n , int sz[] , int gs[] )
{
	int i , xb = 0 , tmp = gs[0] ; 
	for( i = 0 ; i < 5 ; i ++ )
	{
		printf("%d " , gs[i] );
		if( tmp < gs[i] )
		{
			tmp = gs[i] ; 
			xb = i ;
		}
	}
	printf("\n%d\n" , tmp ) ;
	int cf[10000] , ws = 0 ;
	cunru( cf , sz , n , xb , &ws );
	paixu( cf , ws );
	sc_sz( cf , ws);
}
void cunru( int cf[] , int sz[] , int n , int  xb , int * p_ws )
{
	int i , tou = q_tou( xb ) , wei = q_wei( xb );
	for( i = 0 ; i < n ; i ++ )
	{
		if( tou <= sz[i] && sz[i] <= wei )
		{
			cf[* p_ws] = sz[i] ; 
			++ * p_ws ; 
		}
	}
}
void shuru( int n , int sz[] , int gs[])
{
	int i ;
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d" , &sz[i]);
		if( sz[i] >= 0 && sz[i] < 60)
		{
			gs[4] ++ ; 
		}
		if( sz[i] >= 60 && sz[i] < 70)
		{
			gs[3] ++ ; 
		}
		if( sz[i] >= 70 && sz[i] < 80)
		{
			gs[2] ++ ; 
		}
		if( sz[i] >= 80 && sz[i] < 90)
		{
			gs[1] ++ ; 
		}
		if( sz[i] >= 90 && sz[i] <= 100)
		{
			gs[0] ++ ; 
		}
	}
}
