/*
��������
������ĸ�������һЩ������ͼ�Σ����������һ�����ӣ�
ABCDEFG
BABCDEF
CBABCDE
DCBABCD
EDCBABC
����һ��5��7�е�ͼ�Σ����ҳ����ͼ�εĹ��ɣ������һ��n��m�е�ͼ�Ρ�
�����ʽ
����һ�У�������������n��m���ֱ��ʾ��Ҫ�����ͼ�ε�������������
�����ʽ
���n�У�ÿ��m���ַ���Ϊ���ͼ�Ρ�
��������
5 7
�������
ABCDEFG
BABCDEF
CBABCDE
DCBABCD
EDCBABC
���ݹ�ģ��Լ��
1 <= n, m <= 26��
*/

#include<stdio.h>
void shuchu( char [][26] , int , int  );

int main(void )
{
	int n, m ;
	scanf("%d%d", &n , &m );
	char sz[100][26]={0};
	shuchu( sz ,  n , m );
	return 0;
} 
void shuchu( char sz[][26] , int n, int  m)
{
	int i , j ;
	for(i = 0 ; i < n ; i ++)
	{
		char str='A';
		for(j = i ; j < m ; j ++)
		{
        	sz[i][j] = str++;  
		}
		str='A';
       	for(j = i - 1;j >= 0;j --)  
        {  
            sz[i][j] = ++str;
        }
	}
	for(i = 0 ; i < n ; i ++)
	{
		for(j = 0 ; j < m ; j ++)
		{
			printf("%c",sz[i][j]);
		}
		putchar('\n');
	}
}
