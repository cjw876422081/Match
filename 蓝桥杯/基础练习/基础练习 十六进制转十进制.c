/*
��������
�����Ӽ�������һ��������8λ������ʮ���������ַ���������ת��Ϊ����ʮ�������������
����ע��ʮ���������е�10~15�ֱ��ô�д��Ӣ����ĸA��B��C��D��E��F��ʾ��
��������
FFFF
�������
65535
*/ 
#include <stdio.h>
long long  q_zhi(char *);

int main(void)
{

	char zf[10];
	gets(zf);
	printf("%lld\n",q_zhi(zf));
    return 0;
}

long long  q_zhi(char *z)
{
	long long shu=0; 
	char * t=z;
	while(*t !='\0')
	{
		
		if(*t>='0'&&*t<='9')
		{
			shu+=*t-'0';
		}
		if(*t>='A'&&*t<='F')
		{
			shu+=*t-'A'+10; 
		}
		t++; 
		shu*=16;
	}	
	return shu/16;
} 

