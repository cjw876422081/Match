/*
  �㷨ѵ�� ѧ����  
��������
����������־Ҫ���º����꣬�������ѧ���ˡ����ڼ����������裬��ֻ����
	������������������������������ԭ�������ˣ����Ǹ�������ԭ�ϱ�����ĸA,B,C,D��
�����������ڻ����Ĳ������֣�
����1��	������������ ԭ�ϣ�AABDD
����2��	�������� ԭ�ϣ�ABCD
����3��	�������� ԭ�ϣ�CCD
����4��	ˮ�������� ԭ�ϣ�BBB
����5��	��ζ�� ԭ�ϣ�AD
�����������ϣ�����ȥ���и���������һЩԭ�ϻ�������������û��ʲô�ƻ���
���ξ����������ִ��ԭ�ϣ�ÿ�ξ������˵��Ͽ�ǰ�������С���Ĳˡ�
������������дһ�������ж�һ�¿��������������ܳԵ���Щ�ˡ�
�����ʽ
������4������a,b,c,d���ֱ��ʾ�������A,B,C,D��4��ԭ�ϵ�������ÿ��ԭ�ϲ��ᳬ��30�ݡ�
�����ʽ
�������5�С����е�i�б�ʾ�������ĵ�i�ֲ˵���Ŀ��
��������
3
1
2
4
�������
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

