/*

��������
���������������ɴ�д��ĸ��Сд��ĸ��ɵ��ַ���(���Ƚ���1��10֮��)������֮��Ĺ�ϵ������4�����֮һ��
����1�������ַ������Ȳ��ȡ����� Beijing �� Hebei
����2�������ַ�������������ȣ�������Ӧλ���ϵ��ַ���ȫһ��(���ִ�Сд)������ Beijing �� Beijing
����3�������ַ���������ȣ���Ӧλ���ϵ��ַ����ڲ����ִ�Сд��ǰ���²��ܴﵽ��ȫһ�£�Ҳ����˵���������������2�������� beijing �� BEIjing
����4�������ַ���������ȣ����Ǽ�ʹ�ǲ����ִ�СдҲ����ʹ�������ַ���һ�¡����� Beijing �� Nanjing
��������ж�����������ַ���֮��Ĺ�ϵ�����������е���һ�࣬������������ı�š�
�����ʽ
�����������У�ÿ�ж���һ���ַ���
�����ʽ
��������һ�����֣������������ַ����Ĺ�ϵ���
��������
BEIjing
beiJing 

�������
3

*/ 
#include <stdio.h>
void shuru(char*,char*);
int q_gx(char*,char*);
int q_cd(char*);
int  be_wqyz(char *, char * );
int  be_dx(char *, char * );
char daxie(char);

int main(void)
{
	char s1[80];
	char s2[80];
	shuru(s1,s2);
	printf("%d\n",q_gx(s1,s2));
    return 0;
}
char daxie(char c)
{
	if('a'<= c && c <='z')
	{
		return c+'A'-'a';
	}
	return c;
}

int  be_dx(char * s1, char * s2 )
{
	while(daxie(*s1)==daxie(*s2))
	{
		if(*s1=='\0')
		{
			return 1;
		}
		s1++;
		s2++;
	}
	
}




int  be_wqyz(char * s1,char * s2 )
{
	while(*s1== *s2)
	{
		if(*s1=='\0' )
		{
			return 1;
		} 
		s1++;
		s2++;
	} 
	return 0; 
}



int q_cd(char * s)
{
	char* w = s;
	while(*w!='\0')
	{
		w++;
		
	} 
	return w-s;
}

int q_gx(char * s1,char * s2)
{
	if(q_cd(s1)!=q_cd(s2))
	{
		return 1;	
	}
	if(be_wqyz(s1, s2 )==1)
	{
		return 2;
	}
	
	if(be_dx(s1 , s2)==1)
	{
		return 3;
	}
	return 4;
}



void shuru(char * s1,char * s2)
{
	gets(s1);
	gets(s2);
	
}
