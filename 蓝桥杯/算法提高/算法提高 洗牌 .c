/*
��������
����С��T����Ͼ��ʱ�������Ѵ��˿ˣ�����˾�Ҫ����ϴ�ơ���ȻС��T����ô��ϴ�ƣ�������ȴ�����䡣
����������С��T������һ�����ɣ�ֻҪ�Լ�ϴ�ƣ��Լ���һ�����䡣����С��T��Ϊ�Լ�ϴ�Ʋ������ȣ��Ͷ�����һ��С��ϴ�Ʒ���
����С��ϴ�Ʒ����������ģ����ô�ͳϴ�Ʒ���52���˿��ƣ�1��K�����ţ���ȥ��С�������ң��ų�һ�ѣ�Ȼ��ÿ�δ��ƶѶ�����һ���ơ���������ƵĴ�С��P��1��K�Ĵ�С�ֱ�Ϊ1��13������ô�Ͱ������Ʋ��뵽��ǰ���е�P���Ƶĺ��档�����ǰ���в���P���ƣ���ô�Ͱ������Ʒ������
�������ڸ���һ���Ѿ������ҵ��ƣ�������С��ϴ�Ʒ�����ϴ�ƣ�Ȼ�����������ɵ����С�
����ע�⣺С�������ڵ�һ��ϴ��ʱŪ����ĳЩ�ƣ���ʱ�������һ��-1���������Ƶ���Ŀ������
�����ʽ
�����������ݵ����뺬N���ÿո�������ַ�����ʾ�ƶѴӶ����׵�ÿ���˿ˣ�1��K�е�ĳ�����������ж��С�
�����ʽ
�������NΪ52�������С��ϴ�Ʒ�ϴ�ƺ�����У�ÿ���ַ����ÿո������
�������������һ��-1.
��������
4 6 K Q 5 1 Q 9 7 9 K 3 J 1 2 3 5
2
3 5 7 Q 7 10 8 4 9 7 8 9 4
10 6 2 8 2 10 10 Q 5 K J 1
J 8 3 K 4 1 6 J 6
�������
4 1 1 1 3 4 6 6 2 2 2 5 J 3 8 4 4 6 K J 8 J 10 10 K Q 2 5 7 8 10 9 3 7 9 8 7 1 10 5 6 3 Q K Q 5 Q 7 9 9 J K
���ݹ�ģ��Լ��
������֤ÿ���ַ�����Ϊ1 2 3 4 5 6 7 8 9 10 J Q K�е�һ����
*/
#if 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef
	struct
	{
		int sz ;
		char m[3] ;
	}
Pai_t ; 
typedef
	struct node
	{
		Pai_t pai ;
		struct node * next ;
		 
	}
Jiedian_t ;

int dupai( Jiedian_t * * ) ; 
void Input( Pai_t * , char []);
int q_zhi( char [] ) ; 
void change( Jiedian_t * * , int ,Jiedian_t * ) ; 
void Output( Jiedian_t * ) ; 
 
int main(void)
{
	Jiedian_t * head = NULL ;
	dupai( &head ) < 52 ? puts("-1") : Output( head ) ;  
	return 0 ; 
}
void Output( Jiedian_t *p ) 
{
	if(  p != NULL )
	{
		printf("%s " , p->pai.m) ;
		Output( p->next ); 
	}
	else
	{
		putchar('\n') ; 
	}
}
int q_zhi( char * zf )
{
	if( * zf == 'J' || * zf == 'j')
	{
		return 11 ; 
	}
	if( * zf == 'Q' || * zf == 'q')
	{
		return 12 ; 
	}
	if( * zf == 'K' || * zf == 'k')
	{
		return 13 ; 
	}
	if( strcmp( zf , "10") == 0 )
	{
		return 10 ; 
	}
	return *zf - '0' ; 
}
void change( Jiedian_t * * p_head , int djg , Jiedian_t * p_jd )
{
	if( * p_head == NULL || djg == 0 )
	{
		p_jd -> next = * p_head ;
		* p_head = p_jd ;
	}
	else
	{
		change( & ( * p_head ) -> next , djg - 1 , p_jd ) ; 
	}
}
void Input( Pai_t * p_pai , char dx[])
{
	strcpy( p_pai -> m , dx ) ;
	p_pai -> sz = q_zhi( p_pai -> m ) ; 
}

int dupai( Jiedian_t * * p_head ) 
{
	int zs = 0 ;
	char tmp[8] ; 
	while( scanf("%s",tmp) != EOF )
	{
		Jiedian_t * p  = malloc( sizeof( Jiedian_t )) ;
		Input( & p -> pai , tmp ) ;  
		change( p_head , p -> pai.sz , p ) ; 
		zs ++ ; 
	}
	return zs ; 
}
#endif
