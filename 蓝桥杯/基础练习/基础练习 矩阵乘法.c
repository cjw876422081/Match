/*
��������
��������һ��N�׾���A�����A��M���ݣ�M�ǷǸ�������
�������磺
����A =
����1 2
����3 4
����A��2����
����7 10
����15 22
�����ʽ
������һ����һ��������N��M��1<=N<=30, 0<=M<=5������ʾ����A�Ľ�����Ҫ�������
����������N�У�ÿ��N������ֵ������10�ķǸ���������������A��ֵ
�����ʽ
���������N�У�ÿ��N����������ʾA��M��������Ӧ�ľ������ڵ���֮����һ���ո����
��������
2 2
1 2
3 4
�������
7 10
15 22

*/
#include<stdio.h>
void shuru( int [][30] , int );
void shuchu( int [][30] , int );
void mcjc( int [][30] , int [][30] ,int , int );
void chushi(int [][30] , int );
int main(void)
{
	int n , m ;
	int jz[30][30];
	scanf("%d%d", &n , &m);
	shuru( jz , n  );
	int cf[30][30];
	chushi(cf , n);
	mcjc( jz , cf , n , m );
	shuchu( cf, n);
	return 0 ; 
}
void chushi(int jz[][30] , int n)
{
	int i , j ;
	for(i = 0; i < n; i ++ )
	{
		for( j = 0 ; j < n ; j ++)
		{
			if(i == j )
			{
				jz[i][j] = 1;
			}
			else
			{
				jz[i][j] = 0;
			}
		}
	}
} 
void mcjc( int jz[][30] , int cf[][30] , int n, int m)
{
	int i , j  , k;
	
	while(m -- > 0 )
	{
		int zj[30][30]={0};
		for(i = 0 ; i < n; i ++)
		{
			for(j = 0; j < n; j ++)
			{
				for( k = 0 ;  k < n ; k ++)
				{
					zj[i][j]+=cf[i][k]*jz[k][j];
				}
			}
		}
		for(i = 0 ; i < n; i ++)
		{
			for(j = 0; j < n; j ++)
			{
				cf[i][j]=zj[i][j];
			}
		}
		
	}
}
void shuchu( int jz[][30] , int n)
{
	int i , j ;
	for(i = 0 ; i < n ; i ++)
    {
    	for(j = 0 ; j < n ; j ++)
    	{
    		printf("%d ",jz[i][j]);
		}
		putchar('\n');
	}
}
void shuru( int jz[][30] , int n)
{
	int i , j ;
	for(i = 0 ; i < n ; i ++)
    {
    	for(j = 0 ; j < n ; j ++)
    	{
    		scanf("%d",&jz[i][j]);
		}
	}
} 
