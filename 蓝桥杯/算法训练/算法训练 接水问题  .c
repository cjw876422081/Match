/*
问题描述
　　学校里有一个水房，水房里一共装有m 个龙头可供同学们打开水，每个龙头每秒钟的 供水量相等，均为1。 现在有n 名同学准备接水，
他们的初始接水顺序已经确定。将这些同学按接水顺序从1 到n 编号，i 号同学的接水量为wi。接水开始时，
1 到m 号同学各占一个水龙头，并同时打 开水龙头接水。当其中某名同学j 完成其接水量要求wj 后，
下一名排队等候接水的同学k 马上接替j 同学的位置开始接水。这个换人的过程是瞬间完成的，且没有任何水的浪费。
即 j 同学第x 秒结束时完成接水，则k 同学第x+1 秒立刻开始接水。若当前接水人数n’不足m， 则只有n’个龙头供水，
其它m?n’个龙头关闭。 现在给出n 名同学的接水量，按照上述接水规则，问所有同学都接完水需要多少秒。
输入格式
　　第1 行2 个整数n 和m，用一个空格隔开，分别表示接水人数和龙头个数。 第2 行n 个整数w1、w2、……、wn，每两个整数之间用一个空格隔开，wi 表示i 号同 学的接水量。
输出格式
　　输出只有一行，1 个整数，表示接水所需的总时间。
样例输入
5 3
4 4 1 2 1
样例输出
4
样例输入
8 4
23 71 87 32 70 93 80 76
样例输出
163
输入输出样例 1 说明
　　第1 秒，3 人接水。第1 秒结束时，1、2、3 号同学每人的已接水量为1，3 号同学接完
　　水，4 号同学接替3 号同学开始接水。
　　第2 秒，3 人接水。第2 秒结束时，1、2 号同学每人的已接水量为2，4 号同学的已接
　　水量为1。
　　第3 秒，3 人接水。第3 秒结束时，1、2 号同学每人的已接水量为3，4 号同学的已接
　　水量为2。4 号同学接完水，5 号同学接替4 号同学开始接水。
　　第4 秒，3 人接水。第4 秒结束时，1、2 号同学每人的已接水量为4，5 号同学的已接
　　水量为1。1、2、5 号同学接完水，即所有人完成接水。
　　总接水时间为4 秒。
数据规模和约定
　　1 ≤ n ≤ 10000，1 ≤m≤ 100 且m≤ n；
　　1 ≤ wi ≤ 100。

*/ 
#include<stdio.h>
void shuru( int [] , int ); 
int q_sj( int [] , int [],int , int );
void shuru2( int [] , int  ,int []);
int max( int [] , int );
int min( int [] , int );
int main( void )
{
	int n , m ; 
	scanf("%d%d" , &n , &m );
	int sz[n];
	shuru( sz , n );
	int lt[m];
	shuru2( lt , m  ,sz);
	printf("%d\n",q_sj( lt , sz , n , m ));
	return 0 ; 
}
void shuru2( int lt[] , int m , int sz[])
{
	int i ; 
	for( i = 0 ; i < m; i ++ )
	{
		lt[i] = sz[i];
	}
}
int max( int sz[] , int n)
{
	int shu = sz[0] , i  ;
	for( i = 1 ; i < n ; i ++ )
	{
		if( shu < sz[i] )
		{
			shu = sz[i] ; 
		}
	}
	return shu ; 
}
int min( int sz[] , int n)
{
	int shu = sz[0] , i  , xb = 0 ;
	for( i = 1 ; i < n ; i ++ )
	{
		if( shu > sz[i] )
		{
			shu  = sz[i] ; 
			xb = i ;
		}
	}
	return xb ; 
}

int q_sj( int lt[],int sz[] , int p_n , int p_m)
{
	int i ;
	for( i = p_m ; i < p_n  ; i ++ )
	{
		lt[ min( lt , p_m)] += sz[ i ];
	}
	return max(lt , p_m ) ;
}

void shuru( int sz[] , int n )
{
	int i ;
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d", &sz[i]);
	 } 
 } 
