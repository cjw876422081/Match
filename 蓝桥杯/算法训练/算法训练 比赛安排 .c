/*

问题描述
　　设有有2 n（n<=6）个球队进行单循环比赛，计划在2 n – 1天内完成，
每个队每天进行一场比赛。设计一个比赛的安排，使在2 n – 1天内每个队都与不同的对手比赛。
输入格式
　　输入文件matchplan.in共一行，输入n的数值。
输出格式
　　输出文件matchplan.out共（2 n – 1）行，第i行输出第i天的比赛安排。
　　格式为：<i> A-B，C-D，……。其中i是天数，A，B分别为比赛双方的编号，每行共2 n-1个比赛场次。
样例输入
2
样例输出
<1>1-2,3-4
<2>1-3,2-4
<3>1-4,2-3

*/
#if 1 
#include <stdio.h>    
void solve(int [][100], int , int , int ) ;  
int main( void )  
{  
    int n , size;  
    scanf("%d", &n);  
    size = 1 ;  
    int sz[100][100] = { 0 } , i , j ; 
    for( i = 0 ; i < n ; i ++)
	{  
        size *= 2 ;  
    }  
    for( i = 1 ; i <= size ; i ++ )
	{  
        sz[0][i] = i;  
    }  
    solve( sz , size , 1 , size ) ;  
    for( i = 1 ; i < size ; i ++ ) 
	{  
        printf("<%d>", i) ;  
        for(j = 1 ; j <= size ; j ++)
		{  
            if( sz[i][j] > j )
			{  
                printf("%d-%d ", j , sz[i][j]);  
            }                 
        }  
        printf("\n");  
    }  
    return 0;  
} 
void solve(int sz[][100], int s , int left, int right)  
{  
    if( s < 2 )
	{  
        return;  
    }  
    int i, j;  
    int mid = (left + right) / 2;     
    s /= 2 ;  
    solve( sz , s , left , mid ) ;  
    solve( sz , s , mid + 1 , right ) ;  
    for( i = 0 ; i <= s ; i ++ )
	{  
        for( j = left ; j <= mid ; j ++ )
		{  
            sz[i+s][j+s] = sz[i][j] ;  
        }  
        for( j = mid + 1 ; j <= right ; j ++ )
		{  
            sz[i+s][j-s] = sz[i][j];  
        }  
    }  
} 
#endif 
