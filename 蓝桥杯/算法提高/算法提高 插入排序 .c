/*
��������
��������
�������򣬹���˼�壬�ǽ����ɸ�Ԫ�ذ����С��ϵ�ų�һ��˳����ʽ���������£���n��Ԫ��a[1]��a[2]������a[n]����С����������ǽ������ų�һ����˳��a[i[1]]<a[i[2]]<��<a[i[n]]
����i[k]Ϊ�����˳��
�����������򣬹���˼�壬��ͨ������������������ֱ���ͷ�����Դ�ڴ���ʱ�����Ƶķ�����ÿ������һ���ƣ��㶼�Ὣ����뵽��������������˳��Ӧ�ڵ��Ǹ�λ�á���������ÿһ��������������ƹ��̡������������������飺{3, 1, 5, 4, 2}
������һ��������3 �õ�������{3}
�����ڶ���������1 �õ�������{1 3}
����������������5 �õ�������{1 3 5}
�������Ĳ�������4 �õ�������{1 3 4 5}
�������岽������2 �õ�������{1 2 3 4 5}
����Ϊ�˿������������ɲ�����̣������Ե��岽Ϊ����
������ʼʱ��1 3 4 5 2
������2������ʱ����tmp
�������±�jָ��2֮ǰ��Ԫ��5��Ȼ�����tmp��a[j]�Ĵ�С��ϵ������Ԫ���Ƿ�Ӧ�ú��ơ����a[j]>tmp��
	��a[j]���Ƶ�a[j+1]�����б��1 3 4 5 5��
�������±�jǰ��
�����ж�a[j]>tmp������a[j]��a[j+1]���õ�1 3 4 4 5
�������±�jǰ��
�����ж�a[j]>tmp������a[j]��a[j+1]���õ�1 3 3 4 5
������Ϊa[j]<=tmp�����Խ�tmp�Ż�a[j+1]���õ� 1 2 3 4 5
�������ڣ�����n�����������������㷨��������������ȫ���̡�
�����ʽ
������һ��һ��������n����ʾԪ�ظ���
�����ڶ���Ϊn���������Կո����
�����ʽ
������n��Ԫ�أ����������ַ�Ϊn�����֣�ÿ�����ֿ�ͷ��Ϊ��Insert element[i]��iΪ�ڼ���Ԫ�ء�
Ȼ�����ÿһ�����֣�����ò��ָ�Ԫ���ڲ�����������е�ÿһ�������������У�
��ʼʱ��������Init:��ͷ��Ȼ��ÿһ����������Ԫ�غ��Ԫ��������Move back:��ͷ��
���õ������ս��������Final:��ͷ������Ԫ�ؼ���һ���ո������
ʾ���뿴���������ÿһ�����ֵ�Insert element[i]֮���ÿһ���������֮ǰҪ�������񣬼���������ո�
��������
5
3 1 5 4 2
�������
Insert element[1]:
Init:3
Final:3
Insert element[2]:
Init:3 1
Move back:3 3
Final:1 3
Insert element[3]:
Init:1 3 5
Final:1 3 5
Insert element[4]:
Init:1 3 5 4
Move back:1 3 5 5
Final:1 3 4 5
Insert element[5]:
Init:1 3 4 5 2
Move back:1 3 4 5 5
Move back:1 3 4 4 5
Move back:1 3 3 4 5
Final:1 2 3 4 5
���ݹ�ģ��Լ��
����n<=100
��������Ԫ����int��Χ��
10
9 3 3 9 4 3 5 3 5 1
Insert element[1]:
  Init:9
  Final:9
Insert element[2]:
  Init:9 3
  Move back:9 9
  Final:3 9
Insert element[3]:
  Init:3 9 3
  Move back:3 9 9
  Final:3 3 9
Insert element[4]:
  Init:3 3 9 9
  Final:3 3 9 9
Insert element[5]:
  Init:3 3 9 9 4
  Move back:3 3 9 9 9
  Move back:3 3 9 9 9
  Final:3 3 4 9 9
Insert element[6]:
  Init:3 3 4 9 9 3
  Move back:3 3 4 9 9 9
  Move back:3 3 4 9 9 9
  Move back:3 3 4 4 9 9
  Final:3 3 3 4 9 9
Insert element[7]:
  Init:3 3 3 4 9 9 5
  Move back:3 3 3 4 9 9 9
  Move back:3 3 3 4 9 9 9
  Final:3 3 3 4 5 9 9
Insert element[8]:
  Init:3 3 3 4 5 9 9 3
  Move back:3 3 3 4 5 9 9 9
  Move back:3 3 3 4 5 9 9 9
  Move back:3 3 3 4 5 5 9 9
  Move back:3 3 3 4 4 5 9 9
  Final:3 3 3 3 4 5 9 9
Insert element[9]:
  Init:3 3 3 3 4 5 9 9 5
  Move back:3 3 3 3 4 5 9 9 9
  Move back:3 3 3 3 4 5 9 9 9
  Final:3 3 3 3 4 5 5 9 9
Insert element[10]:
  Init:3 3 3 3 4 5 5 9 9 1
  Move back:3 3 3 3 4 5 5 9 9 9
  Move back:3 3 3 3 4 5 5 9 9 9
  Move back:3 3 3 3 4 5 5 5 9 9
  Move back:3 3 3 3 4 5 5 5 9 9
  Move back:3 3 3 3 4 4 5 5 9 9
  Move back:3 3 3 3 3 4 5 5 9 9
  Move back:3 3 3 3 3 4 5 5 9 9
  Move back:3 3 3 3 3 4 5 5 9 9
  Move back:3 3 3 3 3 4 5 5 9 9
  Final:1 3 3 3 3 4 5 5 9 9

*/ 
#include<stdio.h>
void shuchu(int [] , int  );
void sc_sz( int [] , int );
void sc_move( int [] , int );
void shuru( int [] , int );
int main( void )
{
	int n  , sz[100];
	scanf("%d" ,&n );
	shuru( sz , n );
	int i ;  
	for(  i = 0 ;  i < n ; i ++)
	{
		shuchu( sz , i+1 );
	}
	return 0 ; 
}
void shuru( int sz[] , int n)
{
	int i ;
	for( i = 0 ;i < n  ; i ++ )
	{
		scanf("%d" ,&sz[i]);
	} 
}
void sc_move( int sz[] , int gs)
{
	int tmp = sz[gs - 1] , j = gs - 2;
	while( tmp < sz[j])
	{
		sz[j + 1 ] = sz [ j ];
		printf("  Move back:");
		sc_sz( sz , gs); 
		j -- ; 
	}
	sz[j+1] = tmp ;
}
void sc_sz( int sz[] , int gs)
{
	int i ; 
	for( i = 0 ; i < gs ; i ++)
	{
		printf("%d " ,sz[i]);
	}
	putchar('\n');
}
void shuchu(int sz[] , int  gs)
{
	printf("Insert element[%d]:\n" , gs );
	printf("  Init:");
	sc_sz( sz , gs );
	sc_move( sz , gs );
	printf("  Final:");
	sc_sz( sz , gs ); 
} 


