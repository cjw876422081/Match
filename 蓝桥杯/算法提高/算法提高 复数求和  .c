/*

从键盘读入n个复数（实部和虚部都为整数）用链表存储，遍历链表求出n个复数的和并输出。
样例输入: 
3 
3 4
5 2
1 3
样例输出:
9+9i

样例输入: 
7
1 2
3 4
2 5
1 8
6 4
7 9
3 7
样例输出:
23+39i
*/
#include<stdio.h>
#include<stdlib.h> 
typedef
struct FS
{
	int sb ;
	int xb ;
	struct FS* next; 	
}FS;
void shuru( FS * , int );
int js_sb( FS * , int );
int js_xb( FS *, int );

int main( void )
{
	int n ; 
	scanf("%d" ,& n ) ; 
	FS head = { 0 , 0 , NULL };
	shuru( &head , n ); 
	printf("%d+%di\n" , js_sb( head.next , n ) , js_xb( head.next , n ) );
	return 0 ; 
}
int js_xb( FS *head , int n)
{
	int sum  = 0 ;
	while( head != NULL)
	{
		sum += head->xb ; 
		head = head->next ; 
	} 
	return sum ; 
}

int js_sb( FS *head , int n)
{
	int sum  = 0 ;
	while( head != NULL )
	{
		sum += head->sb ; 
		head = head->next ; 
	} 
	return sum ; 
}

void shuru( FS * head , int n)
{
	while( n -- )
	{
		int s1 , s2 ; 
		scanf("%d%d", &s1 , &s2 );
		FS * p = (FS*)malloc(sizeof( FS ));
		p->sb = s1 ;
		p->xb = s2 ; 
		p->next = head->next ;
		head->next = p ;
		head = p ;        
	}
}
