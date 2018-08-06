/*��������
��������N����Ʒ,ÿ����Ʒ��һ������W��һ����ֵV.����һ����װM�����ı���.����ôװʹ����װ��ֵ���.
ÿ����Ʒֻ��һ��.
�����ʽ
��������ĵ�һ�а�����������n, m���ֱ��ʾ��Ʒ�ĸ����ͱ�����װ������
�����Ժ�N��ÿ��������Wi��Vi,��ʾ��Ʒ�������ͼ�ֵ
�����ʽ
�������1�У�����һ����������ʾ����ֵ��
��������
3 5
2 3
3 5
4 7
�������
8
���ݹ�ģ��Լ��
����1<=N<=200,M<=5000.
*/
#include<stdio.h>
int sz[201][5001]={0};
int tongji( int , int );
int max( int , int );
int main( void )
{
	int n , m ;
	scanf("%d%d", &n , &m );
	printf("%d" ,tongji( n , m ));
	return 0 ; 
} 
int max( int a, int b )
{
	return a > b ? a : b ;
}
int tongji( int n , int  m )
{
	int i , j ; 
    for( i = 1 ; i <= n ; i ++ ) 
	{
	    int w, v;
	    scanf("%d%d" , &w , &v ) ;
	    for( j = 1 ; j <= m; j ++ ) 
		{
	        if (j >= w)
	        {
	        	sz[i][j] = max(sz[i-1][j] , sz[i-1][j-w] + v) ;
			}
	        else
	        {
	        	sz[i][j] = sz[i-1][j];
			}
   		 }
	}
	return sz[n][m] ;
}
