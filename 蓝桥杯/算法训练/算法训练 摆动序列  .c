/*��������
�������һ������������������ʣ����Ǿͽ�����Ϊ�ڶ����У�
����1. �����е����������ǲ�����k����������
����2. ��������������������
����3. �����е�����������ȣ�
����4. �����i �C 1�����ȵ�i �C 2���������i�����ȵ�i �C 2����С��
	�����i �C 1�����ȵ�i �C 2����С��
    ���i�����ȵ�i �C 2������
�������磬��k = 3ʱ�������漸�����������У�
����1 2
����1 3
����2 1
����2 1 3
����2 3
����2 3 1
����3 1
����3 2
����һ����8�֣�����k���������������Ҫ������еĸ�����
�����ʽ
�������������һ������k����k<=20��
�����ʽ
�������һ����������ʾ����Ҫ������и�����
��������
3
�������
8*/
#include<stdio.h>
#include<stdbool.h>

void shuru( int [] , int );
void pailie( int [] , int , int , int * );
void huan( int * , int * );
bool panduan( int [] , int );

int main(void)
{
	int n , sz[100] = {0}, gs = 0;
	scanf("%d", &n); 
	shuru( sz , n );
 	pailie( sz , 0 , n , &gs );
 	printf("%d\n", gs);
	return 0;
} 

bool panduan( int sz[] , int i )
{
	if(  i < 2 )
	{
		return true;
	}
	if( sz[i-1] > sz[i-2] && sz[i] < sz[i-2] )
	{
		return true;
	}
	if( sz[i-1] < sz[i-2] && sz[i] > sz[i-2] )
	{
		return true;
	}
	return false;
}

void huan( int * a , int * b )
{
	int tmp = * a;
	* a = * b;
	* b = tmp;
}

void pailie( int sz[] , int cs , int n , int * p_gs )
{
	if( cs == n )
	{
		return ;
	}
	int i;
	for( i = cs ; i < n ; i ++ )
	{
		huan( &sz[cs] , &sz[i] );
		if( panduan( sz , cs ) == true )
		{
			if( cs >= 1 )
			{
				++ * p_gs;
			}
			pailie( sz , cs + 1 , n , p_gs );
		}
		huan( &sz[cs] , &sz[i] );
	}
}

void shuru( int sz[] , int n )
{
	int i;
	for( i = 0 ; i < n ; i ++ )
	{
		sz[i] = i + 1 ;  
	}
}

