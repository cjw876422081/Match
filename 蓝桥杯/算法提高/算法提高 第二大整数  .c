/*

��������
������дһ�����򣬶���һ��������������20���������û�����0ʱ����ʾ���������
	Ȼ����򽫴����������У��ѵڶ�����Ǹ������ҳ�������������ӡ������
	˵������1��0��ʾ������������������������������С���2�������������У�����������Ҳ�����и�������3�����������ĸ���������2����
���������ʽ������ֻ��һ�У��������ɸ��������м��ÿո���������һ������Ϊ0��
���������ʽ������ڶ�����Ǹ�������
���������������
��������
5 8 -12 7 0

�������
7

*/
#include<stdio.h>
void shuru(int [] , int *) ; 
void shuchu( int [] , int );
void huan( int * ,int *);
int main(void )
{
	int sz[20+1];
	int ws = 0; 
	shuru( sz , &ws);
	shuchu(sz , ws );
	return 0;
}
void huan( int * a ,int * b)
{
	int tmp = *a ;
	*a = * b ;
	*b = tmp ;
}
void shuchu( int sz[] , int p_ws)
{
	int i ,j ; 
	for( i = 0 ; i < 2 ; i ++ )
	{
		for( j = i + 1 ; j < p_ws ; j ++ )
		{
			if( sz [i] <  sz[j])
			{
				huan( &sz[i] , &sz[j] );
			}
			
		}
	} 
	printf("%d" ,sz[1]);
}
void shuru(int sz[] , int *p_ws)
{
	int i ; 
	for( i = 0 ; scanf("%d",&sz[i]) && sz[i]!= 0 ; i ++)
	{
		++ * p_ws;
	}
}
