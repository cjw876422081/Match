/*
��������
�����������ϣ�����1986�꣬�ɿ���˹������������ģ�����ϸ���Զ�����һ�֡�
����ƽ���ϵ������θ��ӱ����Ϻ�ɫ���ɫ��������һ������������һֻ�����ϡ���
�������ϵ�ͷ������Ϊ��������������һ����
�������ϵ��ƶ�����ʮ�ּ򵥣�
�����������ںڸ���ת90�ȣ����ø��Ϊ�׸񣬲���ǰ��һ��
�����������ڰ׸���ת90�ȣ����ø��Ϊ�ڸ񣬲���ǰ��һ��

����������Ȼ�򵥣����ϵ���Ϊȴʮ�ָ��ӡ��ոտ�ʼʱ���µ�·�߶����нӽ��Գƣ����ǻ��ظ�����������ʼ״̬��Σ����Ͼ��������Ļ��һ�󣬻Ὺ�ٳ�һ������ġ����ٹ�·����

�������ϵ�·���Ǻ�������Ԥ��ġ�

������������Ǹ��ݳ�ʼ״̬���ü����ģ�����������ڵ�n�����ߺ�������λ�á�
�����ʽ
�����������ݵĵ�һ���� m n ����������3 < m, n < 100������ʾ�����θ��ӵ�������������
������������ m �����ݡ�
����ÿ������Ϊ n �����ո�ֿ������֡�0 ��ʾ�׸�1 ��ʾ�ڸ�

������������һ�����ݣ�x y s k, ����x yΪ��������ʾ���������кź��кţ��кŴ��ϵ����������кŴ��������������Ǵ�0��ʼ��ţ���s ��һ����д��ĸ����ʾ����ͷ�ĳ�������Լ�����������ҷֱ��ã�UDLR��ʾ��k ��ʾ�����ߵĲ�����
�����ʽ
�����������Ϊ�����ո�ֿ������� p q, �ֱ��ʾ������k�����������ӵ��кź��кš�
��������
5 6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
2 3 L 5
�������
1 3
��������
3 3
0 0 0
1 1 1
1 1 1
1 1 U 6
�������
0 0
*/
#include<stdio.h>
 
void shuru( int [][100] , int , int );
void jisuan( int [][100] , int *, int * , char , int );
void bhgz( int [][100] , int , int );
char q_fw( char , int );
int b_x( char , int  ) ;
int b_y( char , int  ) ;
int main( void )
{
	int n , m ; 
	int sz[100][100];
	scanf("%d%d" ,&n , & m );
	shuru( sz , n , m );
	int x , y , s , k ; 
	scanf("%d%d %c%d", &x , & y , & s , & k );
	jisuan( sz , &x , &y , s ,  k ); 
	printf("%d %d\n" , x  ,  y );
	return 0 ; 
}
int b_y( char c , int  y ) 
{
	if( c == 'L' ) 
	{
		return y - 1 ;
	} 
    else 
	{
		if( c == 'R')  
    	{
    		return y + 1 ; 
		} 
    	else
		{
			return y ;
		}  
	}
}
int b_x( char c , int  x ) 
{
	if( c == 'U' ) 
	{
		return x - 1 ;
	} 
    else 
	{
		if( c == 'D')  
    	{
    		return x + 1 ; 
		} 
    	else
		{
			return x ;
		}  
	}
}
char q_fw( char c , int  n)
{
	if( n == 0 )
	{
		switch( c )
		{
			case 'U' : return 'L'; 
			case 'L' : return 'D';
			case 'D' : return 'R';
			case 'R' : return 'U';
		}
	}
	if( n == 1 )
	{
		switch( c )
		{
			case 'U' : return 'R'; 
			case 'R' : return 'D';
			case 'D' : return 'L';
			case 'L' : return 'U';
		}
	}
}
void bhgz( int sz[][100] , int x , int y)
{
	sz[x][y] = sz[x][y] == 0 ? 1 : 0 ;
}
void jisuan( int sz[][100] ,int * x , int * y , char s , int k)
{
	int i ; 
	for( i = 0 ; i < k ; i ++ )
	{
		s = q_fw( s , sz[ * x ][ * y ] );
		bhgz( sz , * x  , * y );
		* x = b_x( s , *x ) ;
		* y = b_y( s , *y ) ;  
	}
}
void shuru( int sz[][100] , int n , int m  )
{
	int i , j ; 
	for( i = 0 ; i < n ; i ++ )
	{
		for( j = 0 ; j < m ; j ++ )
		{
			scanf("%d" ,& sz[i][j] ) ;
		}
	}
} 
