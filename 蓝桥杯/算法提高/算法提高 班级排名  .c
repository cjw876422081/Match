/*
��������յ�Ӱ���£�Ҳ��ѧϰ�����Ĳ�������Ȥ��
��������ÿ�ο���֮�󣬶���׷����ʦ�ʣ��Լ��ڰ༶���������Ƕ��١�����һ�࣬��ʦҲ���ͷ��ˣ����������˴�������˵ĳɼ��������Լ�ȥ����Լ���������
��������̫���ˣ����Ҳ�޷������������������������������
�����ʽ
������һ��Ϊһ������N������༶��ѧ��������
����������N�У�ÿ��һ���ַ���������һ��ѧ������������һ������DaDa��
����������һ��һ������M������һ����M�ο��ԡ�
����ÿ�ο�����N�У�ÿ������һ���ո�ָ���һ��������S��һ���ַ���P����������ΪP��ѧ������ο����е���S�֡�
�����ʽ
����һ��M�У�ÿ��һ���������������ڰ༶�����������������һ�ο��Թ�������п����ܷ�������������ͱ��˲��У������������ǰ�档
��������
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
�����������
1
2
���ݹ�ģ��Լ��
����N <= 100�����ֳ��Ȳ�����30������������100
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
void lj_fs(XX_t *,XX_t *,int);//�ۼƷ��� 
int shi_yizhi(char *,char *);//�Ƿ�һ�� 
void paixu(XX_t *,int);//���� 
void huan(XX_t *,XX_t *);//����-�� 
int q_mc(XX_t *,int);//������ 

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

