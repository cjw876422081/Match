/*
��������
����3000�׳���ʱ��Χ�۵����˸߲��ҵ�Ԥ����������������Ϊ�������Բ�ͬ�İ࣬�������˶�Ա��һ�����˽⣬
�������Ƿֱ���Լ��˽��һЩ�˶�Ա��ʵ�����������������Բ����˶�Ա�������������Ԥ�⣬
���Ҹ����˿������صİ೤����Ϊ���ģ��������Ǿ�����ȥ��Dotaȥ�ˡ�����������������೤ѯ������������
���೤���ǵ��ˣ�ֻ�ǵ���������Щ�˵�Ԥ������ȷ�ģ���Щ�˵�Ԥ���Ǵ���ġ�������֪������������������ʲô��
�����ʽ
������һ����������n�� m��nΪ�˶�Ա������mΪΧ�۵��������˶�Ա��Ŵ�0��n-1��
����������m�У�ÿ��Ϊһ��Χ�۵����������Ԥ�⡣ÿ�е�һ����c��ʾ��Ԥ����������������c��0~n-1�Ĳ�ͬ������
��ʾ��Ԥ����˶�Ա��������������һ������0��ʾ���Ԥ���Ǵ���ģ�1��ʾ����ȷ�ġ�
�����ʽ
������һ��һ����kΪ�ж����������Ŀ��ܡ�
��������k�У�ÿ��һ��0~n-1�����У�Ϊĳһ�����ܵ����������ڵ������ÿո�����������������ֵ������������
��������
Input Sample 1:
3 2
2 0 1 1
2 1 2 0
Input Sample 2:
3 2
2 0 1 1
2 2 1 0
�������
Output Sample 1:
2
0 2 1
2 0 1
Output Sample 2:
1
0 1 2
���ݹ�ģ��Լ��
����1<=n<=10, 2<=c<=n, 1<=m<=10����֤���ݺϷ����Ҵ�������������������20000��
����һ���������У�һ��Ԥ������ȷ�ģ����ҽ���Ԥ������������˳�����������е�һ�������С�
һ��Ԥ���Ǵ���ģ����ҽ������Ԥ�ⲻ��ȷ��
*/
#if 1 
#include<stdio.h>

typedef
struct
{
	int rs ; 
	int pf[12] ; 
	int pd ; 
}Pre_t ; 

void Input( Pre_t [] , int ); 
void dfs( int , int * , int , int , Pre_t [] , int [][20] ,int [] , int []) ; 
int check( int  , int  , Pre_t []  , int [] ) ;
void Output( int , int  , int [][20] ) ;

int main(void)
{
	int n , m  , sum = 0 ;
	scanf("%d%d" , & n , & m ) ;
	int gra[20001][20] ={ 0 } ; 	
	Pre_t sj[20] ; 
	Input( sj ,  m  ); 
	int s1[20] = {0} , s2[20] = {0}; 
	dfs(  0 , &sum , n , m , sj , gra , s1 , s2 ) ; 
	Output( n , sum , gra ); 
	return 0 ; 
} 
void Output( int n , int sum , int gra[][20] ) 
{
	printf("%d\n" , sum );
	int i , j ; 
    for( i = 0 ; i < sum ; i ++ )
    {
        for( j = 0 ; j < n ; j ++ )
        {
            printf("%d " , gra[i][j] ) ;
        }
        putchar('\n') ; 
    }
}
int check(int n ,  int m ,  Pre_t p[]  , int s1[]  ) 
{

    int i , j , k  ;
    for ( i = 0 ; i < m ; i ++ )
    {
        int s = p[i].rs ;
        for ( j = 0 , k = 0 ; k < s && j < n ; )
        {
            if ( p[i].pf[k] == s1[j] )
            {
                k ++ ;
                j ++ ; 
            }
            else
            {
            	j ++ ;
			}
        }
        if (( k != s && p[i].pd == 1 ) || ( k == s && p[i].pd == 0 ))
        {
            return 0;
        }
    }
    return 1;
}
void dfs( int x ,  int *sum , int n , int m ,Pre_t sj[] , int gra[][20] , int s1[] ,int s2[]) 
{
	int i ; 
	if( x == n )
	{
		if( check( n ,  m , sj ,  s1 ) == 1  )
		{
			for( i = 0 ; i < n ; i ++ )
	        {
	            gra[*sum][i] = s1[i] ;
	        }
	        ++ *sum ;
		}
		return ; 
	}
	for( i = 0 ; i < n ; i ++ )
    {
        if( s2[i] == 0 )
        {
            s2[i] = 1 ;
            s1[x] = i ;
            dfs( x + 1 , sum , n , m , sj , gra , s1 , s2  ); 
            s2[i] = 0;
        }
    }
}

void Input( Pre_t p[] ,  int m)
{
	int i , j ; 
	for( i = 0 ; i < m ; i ++ )
	{
		scanf("%d" , &p[i].rs ) ; 
		for( j = 0 ; j < p[i].rs  ; j ++  )
		{
			scanf("%d" , & p[i].pf[j] ) ; 
		}
		scanf("%d" , & p[i].pd ) ; 
	}
}
#endif

