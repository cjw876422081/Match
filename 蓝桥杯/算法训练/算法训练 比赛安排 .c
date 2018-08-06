/*

��������
����������2 n��n<=6������ӽ��е�ѭ���������ƻ���2 n �C 1������ɣ�
ÿ����ÿ�����һ�����������һ�������İ��ţ�ʹ��2 n �C 1����ÿ���Ӷ��벻ͬ�Ķ��ֱ�����
�����ʽ
���������ļ�matchplan.in��һ�У�����n����ֵ��
�����ʽ
��������ļ�matchplan.out����2 n �C 1���У���i�������i��ı������š�
������ʽΪ��<i> A-B��C-D������������i��������A��B�ֱ�Ϊ����˫���ı�ţ�ÿ�й�2 n-1���������Ρ�
��������
2
�������
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
