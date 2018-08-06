/*
达达在陶陶的影响下，也对学习慢慢的产生了兴趣。
　　他在每次考试之后，都会追着老师问，自己在班级的总名次是多少。考试一多，老师也不耐烦了，于是他给了达达所有人的成绩，让他自己去算出自己的排名。
　　可人太多了，达达也无法立即算出来，于是他想让你帮帮他。
输入格式
　　第一行为一个整数N，代表班级的学生总数。
　　接下来N行，每行一个字符串，代表一个学生的姓名，第一行总是DaDa。
　　接下来一行一个整数M，代表一共有M次考试。
　　每次考试有N行，每行有以一个空格分隔的一个正整数S和一个字符串P，代表名字为P的学生在这次考试中得了S分。
输出格式
　　一共M行，每行一个整数，代表达达在班级里的排名，排名是这一次考试过后的所有考试总分排名，如果达达和别人并列，达达总是排在前面。
样例输入
3
DaDa
A
B
2
49 DaDa
49 A
48 B
80 A
85 B
83 DaDa
【样例输出】
1
2
数据规模和约定
　　N <= 100，名字长度不超过30，分数不超过100
*/
#include <stdio.h>
#include <string.h>
typedef
	struct
	{
		int fs;
		char xm[30+1];
	} XX_t ;

void sr_xs(XX_t *,int);
void sc_xs(XX_t *,int);
void shuru(XX_t *,int);
void lj_fs(XX_t *,XX_t *,int);//累计分数 
int shi_yizhi(char *,char *);//是否一致 
void paixu(XX_t *,int);//排序 
void huan(XX_t *,XX_t *);//排序-换 
int q_mc(XX_t *,int);//求名次 

int main(void)
{
	freopen( "input6.txt" , "r" , stdin ); 
	int N;
	scanf("%d", &N );
	XX_t xs[N];
	sr_xs(xs,N);
	int M;
	scanf("%d\n", &M );
	while( M -- > 0 )
	{
		XX_t xsxx[N];
		shuru(xsxx,N);
		lj_fs(xs,xsxx,N);
		paixu(xs,N);
		printf("%d\n", q_mc(xs,N) );
	}
	return 0;
}

int q_mc(XX_t * xs,int N)
{
	int i = 0 ;
	while( strcmp( xs[i].xm , "DaDa") != 0 ){
		++ i ;
	}
	while( i > 0 && xs[i].fs == xs[i-1].fs ){
		-- i;
	}
	return i+1 ; 
/*
	for( i = 0 ; i < N ; i ++ )
	{
		if( strcmp(xs[i].xm,"DaDa") == 0 )
		{
			break;
		}
	}
	for( ; i > 0 ; -- i ){
		if( xs[i].fs != xs[i-1].fs) {
			return i+1 ;
		}
	}
	return 1 ;
*/
}

void huan(XX_t * p_1,XX_t * p_2)
{
	 XX_t tmp = * p_1;
	 * p_1 = * p_2 ;
	 * p_2 = tmp ;
}

void paixu(XX_t * xs,int N)
{
	int i;
	for( i = 0 ; i < N ; i ++ )
	{
		int j;
		for( j =  0 ; j < N - i - 1   ; j ++ )
		{
			if( xs[j].fs < xs[j + 1].fs )
			{
				huan(xs + j,xs + j + 1);
			}
		}
	}
}

void lj_fs(XX_t * xs,XX_t * xsxx,int N)
{
	int i;
	for( i = 0 ; i < N ; i ++ )
	{
		int j;//xx
		for( j = 0 ; j < N ; j ++ )
		{
			if( strcmp(xs[i].xm,xsxx[j].xm) == 0 )
			{
				xs[i].fs += xsxx[j].fs;
			}
		}
	}
}

void shuru(XX_t * xsxx,int N)
{
	int i;
	for( i = 0 ; i < N ; i ++ )
	{
		scanf("%d%s", &xsxx[i].fs , xsxx[i].xm );
	}
}


void sr_xs(XX_t * xs,int N)
{
	int i;
	for( i = 0 ; i < N ; i ++ )
	{
		xs[i].fs = 0;
		scanf("%s", xs[i].xm );
	}
}

