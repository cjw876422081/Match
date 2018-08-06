/*
问题描述
　　小弱T在闲暇的时候会和室友打扑克，输的人就要负责洗牌。虽然小弱T不怎么会洗牌，但是他却总是输。
　　渐渐地小弱T发现了一个规律：只要自己洗牌，自己就一定会输。所以小弱T认为自己洗牌不够均匀，就独创了一种小弱洗牌法。
　　小弱洗牌法是这样做的：先用传统洗牌法将52张扑克牌（1到K各四张，除去大小王）打乱，放成一堆，然后每次从牌堆顶层拿一张牌。如果这张牌的大小是P（1到K的大小分别为1到13），那么就把这张牌插入到当前手中第P张牌的后面。如果当前手中不足P张牌，那么就把这张牌放在最后。
　　现在给你一对已经被打乱的牌，请你用小弱洗牌法进行洗牌，然后输出最后生成的序列。
　　注意：小弱可能在第一次洗牌时弄丢了某些牌，这时请你输出一个-1来提醒他牌的数目不够。
输入格式
　　测试数据的输入含N个用空格隔开的字符串表示牌堆从顶至底的每张扑克（1到K中的某个）。可能有多行。
输出格式
　　如果N为52，输出用小弱洗牌法洗牌后的序列，每个字符串用空格隔开。
　　否则请输出一个-1.
样例输入
4 6 K Q 5 1 Q 9 7 9 K 3 J 1 2 3 5
2
3 5 7 Q 7 10 8 4 9 7 8 9 4
10 6 2 8 2 10 10 Q 5 K J 1
J 8 3 K 4 1 6 J 6
样例输出
4 1 1 1 3 4 6 6 2 2 2 5 J 3 8 4 4 6 K J 8 J 10 10 K Q 2 5 7 8 10 9 3 7 9 8 7 1 10 5 6 3 Q K Q 5 Q 7 9 9 J K
数据规模和约定
　　保证每个字符串都为1 2 3 4 5 6 7 8 9 10 J Q K中的一个。
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
