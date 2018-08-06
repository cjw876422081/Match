
/*
问题描述
　　给定一个矩阵A,一个非负整数b和一个正整数m，求A的b次方除m的余数。
　　其中一个nxn的矩阵除m的余数得到的仍是一个nxn的矩阵，这个矩阵的每一个元素是原矩阵对应位置上的数除m的余数。
　　要计算这个问题，可以将A连乘b次，每次都对m求余，但这种方法特别慢，当b较大时无法使用。下面给出一种较快的算法(用A^b表示A的b次方)：
　　若b=0，则A^b%m=I%m。其中I表示单位矩阵。
　　若b为偶数，则A^b%m=(A^(b/2)%m)^2%m，即先把A乘b/2次方对m求余，然后再平方后对m求余。
　　若b为奇数，则A^b%m=(A^(b-1)%m)*a%m，即先求A乘b-1次方对m求余，然后再乘A后对m求余。
　　这种方法速度较快，请使用这种方法计算A^b%m，其中A是一个2x2的矩阵，m不大于10000。
输入格式
　　输入第一行包含两个整数b, m，第二行和第三行每行两个整数，为矩阵A。
输出格式
　　输出两行，每行两个整数，表示A^b % m的值。
样例输入
2 2
1 1
0 1
样例输出
1 0
0 1

0 1
41 18467 
6334 26500 
1 2134
19169 15724 
11478 29358 
*/
#include <stdio.h>

void shuru( int [][2] , int );
void shuchu( int [][2] , int );
void copy( int [][2] , int [][2] , int );
void q_chengfang( int [][2] ,  int  , int );
void jisuan(int [][2], int [][2] , int );

int main(void)
{
    int b , m , jz[2][2] ;
    scanf("%d%d", &b , &m);
	shuru( jz , 2  );
    q_chengfang(jz, b, m);
	shuchu( jz , 2 );
    return 0 ;
}
void jisuan(int jz1[][2], int jz2[][2] , int m)
{
    int i , j , k ;
    int sum , t[2][2] ;
    for( i = 0 ; i < 2 ; i ++)
	{
        for(j = 0 ; j < 2 ; j ++)
		{
            sum = 0;
            for( k = 0 ; k < 2 ; k ++)
			{
                sum += jz1[i][k] * jz2[k][j];
            }
            t[i][j] = sum % m ;
        }
    }
    copy( jz1 , t , 2 );
}

void q_chengfang( int jz[][2] , int p_b , int p_m)
{

    if(p_b == 0)
	{
		int i, j;
        for(i = 0 ; i < 2 ; i ++ )
		{
            for(j = 0 ; j < 2 ; j ++)
			{
                if(i == j)
				{
                    jz[i][j] = 1 % p_m ;
                }
				else
				{
                    jz[i][j] = 0 % p_m ;
                }
            }
        }
        return;
    }
	else
	{
		if(p_b % 2 == 0)
		{
			q_chengfang(jz, p_b / 2, p_m);
	        jisuan(jz, jz, p_m);
		}
		else
		{
			int cf[2][2];
	        copy(cf, jz , 2 );
	        q_chengfang(jz, p_b-1, p_m);
	       	jisuan(jz, cf, p_m);
	    }
	}
}


void copy( int a[][2] , int b[][2] , int n )
{
	int i, j;
    for(i = 0 ; i < n ; i ++)
	{
        for(j = 0 ; j < n ; j ++)
		{
            a[i][j] = b[i][j];
        }
    }
}
void shuchu( int jz[][2]  ,int n)
{
	int i , j ;
	for(i = 0 ; i < n ; i ++)
    {
    	for(j = 0 ; j < n ; j ++)
    	{
    		printf("%d ", jz[i][j]) ;
		}
		putchar('\n');
	}
}

void shuru( int jz[][2] , int n )
{
	int i , j ;
	for(i = 0 ; i < n ; i ++ )
    {
    	for(j = 0 ; j < n ; j ++ )
    	{
    		scanf("%d",&jz[i][j]);
		}
	}
} 

