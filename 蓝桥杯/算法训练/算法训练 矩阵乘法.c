/*
��������
���������������󣬷ֱ���m*s��s*n��С���������������˵Ľ����
�����ʽ
������һ�У��ո����������������m,s,n����������200����
����������m�У�ÿ��s���ո��������������ʾ����A��i��j����
����������s�У�ÿ��n���ո��������������ʾ����B��i��j����
�����ʽ
����m�У�ÿ��n���ո��������������������ľ���C��i��j����ֵ��
��������
2 3 2
1 0 -1  
1 1 -3
0 3
1 2 
3 1
�������
-3 2
-8 2

5 2 10
7 3
9 3
3 9
9 6
9 4
9 5 2 8 7 0 1 5 6 3
1 9 9 4 4 3 9 1 8 1

��ʾ
����CӦ����m��n�У�����C(i,j)���ھ���A��i�������������B��j�����������ڻ���
����������C(1,1)=(1,0,-1)*(0,1,3) = 1 * 0 +0*1+(-1)*3=-3
*/
#include<stdio.h>
void shuru( int m , int s , int n, int [][s] ,int [][n] );
void jisuan( int m , int s , int n, int [][s] ,int [][n] , int [][n] );
void shuchu( int m , int n  , int [][n]);
int main( void )
{
	int m , s , n ;
	scanf("%d%d%d" , &m , &s , &n);
	int jz1[m][s] , jz2[s][n];
	int c[m][n]; 
	shuru(  m , s , n , jz1 , jz2  );
	jisuan( m , s , n , jz1 , jz2 , c );
	shuchu( m , n , c );
	return 0 ; 
}
void jisuan( int m , int s , int n, int jz1[][s] ,int jz2[][n] , int c[][n] )
{
	int i , j , k ; 
    for( i = 0 ; i < m ; i ++)  
    {  
        for( j = 0 ; j < n ; j ++)  
        {  
        	c[i][j] = 0 ; 
            for( k = 0 ; k < s ; k ++)  
            {  
                c[i][j] += jz1[i][k] * jz2[k][j];  
            }  
        }  
    }  
}
void shuchu( int m , int n  , int c[][n])
{
	int i , j ; 
	for( i = 0 ; i < m ; i ++ )
	{
		for( j = 0 ; j < n ; j ++ )
		{
			printf("%d ", c[i][j]);
		}
		putchar('\n');
	}
}
void shuru( int m , int s , int n, int jz1[][s] ,int jz2[][n] )
{
	int i , j ; 
	for( i = 0 ; i < m ; i ++ )
	{
		for( j = 0 ; j < s ; j ++ )
		{
			scanf("%d", &jz1[i][j]);
		}
	}
	for( i = 0 ; i < s ; i ++ )
	{
		for( j = 0 ; j < n ; j ++ )
		{
			scanf("%d", &jz2[i][j]);
		}
	}
}
