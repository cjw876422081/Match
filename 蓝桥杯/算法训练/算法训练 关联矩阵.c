/*

��������
������һ��n�����m���ߵ�����ͼ����������Ĺ�������
�����ʽ
������һ����������n��m����ʾͼ�н��ͱߵ���Ŀ��n<=100,m<=1000��
����������m�У�ÿ����������a��b����ʾͼ����(a,b)�ߡ�
����ע��ͼ�п��ܺ����رߣ����������Ի���
�����ʽ
���������ͼ�Ĺ�������ע������ı�ߺͽ���˳��
��������
5 9
1 2 
3 1 
1 5
2 5
2 3
2 3
3 2
4 3
5 4
�������
1 -1 1 0 0 0 0 0 0  
-1 0 0 1 1 1 -1 0 0
0 1 0 0 -1 -1 1 -1 0
0 0 0 0 0 0 0 1 -1
0 0 -1 -1 0 0 0 0 1

*/
#include<stdio.h>
void shuru( int n , int m , int [][m]);
void shuchu( int n , int m , int [][m]);
int main( void )
{
	int n , m ;
	scanf("%d%d",&n, &m);
	int jz[n][m];
	shuru(n , m , jz );
	shuchu( n , m , jz );
	return 0 ; 
}
void shuru( int n , int m , int jz[][m])
{
	int i , j ;
	int s1 , s2 ;
	for( i = 0 ; i < m ; i ++)
	{
		scanf("%d%d", &s1 , &s2);
		for( j = 0 ; j < n ; j ++ )
		{
			if( j == s1 - 1)
			{
				jz[j][i] = 1 ;
			}
			else
			{
				if(j == s2 - 1 )
				{
					jz[j][i] = - 1 ;
				}
				else
				{
					jz[j][i] = 0;
				}
			}
		}
	
	}
}
void shuchu( int n , int m , int jz[][m])
{
	int i , j ;
	for( i = 0 ; i < n ; i ++)
	{
		for( j = 0 ; j < m ; j ++ )
		{
			printf("%d ",jz[i][j]);
		}
		putchar('\n'); 
	}
}
