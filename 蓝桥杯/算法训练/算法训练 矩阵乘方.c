
/*
��������
��������һ������A,һ���Ǹ�����b��һ��������m����A��b�η���m��������
��������һ��nxn�ľ����m�������õ�������һ��nxn�ľ�����������ÿһ��Ԫ����ԭ�����Ӧλ���ϵ�����m��������
����Ҫ����������⣬���Խ�A����b�Σ�ÿ�ζ���m���࣬�����ַ����ر�������b�ϴ�ʱ�޷�ʹ�á��������һ�ֽϿ���㷨(��A^b��ʾA��b�η�)��
������b=0����A^b%m=I%m������I��ʾ��λ����
������bΪż������A^b%m=(A^(b/2)%m)^2%m�����Ȱ�A��b/2�η���m���࣬Ȼ����ƽ�����m���ࡣ
������bΪ��������A^b%m=(A^(b-1)%m)*a%m��������A��b-1�η���m���࣬Ȼ���ٳ�A���m���ࡣ
�������ַ����ٶȽϿ죬��ʹ�����ַ�������A^b%m������A��һ��2x2�ľ���m������10000��
�����ʽ
���������һ�а�����������b, m���ڶ��к͵�����ÿ������������Ϊ����A��
�����ʽ
����������У�ÿ��������������ʾA^b % m��ֵ��
��������
2 2
1 1
0 1
�������
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

