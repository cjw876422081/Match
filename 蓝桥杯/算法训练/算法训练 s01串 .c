	/*��������
����s01����ʼΪ"0"
���������·�ʽ�任
����0��1��1��01
�����ʽ
����1������(0~19)
�����ʽ
����n�α任��s01��
��������
    3                  
�������
    101
���ݹ�ģ��Լ��
    0~19*/
#include<stdio.h>
#include<string.h> 
void shuchu( char * , char * , int  , int ) ;
int main(void) 
{
	int n;
	scanf("%d",&n);
	char s1[1000000] = "1" , s2[1000000] = "01"; 
	shuchu( s1 , s2 , n ,  1 );
	return 0;
} 

void shuchu( char * s1 , char * s2 , int n , int i )
{
	if( n == 0 )
	{
		putchar('0');
		return ;
	}
	if( n == 1 )
	{
		puts(s1);
		return ;
	}
	if( i == n )
	{
		puts( s1 );
		return ;
	}
	shuchu( s2 , strcat( s1 , s2 ) , n ,  i + 1 ); 
}
