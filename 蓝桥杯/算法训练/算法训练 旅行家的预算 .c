/*
��������
����һ�����м����ʻ���������ٵķ��ô�һ�����е���һ�����У��������ʱ�����ǿյģ���
	������������֮��ľ���D1���������������C������Ϊ��λ����ÿ����������ʻ�ľ���D2��
	������ÿ�����ͼ۸�P����;��վ��N��N����Ϊ�㣩����վi�������ľ���Di��
	ÿ�����ͼ۸�Pi��i=1��2������N��������������������С�������λ������޷�����Ŀ�ĵأ�
	�������No Solution����
�����ʽ
������һ��Ϊ4��ʵ��D1��C��D2��P��һ���Ǹ�����N��
����������N�У�ÿ������ʵ��Di��Pi��
�����ʽ
����������Ե���Ŀ�ĵأ����һ��ʵ��������������С�������λ������ʾ��С���ã�
`���������No Solution�����������ţ���
��������
275.6 11.9 27.4 2.8 2
102.0 2.9
220.0 2.2
�������
26.95
*/
#include<stdio.h>
double count_min_expense( double [] , double [] , int  ); 
int main( void )
{
	double D1 , C , D2 , P ;
	int n ;
	scanf("%lf%lf%lf%lf",&D1 , &C , &D2 , &P);
	scanf("%d",&n );
	double  distance[n+1] , price[n+1];
	double  maxv = C*D2 ; 
	int i ;
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%lf%lf",&distance[i] , &price[i]);
		if( distance[i] - distacne[i-1] > maxv &&  i > 0)
		{
			printf("No Solution\n");
		}
	}
	distance[n] = D1 ; 
	printf("%.2lf" ,count_min_expense( distance , price , n ));
	return 0;
} 
double count_min_expense( double p_d[] , double p_p[] , int n )
{
	while( )
}

