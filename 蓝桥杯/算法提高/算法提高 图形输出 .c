/*
������дһ��������Ļ������������ݣ�
����X | X | X
����---+---+---
����| |
����---+---+---
����O | O | O
����ע�⣺������ͬѧ���ϸ���ͼ�εĸ�ʽ��������룬����X��OΪ��д������ϵͳ����Ϊ����
*/
#include <stdio.h>
void shuchu(char *[]  , int );
int main(void) 
{
	char *zf[]={"X | X | X",
				 "---+---+---",
				 "| |",
				 "---+---+---",
				 "O | O | O",};
	shuchu( zf , sizeof zf / sizeof * zf) ;
    return 0;
}
void shuchu(char *zf[]  , int n)
{
	if( n > 0)
	{
		puts(*zf);
		shuchu(zf+1 , n-1);
	}
}
