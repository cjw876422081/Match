/*
��������
��һ�� n ���ڵ����������ÿ���ڵ㶼��һ��������Ȩֵ�����һ���㱻ѡ���ˣ���ô�����Ϻ������ڵĵ㶼���ܱ�ѡ��
��ѡ���ĵ��Ȩֵ������Ƕ��٣�
�����ʽ
��һ�а���һ������ n ��
��������һ�а��� n ������������ i ������������� i ��Ȩֵ��
������һ�� n-1 �У�ÿ���������ϵ�һ���ߡ�
�����ʽ
���һ������������ѡ���ĵ��Ȩֵ�͵����ֵ��
��������
5
1 2 3 4 5
1 2
1 3
2 4
2 5
�������
12
����˵��
ѡ��3��4��5�ŵ㣬Ȩֵ��Ϊ 3+4+5 = 12 ��
���ݹ�ģ��Լ��
����20%�����ݣ� n <= 20��
����50%�����ݣ� n <= 1000��
����100%�����ݣ� n <= 100000��
Ȩֵ��Ϊ������1000����������
*/

#include<stdio.h>

int jd[100000][100];
void shuru( int , int [][2] );
void xieru( int , int );
int max( int , int );
void jisuan( int , int [][2], int , int );
int main( void )
{
	int n ; 
	scanf("%d", &n) ;
	int qz[n][2];
	shuru( n , qz );
	jisuan( n , qz , 1  , 0 );
	printf("%d\n", max( qz[1][0] , qz[1][1] ));
	return 0;
}
void jisuan( int n , int qz[][2] , int  i , int j )
{
	int  t , k = 0 ; 
   	while(t = jd[i][k++]) 
	{        
	    if(t != j )  
	    {    
	    	jisuan( n , qz , t , i ); 
	        qz[i][1] += qz[t][0];                    
	        qz[i][0] += max( qz[t][0] , qz[t][1]);   
	   	}  
	}  
	
}
int max( int a , int b )
{
	return a > b ? a : b ;
}
void xieru( int a , int  b )
{
	int i = 0 , j = 0 ; 
    while(jd[a][i] != 0)
	{
		i ++ ;
	}
    jd[a][i] = b ;      
    while(jd[b][j] != 0 )  
    {
    	j ++;
	}
    jd[b][j] = a ;  
}
void shuru( int n , int qz[][2] )
{
	int i ; 
    for( i = 1 ; i <= n ; i ++ ) 
	{
		scanf("%d" , & qz[i][1]);
		qz[i][0] = 0 ;
	}
	int zjd , fjd ; 
    for( i = 1 ; i < n ; i ++ )   
    {  
        scanf("%d%d" , & zjd , &fjd );  
        xieru( zjd , fjd );             
    }  
	
}
