/*������
��������
����A������һ���޴��Բ�ι㳡��Ϊ���̻������;���������������������Բ�ι㳡��Ȧ��һȦ����԰�ֲ��� �õ�ָ��󣬳����滮��n��������λ�ã�˳ʱ����1��n������ÿ��λ�ö���һ�����۶�Ai����������������Ϳ��Եõ���Ai�����۶ȡ�������A�������� ����Ƿ�ѣ��������������������ڵ�λ�ã�i��λ�ú�i+1��λ�ý�����λ�á�ֵ��ע�����1�ź�n��Ҳ������λ�ã�����
����������������԰�ֲ����ṩ��m�����粢Ҫ��ȫ�����ϣ������æ�����������ʹ�����۶��ܺ��������޷���m������ȫ�����ϣ������޽���Ϣ��
�����ʽ
��������ĵ�һ�а�������������n��m��
�����ڶ���n������Ai��
�����ʽ
�������һ����������ʾ���ֲ���������Եõ������۶ȡ�����޽������Error!�������������š�
��������
7 3
1 2 3 4 5 6 7
�������
15
��������
7 4
1 2 3 4 5 6 7
�������
Error!
���ݹ�ģ��Լ��
��������ȫ�����ݣ�����1<=m<=n<=30��
��������90%����������m<=n<=20
����-1000<=Ai<=1000
*/
#if 1
#include <stdio.h>
#include <stdlib.h>

void Input( int [] , int ) ;
void Output( int , int , int [] ) ;
int Solve( int , int , int [] , int [] , int ) ;

int main(void)  
{  
	int n , m ;
	scanf("%d%d", & n , & m ) ;
	int tree[n] ;
	Input( tree , n ) ; 
	Output( n , m , tree ) ;
    return 0;  
}

int Solve( int n , int m , int tree[] , int sz[] , int k )
{
	if( k >= n && m > 0 ) 
    {  
        return -1 ;  
    }
	int mg = 0 , i = -1 , j = -1 ;
	if( k < n && m > 0 )
	{
		if( sz[( k + 1 ) % n ] == 0 )
		{
			sz[k] = 1 ;
			i = Solve( n , m - 1 , tree , sz , k + 2 );
			sz[k] = 0 ;
		}
		j = Solve( n , m , tree , sz , k + 1 ) ;
        if( i != -1 && mg < i + tree[k]) 
		{
			mg = i + tree[ k ] ;
		} 
        if( j != -1 && mg < j ) 
		{
			mg = j ;
		} 
        if( i == -1 && j == -1) 
		{
			mg = -1 ; 
		}
	}
	return mg ;
}

void Output( int n , int m , int tree[] )
{
	if(  m > ( n / 2 ) )
	{
		printf("Error!");
		return ;
	}
	int sz[50] = { 0 } ;
	printf("%d" , Solve( n , m , tree , sz , 0 ) );
}

void Input( int tree[] , int n )
{
	int i;
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d", & tree[i] ) ;
	}
}

#endif
