/*
��������
��������n����[a,b]�����������������ǵĺ�Ϊx�ĸ��ʡ�
�����ʽ
����һ�������ĸ���������Ϊn��a��b��x���ÿո�ָ���
�����ʽ
�������һ�а���һ��С��λ��Ϊx�ĸ��ʣ�С���������λС��
��������
2 1 3 4
�������
0.3333
���ݹ�ģ��Լ��
��������50%�����ݣ�n��5.
��������100%�����ݣ�n��100,b��100.
*/
#include<stdio.h>   
double dp[101][10001];
double jisuan( int , int , int , int );
int main( void ) 
{  
	int n, a, b, x;  
    scanf("%d%d%d%d", &n, &a, &b, &x);  
    printf("%.4lf\n",jisuan( n , a , b , x ));  
    return 0;  
}   
double jisuan( int n , int a , int b, int x)
{ 
	dp[0][0] = 1 ;  
    int  i , j  , k ;  
    for( i = 1 ; i <= n ; i ++ )
	 {  
        for( j = 0 ; j <= x ; j ++) 
		{  
            for( k = a ; k <= b ; k ++) 
			{  
                if(j >= k) 
				{
                	dp[i][j] += dp[i-1][j-k] / ( b - a + 1) ;  
				}
            }  
        }  
    }   
    return dp[n][x];
}
