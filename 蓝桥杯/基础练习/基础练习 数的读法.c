/*
��������
����Tom�������ڸ��о�������һ�Ź��ڻ���Ŀγ̣���һ������������Ϊͷ�ۣ�һ��Ⱦɫ�����г�ǧ���������ԣ����Ǵ�0��ʼ��ţ��������򣬼�ǧ���������ڡ�
��������˵���ڶ�ѧ�������1234567009��λ���ϵļ��ʱ���⿴�������Ǻ���׼ȷ��������ġ�
�������ԣ������е���Ҫһ��ϵͳ��Ȼ��������12 3456 7009ʱ���������Ӧ�����
����ʮ������ǧ�İ���ʮ������ǧ���
�����ú���ƴ����ʾΪ
����shi er yi san qian si bai wu shi liu wan qi qian ling jiu
����������ֻ��Ҫ������Ϳ����ˡ�
������������ǰ����������һ��ϵͳ������һ�����������ִ���������������Ķ�д�Ĺ淶תΪ����ƴ���ִ������ڵ�����������һ���ո���񿪡�
����ע������ϸ��չ淶������˵��10010��������yi wan ling yi shi�������ǡ�yi wan ling shi������100000��������shi wan�������ǡ�yi shi wan������2000��������er qian�������ǡ�liang qian����
�����ʽ
������һ�����ִ�����ֵ��С������2,000,000,000��
�����ʽ
������һ����СдӢ����ĸ�����źͿո���ɵ��ַ�������ʾ������Ӣ�Ķ�����
��������
1234567109
�������
shi er yi san qian si bai wu shi liu wan qi qian ling jiu
*/
#include <stdio.h>

void shuchu( int );  
int main(void)  
{  
	int n;  
    scanf("%d", &n);
	shuchu( n );  
    return 0;  
}
void shuchu( int n)
{	
	char *num[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};  
    char *wei[5] =  {"shi","bai","qian","wan","yi"};  
    char *str[100];  
	int shu , ws = 0 , gs = 0 ,cl[2]={0}; 
	do
	{
		shu = n % 10 ; 
		if( shu > 0 )
		{
			if( ws > 0 )
			{
				if( ws >= 4 && cl[ws / 4 - 1 ] != 1 )
				{
					cl[ws / 4 - 1] = 1 ;
					str[gs ++ ] = wei[ ws / 4 + 2];
				} 
				if( ws % 4 != 0 )
				{
					str[gs++] = wei[ ws % 4 - 1];
				}
			}
			str[gs++] = num[shu];
		}
		else
		{
 			if ( gs > 0 && str[gs- 1] != num[0]) 
			{  
	            str[gs ++] = num[0];  
	        }  
		}
		ws ++ ; 
	} 
	while((n/=10) != 0);
	if (str[gs - 1] == num[1] && gs > 1 && str[gs - 2] == wei[0])
	{
		gs --;
	} 
	if( ws == 1 && gs == 0)
	{
		str[gs++] = num[shu];
	 } 
	int i ; 
    for (i = gs - 1; i >= 0; i--)
	{
		printf("%s ", str[i]);
	}  
}  
