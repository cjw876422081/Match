/*
��������
����������������a��b����������������ĺ͡�a��b��������100λ��
�㷨����
��������a��b���Ƚϴ����Բ���ֱ��ʹ�������еı�׼�����������洢�������������⣬һ��ʹ������������
��������һ������A��A[0]���ڴ洢a�ĸ�λ��A[1]���ڴ洢a��ʮλ���������ơ�ͬ��������һ������B���洢b��
��������c = a + b��ʱ�����Ƚ�A[0]��B[0]��ӣ�����н�λ��������ѽ�λ�����͵�ʮλ��������r��
�Ѻ͵ĸ�λ������C[0]����C[0]����(A[0]+B[0])%10��Ȼ�����A[1]��B[1]��ӣ�
��ʱ��Ӧ����λ��������ֵrҲ����������C[1]Ӧ����A[1]��B[1]��r�������ĺͣ�
������н�λ���������Կɽ��µĽ�λ���뵽r�У��͵ĸ�λ�浽C[1]�С��������ƣ��������C������λ��
�������C������ɡ�
�����ʽ
��������������У���һ��Ϊһ���Ǹ�����λa���ڶ���Ϊһ���Ǹ�����b������������������100λ����������߶�����0��
�����ʽ
�������һ�У���ʾa + b��ֵ��
��������
20100122201001221234567890
2010012220100122
�������
20100122203011233454668012
*/
#include<stdio.h>
void shuru( int [] , int *);
void q_nx( int [] , int );
void shuchu( int [] , int);
void q_he(int [] , int , int [] , int , int [] , int * );
void put_in(int [] , int [] , int [] , int  );
int main( void )
{
	int s1[100]={0} ,s2[100]={0} ,c[101]={0};
	int cd1=0,cd2=0;
	shuru(s1 , &cd1 );
	shuru(s2 , &cd2 );
	int ws=0;
	q_he(s1 , cd1 , s2 , cd2 , c , &ws);
	shuchu( c , ws);
	return 0;
}
void put_in(int s1[] , int s2[] , int c[] , int cd )
{
	int i;
	for(i = 0 ; i < cd ; i ++)
	{
		c[i]=s1[i]+s2[i];
	}
}
void q_he(int s1[] , int cd1, int s2[] , int cd2, int c[] , int * ws)
{
	int n=cd1 > cd2 ? cd1 : cd2;
	put_in( s1 , s2 , c , n);
	int i;
	for(i = 0 ; i < n ; i ++)
	{
		c[i+1] += c[i]/10;
		c[i] %= 10;
		++ *ws;
	}
	if(c[n] > 0)
	{
		++ *ws;
	}
	
}
void shuchu( int sz[] , int n)
{
	int i;
	for( i = n-1 ; i >=0 ; i--)
	{
		printf("%d",sz[i]);
	}
	putchar('\n');
}
void q_nx( int sz[] , int n)
{
	int tou=0,wei = n -1;
	while(tou < wei)
	{
		int tmp=sz[tou];
		sz[tou]=sz[wei];
		sz[wei]=tmp;
		tou++;
		wei--;
	}
}
void shuru( int sz[] , int * cd)
{
	char c;
	while((c = getchar()) !='\n' )
	{
		sz[*cd] = c -'0';
		++ *cd ;
	}
	q_nx( sz , * cd );
}

