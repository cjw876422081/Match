/*
问题描述
　　3000米长跑时，围观党们兴高采烈地预测着最后的排名。因为他们来自不同的班，对所有运动员不一定都了解，
于是他们分别对自己了解的一些运动员的实力作出了评估，即对部分运动员做了相对排名的预测，
并且告诉了可怜留守的班长。因为无聊，于是他们就组团去打Dota去了。比赛结束后他们向班长询问最后的排名，
但班长不记得了，只记得他们中哪些人的预测是正确的，哪些人的预测是错误的。他们想知道比赛的排名可能是什么。
输入格式
　　第一行两个整数n， m，n为运动员数量，m为围观党数量。运动员编号从0到n-1。
　　接下来m行，每行为一个围观党的相对排名预测。每行第一个数c表示他预测的人数，后面跟着c个0~n-1的不同的数，
表示他预测的运动员相对排名，最后还有一个数，0表示这个预测是错误的，1表示是正确的。
输出格式
　　第一行一个数k为有多少种排名的可能。
　　下面k行，每行一个0~n-1的排列，为某一个可能的排名，相邻的数间用空格隔开。所有排名按字典序依次输出。
样例输入
Input Sample 1:
3 2
2 0 1 1
2 1 2 0
Input Sample 2:
3 2
2 0 1 1
2 2 1 0
样例输出
Output Sample 1:
2
0 2 1
2 0 1
Output Sample 2:
1
0 1 2
数据规模和约定
　　1<=n<=10, 2<=c<=n, 1<=m<=10，保证数据合法，且答案中排名可能数不超过20000。
对于一个排名序列，一个预测是正确的，当且仅当预测的排名的相对顺序是排名序列的一个子序列。
一个预测是错误的，当且仅当这个预测不正确。
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

