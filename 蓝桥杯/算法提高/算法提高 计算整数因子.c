/*��������
��������һ����������������������ӡ�
�����ʽ
��������ֻ��һ�У�����һ������n��
�����ʽ
�������һ�У��������ɸ�������Ϊn�����������ӣ����մ�С�����˳�����С�
��������
6
�������
2 3
���ݹ�ģ��Լ��
����1<=n<=10000��
*/
#include<stdio.h>
void shuchu( int );
int main( void )
{
	int n ; 
	scanf("%d" , & n );
	shuchu( n ) ;

	return 0 ; 
}
void shuchu( int n )
{
	int i , j ; 
	for( i = 2; i < n ; i ++) 
	{
        int bj = 0;
        for(j = 2; j * j <= i ; j ++)
		{
            if(i % j == 0)
            {
            	bj = 1 ;
			}
        }
        if(bj == 0 && n % i == 0)
        {
        	printf("%d " , i ) ;
		}
    }
}
