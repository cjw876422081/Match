/*
��������
����L���ڳ��⣬�½���һ��word�ĵ����벻��ȡʲô���֣�
	����һ�˾��ʣ����������Ŀ�С��½�Microsoft Word�ĵ����𣿡���
	L��ϲ��һ�����ӣ�˵�����ã��ͽ���������ˡ���
������ϸ�۲죬�����½�һ��word�ĵ�ʱ��
	��õ�һ����Ϊ���½� Microsoft Word �ĵ�.doc�����ļ���
	���½�һ��������Ϊ���½� Microsoft Word �ĵ�(2).doc�������½���
	���ǡ��½� Microsoft Word �ĵ�(3).doc���������½���
		��Ų��ϵ����������������½��������ĵ���
		Ȼ��ɾ���ˡ��½� Microsoft Word �ĵ�(2).doc����
		���½����ֻ�õ�һ�����½� Microsoft Word �ĵ�(2).doc����
�����ϸ�˵��Windows��ÿ���½��ĵ�ʱ������ѡȡһ���������ļ���Ų��ظ�����С��������Ϊ���ĵ��ı�š�
��������ģ�����Ϲ��̣�֧���������ֲ���
����New���½�һ��word�ĵ��������½����ĵ��ı��
����Delete id��ɾ��һ�����Ϊid��word�ĵ�������ɾ���Ƿ�ɹ�
������ʼʱһ���ļ���û�У����½� Microsoft Word �ĵ�.doc���ı������1��
�����ʽ
������һ��һ��������n��ʾ����������������n�У�ÿ�б�ʾһ��������������Ϊ��New�������ʾ�½���Ϊ��Delete id�����ʾҪɾ�����Ϊid���ĵ�������idΪһ��������������������˳�����ν��С�
�����ʽ
�������������ÿһ�У�����䷴������������½�����������½����ĵ��ı�ţ�����ɾ������������ɾ���Ƿ�ɹ������ɾ�����ļ����ڣ���ɾ���ɹ��������Successful�������������Failed����
��������
12
New
New
New
Delete 2
New
Delete 4
Delete 3
Delete 1
New
New
New
Delete 4
�������
1
2
3
Successful
2
Failed
Successful
Successful
1
3
4
Successful
���ݹ�ģ��Լ��
���������������������������������1481
����ɾ����ŵ���ֵ������2012
*/ 
#if 1 
#include<stdio.h>
#include<string.h>
#define N (2013)
void Output( int );
int main(void)
{
	int n ; 
	scanf("%d" , & n );
	Output( n ); 
	return 0 ; 
}
void Output( int n )
{
	char str[8] ; 
	int sz[N] = { 0 }; 
	int del , i ; 
	while( n -- > 0  )
	{
		scanf("%s", str); 
		if( strcmp( str , "New") == 0 )
		{
			//printf("1\n");
			for( i = 1 ; i < N ; i ++ )
			{
				if( sz[i] ==  0 )
				{
					sz[i] = i ; 
					printf("%d\n" , i ); 
					break ; 
				}
			}
		}
		else
		{
			
			scanf("%d" , & del );
			for( i = 1 ; i < N ; i  ++ )
			{
				if( i == del )
				{
					if ( sz[i] == 0 )  
                    {  
                        printf("Failed\n");  
                        break;  
                    }  
                    else  
                    {  
                        sz[i]=0;  
                        printf("Successful\n");  
                        break;  
                    }  
				}
			}
		}
	}
}
#endif 
 
