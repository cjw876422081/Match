/*
��������
������Ŀ�ܼ򵥣�����N�����֣����ı����ǵ����λ�ã����м����K���˺ź�N-K-1���Ӻţ����������ӣ�ʹ���ս����������Ϊ�˺źͼӺ�һ������N-1���ˣ�����ǡ��ÿ������������֮�䶼��һ�����š����磺
����N=5��K=2��5�����ֱַ�Ϊ1��2��3��4��5�����Լӳɣ�
����1*2*(3+4+5)=24
����1*(2+3)*(4+5)=45
����(1*2+3)*(4+5)=45
��������
�����ʽ
���������ļ����ж��У���һ��Ϊ�����пո��������������ʾN��K�����У�2<=N<=15, 0<=K<=N-1�����ڶ���Ϊ N���ÿո���������֣�ÿ��������0��9֮�䣩��
�����ʽ
��������ļ���һ�а���һ����������ʾҪ������Ľ��
��������
5 2
1 2 3 4 5
�������
120
����˵��
����(1+2+3)*4*5=120
15 14
9 9 9 9 9 9 9 9 9 9 9 9 9 9 9

*/ 
#include<stdio.h>
void shuru( long long  [] , int , long long  [][16]);
long long jisuan( long long  [] , int , int  ,long long  [][16] );
long long  max( long long  , long long  );
long long  min( long long , long long  );
int main( void )
{
	int n , m ; 
	scanf("%d%d" ,& n , &m );
	long long  sz[16]={0} , jg[16][16] = {0 };
	shuru( sz , n , jg );
	printf("%lld\n" , jisuan( sz , n , m , jg ));
	return 0 ; 
} 
long long  min( long long  a , long long  b )
{
	return a < b ? a : b ;   
}
long long  max( long long  a, long long  b)
{
	return a > b ? a : b ;
}
long long  jisuan( long long  sz[] , int n , int m ,long long  jg[][16] )
{
	int i , j , k ; 
    for( i = 1 ; i <= n ; i ++ ) 
	{   
   		for( j = 1 ; j <= m ; j ++ ) 
		{  
        	for(k = 2 ; k <= i ; k ++) 
			{ 
            	jg[i][j] = max( jg[i][j] , jg[k - 1][j - 1] * (sz[i] - sz[k - 1]));  
        	}  
    	}  
	}  
	return jg[n][m] ; 
}
void shuru( long long  sz[] , int n , long long  jg[][16])
{
	int i , shu ;
	for( i = 1 ; i <= n ; i ++ )
	{
		scanf("%d", & shu );
		sz[i] = sz[ i -1 ] + shu ; 
		jg[i][0] = sz[i] ; 
	}
}
