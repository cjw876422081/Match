/*��������
������һ�죬������˺ö�ö�������ɫ�����ӣ���������Щ������ôƯ������������һ������Ȼ���͸������ǵ�Ů��~������������һЩ���������˳���Ϊn������������׼����������β��ӵ�ʱ�����������ˡ�
����������ô���ĵ�������Ҳ���ó�����������
����������֪�����������ĳ����������ǫ��������������ô���ܰ���������Ư����
�����������~������Ҫ���������һ��������ɫ�����ӣ�Ȼ��������ȥ��������ӣ�Ȼ�󡭡�������㿴���ǲ���Ư���ܶ���~������һ����˵����m���޸Ĳ��衣
�����������������˹���̫�鷳�ˣ����ǽ������㡣
�����ʽ
������һ�����������ֱ�Ϊn��m��
�����ڶ���n��������ʾ����һ��ʼ����������i������ʾ��i�����ӵ���ɫ��
����������m�У�Ϊ������ʽ֮һ��
����ADD P Q����ʾ����ɫΪP������ǰ�����һ����ɫΪQ�����ӡ�
����DEL P����ʾ����ɫΪP������ȥ������������ڶ˵㴦������Ҫ�����Աߵ���������������������ĳʱ������״̬Ϊ1 4 5 8����ִ��DEL 4����1 5 8��ִ��DEL 1����4 5 8��
�������뱣֤��ÿ�β���֮ǰ����������ɫΪP�����ӣ�������ʱ��������ɫ������ͬ��
�����ʽ
������һ��Ϊһ����len��Ϊ�������в����������ĳ��ȡ�
�����ڶ���len��������ʾ��ʱ������״̬����i������ʾ��i�����ӵ���ɫ��
��������
10 5
1 2 3 4 5 6 7 8 9 10
DEL 5
ADD 7 5
DEL 10
ADD 4 20
ADD 20 12
�������
11
1 2 3 12 20 4 6 5 7 8 9
���ݹ�ģ��Լ��
������ʾ��ɫ�����ֲ�����10^5��������1<=n<=10^4��1<=m<=10^4��
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef 
	struct node
	{
		int value ;
		struct node * next ; 
	}Node ; 
void shuru( Node * , int );
void xiugai( Node * , int );
void Add(Node * , int  , int  );
void Del(Node * , int   );
void shuchu( Node* );
int main( void )
{
	int n , m ; 
	scanf("%d%d", &n , &m );
	Node head = { n , NULL };
	shuru( & head , n );
	xiugai( & head , m );
	printf("%d\n", head.value ) ;
	shuchu( head.next );
	return 0 ; 
}
void shuchu( Node* head )
{
	if( head != NULL )
	{
		printf("%d ",head->value) ; 
		shuchu( head->next) ;
	}
}
void Del(Node * head ,  int  p)
{
	if( head->next->value == p )
	{
		Node *tmp = head->next ; 
		head->next= tmp->next ;
		return ;
	}	
	Del( head->next , p );
}

void Add(Node * head , int  p, int  q)
{
	if( head->next->value == p )
	{
		Node *tmp = malloc( sizeof( Node));
		tmp->value = q ; 
		tmp -> next = head->next ;
		head->next= tmp ;
		return ; 
	}	
	Add( head->next , p , q );
}
void xiugai( Node * head , int n )
{
	char mingling[4];
	int  p  , q ; 
	while( n -- > 0 )
	{
		scanf("%s %d" , mingling , &p );
		if( *mingling == 'A')
		{

			scanf("%d" , &q );

			Add( head , p , q );

			head->value ++ ;
		}
		else
		{
			Del(head ,  p);

			head->value -- ;
		}
	}
	
}
void shuru( Node * head , int n  )
{
	while( n -- > 0)
	{
		Node * tmp = malloc( sizeof( Node));
		scanf("%d" , &tmp->value);
		tmp->next = NULL;
		head->next = tmp ; 
		head = tmp ; 
	}
}
