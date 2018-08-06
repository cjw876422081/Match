/*
  算法训练 学做菜  
问题描述
　　涛涛立志要做新好青年，他最近在学做菜。由于技术还很生疏，他只会用
	鸡蛋，西红柿，鸡丁，辣酱这四种原料来做菜，我们给这四种原料标上字母A,B,C,D。
　　涛涛现在会做的菜有五种：
　　1、	西红柿炒鸡蛋 原料：AABDD
　　2、	酸辣鸡丁 原料：ABCD
　　3、	宫保鸡丁 原料：CCD
　　4、	水煮西红柿 原料：BBB
　　5、	怪味蛋 原料：AD
　　这天早上，开开去早市给涛涛买了一些原料回来。由于事先没有什么计划，
涛涛决定，对于现存的原料，每次尽量做菜单上靠前（即编号小）的菜。
　　现在请你写一个程序，判断一下开开和涛涛中午能吃到哪些菜。
输入格式
　　共4个整数a,b,c,d。分别表示开开买的A,B,C,D这4种原料的数量。每种原料不会超过30份。
输出格式
　　输出5行。其中第i行表示涛涛做的第i种菜的数目。
样例输入
3
1
2
4
样例输出
1
0
1
0
1
*/
#include <stdio.h>
#define YLS (4)
#define CZS (5) 
#define ZDS (30)
void shuru( int [] , int );
void shuchu( int [] , int );
void qc_yd( int , int [] , int [] , int );
int q_sm( int [] , int , int [] );
int q_fs( int , int ) ;
void q_csm( int [] , int , int [] , int , int [][YLS] );
int main(void)
{
	int yl[YLS];
	shuru( yl , YLS );
	int cgc[CZS][YLS] = { 	{ 2 , 1 , 0 , 2 } , { 1 , 1 , 1 , 1 } ,{ 0 , 0 , 2 , 1 } ,{ 0 , 3 , 0 , 0 } ,{ 1 , 0 , 0 , 1 } };
	int csm[CZS] = {0};
	q_csm( csm , CZS , yl , YLS , cgc );
	shuchu( csm , CZS );
	return 0;
}

int q_sm( int yl[] , int yls, int icgc[] )
{
	int sm = q_fs( yl[0] , icgc[0] );
	int i;
	for( i = 1 ; i < yls ; i ++ )
	{
		int tmp = q_fs( yl[i] , icgc[i] );
		if( tmp < sm)
		{
			sm = tmp ;
		}
	}
	qc_yd( sm , icgc , yl , yls );
	return sm ;
}

void qc_yd( int sm , int icgc[] , int yl[] , int yls )
{
	int i;
	for( i = 0 ; i < yls ; i ++ )
	{
		yl[i] -= icgc[i] * sm ;
	}	
}

int q_fs( int xyyl , int cyyl )
{
	if( cyyl != 0 )
	{
		return xyyl / cyyl ;
	}
	return ZDS ;
}

void q_csm( int csm[] , int czs , int yl[] , int yls, int cgc[][yls] )
{
	int i;
	for( i = 0 ; i < czs ; i ++ )
	{
		csm[i] += q_sm( yl , yls , cgc[i] );
	}
}

void shuchu( int sz[] , int n )
{
	int i ; 
	for( i = 0 ; i < n ; i ++ )
	{
		printf("%d\n" , sz[i]);
	}
}

void shuru( int sz[] , int n)
{
	int i ; 
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d" ,&sz[i]);
	}
}

