/*
������ϰ �����Ĵ���

��������
�������Ĵ�����һ��������ַ��������������Ҷ��ʹ����������һ���ġ�С������Ϊ��

�Ĵ����������ġ����ڸ���һ����������һ���ǻ��ĵģ�����������ٵĽ�������ʹ�ø�

�����һ�������Ļ��Ĵ���
���������Ķ����ǣ������������ڵ��ַ�
��������mamad
������һ�ν��� ad : mamda
�����ڶ��ν��� md : madma
���������ν��� ma : madam (���ģ�������)
�����ʽ
������һ����һ������N����ʾ���������ַ����ĳ���(N <= 8000)
�����ڶ�����һ���ַ���������ΪN.ֻ����Сд��ĸ
�����ʽ
����������ܣ�������ٵĽ���������
�����������Impossible
��������
5
mamad
5
mamad
�������
3
*/
#include<stdio.h>  
#define N 8000  

void shuchu( int ,char []);
void huan( char [] , int , int );
int main(void)
{  
	int n;  
    char zf[N];
    scanf("%d%s",&n ,zf);  
    shuchu( n , zf );
    return 0;  
      
}  
void huan( char zf[] , int p_k, int p_j)
{
	int i;
	for( i = p_k ; i < p_j ; i ++ )
	{
		char tmp = zf[i];
		zf[i] = zf[i+1] ;
		zf[i+1] = tmp ; 
	}
}
void shuchu( int n ,char zf[])
{
	int i , j = n - 1 ; 
	int dzfgs = 0 , bs = 0;  
    for(i = 0 ; i <  j  ; i ++)
	{  
		int t = j ;
        while( zf[i] != zf[t] )  
		{  
            t--;  
    	}  
        if( i == t )
		{      
            dzfgs ++ ;  
            if( n % 2 == 0 || dzfgs > 1)
			{  
                printf("Impossible\n");  
                return ;  
            }  
            bs += n/2 - i ;  
            continue;   
        }  
        if( zf[i] == zf[t])
		{  
          
            bs += j - t ;  
			huan(zf , t , j );  
            j -- ;  
        }  
    }     
    printf("%d",bs);  
}
