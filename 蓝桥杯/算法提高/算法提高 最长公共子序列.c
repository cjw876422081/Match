/*
��������
�������������ַ�����Ѱ���������ִ�֮�������������С�
�����ʽ
�����������У��ֱ����һ���ַ�����������Сд��ĸ��
�����ʽ
��������������еĳ��ȡ�
��������
abcdgh
aedfhb
�������
3
����˵��
���������������Ϊa��d��h��
���ݹ�ģ��Լ��
�����ִ�����1~1000��
*/
#if 1 
#include<stdio.h>
#include<string.h>
int num[1002][1002] = { 0 } ; 
void tongji( char [] , int , char [] , int , int [][1002]);
int main(void)
{
	char s1[1001] ; 
	char s2[1001] ; 
	scanf("%s %s" , s1 , s2 );
	int len1 = strlen( s1 ) , len2 = strlen( s2 ) ;
	tongji( s1 , len1 , s2 , len2 , num ) ;
	printf("%d\n" ,num[len1][len2] ) ; 
	return 0 ; 
}
void tongji( char s1[] , int len1, char s2[] , int len2 , int num[][1002])
{
	int i , j ;
	for( i = 1 ; i <= len1 ; i ++ )
	{
		for( j = 1 ; j <= len2 ; j ++ )
		{
			if( s1[i - 1] == s2[j - 1] )
			{
				num[i][j] = num[i - 1][j - 1] + 1 ;
			}
			else
			{
				num[i][j] = num[i][j - 1] > num[i - 1][j] ? num[i][j - 1] : num[i-1][j] ;
			}
		}
	} 
	
}
#endif
