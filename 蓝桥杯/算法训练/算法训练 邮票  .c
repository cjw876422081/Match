/*��������
��������һ���ŷ⣬��N��1��N��100����λ�ÿ�������Ʊ��ÿ��λ��ֻ����һ����Ʊ��
����������M(M<=100)�ֲ�ͬ���ʵ���Ʊ����ֵΪX1,X2��.Xm�֣�Xi��������1��Xi��255����ÿ�ֶ���N�š�
������Ȼ���ŷ���������������Сֵ��min(X1, X2, ��, Xm)�����ֵ�� N*max(X1, X2, ��,����Xm)��
�����������õ�������ֵ���γ�һ�����ϣ�������û���ظ���ֵ����Ҫ���������������Ƿ���ڴ�1��ĳ��ֵ�������������У����������е����ֵ��
�������磬N=4��M=2����ֵ�ֱ�Ϊ4�֣�1�֣������γ�1��2��3��4��5��6��7��8��9��10��12��13��16�����У�
����1��ʼ��������������Ϊ1��2��3��4��5��6��7��8��9��10�����������������е����ֵΪ10�֡�
�����ʽ
������һ�У��������ճ������Ʊ����N���ڶ��У���Ʊ����M�������У��ո������M�����֣���ʾ��Ʊ����ֵXi��
ע�⣺Xi���в�һ���Ǵ�С����ģ�
�����ʽ
������1��ʼ�������������е����ֵMAX���������ڴ�1�ֿ�ʼ�����У����������Ʊ��û��1��������Ʊ����
�����0.
��������
����һ��
4
2
4 1
��������
10
5
2 4 6 8 10
�������
����һ��
10
��������
0
20
10
1 14 101 116 144 168 178 228 242 247

*/
#include<stdio.h>  
void shuru( int [] , int );
void shuchu( int [], int );
int q_max( int [] , int );
void chushihua( int [] , int );
void jisuan(int [] , int [] , int , int ,int  );
void fr_yp( int [] , int [] , int , int  );
int main( void ) 
{  
	int n , m , max ; 
	scanf("%d%d" ,& n , & m ) ;
	int sz[m] ;  
	shuru( sz ,  m );
	max = q_max( sz , m ) ;
	int cf[ n * max + 1] ; 
	chushihua( cf , n * max + 1 );
	cf[0] = 1 ;
	jisuan( cf , sz , n , m , max );
    shuchu( cf , n * max + 1 );
	return 0;  
}  
void chushihua( int cf[] , int n)
{
	int i ; 
	for(i = 0 ; i < n ; i ++ )
	{
		cf[i] = 0 ; 
	}	
}
void jisuan(int cf[] , int sz[] , int n , int m , int max )
{
	int i ; 
	for( i = 0 ; i < n ; i ++ )
	{
		int  j ; 
		for( j = i * max ; j >= 0 ; j -- )
		{
			if( cf[j] == 1 )
			{
				fr_yp( cf , sz , m , j );
			}
		}
	}
}
void fr_yp( int cf[] , int sz[] , int m , int cs )
{
	int i ; 
	for( i = 0 ; i < m ; i ++)
	{
		cf[cs + sz[i]] = 1 ; 
	}
}
int q_max( int sz [] , int n)
{
	int i , max = 0 ; 
	for( i = 0 ; i < n ; i ++ )
	{
		if( sz[i] > sz[max])
		{
			max = i ; 
		}
	}
	return sz[max] ; 
}
void shuchu( int sz[] , int n  )
{
	int i ; 
	for(i = 0 ; i < n ; i ++ )
	{
		if( sz[i] == 0 )
		{
			printf("%d\n" , i - 1);
			return ; 
		}
	}
}

void shuru( int sz[] , int n)
{
	int i ;
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d", & sz[i]);
	}
}
