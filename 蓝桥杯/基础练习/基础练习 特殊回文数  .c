/*
��������
����123321��һ���ǳ����������������߶��ʹ��ұ߶���һ���ġ�
��������һ��������n�� �����������������λ����λʮ�������������λ����֮�͵���n ��
�����ʽ
��������һ�У�����һ��������n��
�����ʽ
��������С�����˳���������������������ÿ������ռһ�С�
��������
52
�������
899998
989989
998899
���ݹ�ģ��Լ��
����1<=n<=54��
*/ 
#include <stdio.h> 
int qiu_nxs(int);
int qiu_szh(int);
void shuchu(int);

int main(void)
{	
	int n,i;
	scanf("%d",&n);
	for(i=10000;i<1000000;i++)
	{
		if(qiu_nxs(i)==i)
		{
			if(qiu_szh(i)==n)
			{
				printf("%d\n",i);
			}
		}	
	} 
	return 0;
}

int qiu_szh(int ys)
{
    int szh=0; 
	do
	{				
	   szh+= ys%10;		
	}			
	while((ys/=10)!=0);
	return szh;
}
int qiu_nxs(int ys)
{
	int nxs=0;
	do
	{
		nxs*=10;
		nxs+=ys%10;	 
	}
	while((ys/=10)!=0);
	return nxs;
}
