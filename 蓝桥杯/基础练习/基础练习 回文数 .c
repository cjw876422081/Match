/*
��������
����1221��һ���ǳ����������������߶��ʹ��ұ߶���һ���ģ������������������λʮ��������
�����ʽ
��������С�����˳�����������������λʮ��������
*/ 
#include <stdio.h> 
int qiu_nxs(int);
void shuchu(int);

int main(void)
{	
	int i;
	for(i=1000;i<10000;i++)
	{
		if(qiu_nxs(i)==i)
		{
			printf("%d\n",i);
		
		}	
	} 
	return 0;
}

int qiu_nxs(int ys)
{
	int nxs = 0 ;
	do
	{
		nxs*=10;
		nxs+=ys%10;	 
	}
	while((ys/=10)!=0);
	return nxs;
}
