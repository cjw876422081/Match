/*  
������ϰ FJ���ַ���  
  
��������  
����FJ��ɳ����д������һЩ�ַ�����  
����A1 = ��A��  
����A2 = ��ABA��  
����A3 = ��ABACABA��  
����A4 = ��ABACABADABACABA��  
������ ��  
���������ҳ����еĹ��ɲ�д���е�����AN��  
�����ʽ  
��������һ������N �� 26��  
�����ʽ  
�����������Ӧ���ַ���AN����һ�����з�����������в��ú��ж���Ŀո���С�  
  
�س�����  
��������  
3  
�������  
ABACABA  
*/  
#include<stdio.h>  
void sc_zf( int ); 
int main(void)  
{  
    int n ;
	scanf("%d",&n);
	sc_zf( n );
    return 0;  
}  
void sc_zf( int n )  
{  
    if(n == 1 )
	{
		putchar('A');  
	}
    else   
    {  
        sc_zf( n - 1 );  
        putchar( n + 'A' - 1 );  
        sc_zf( n - 1 );   
    }  
} 
