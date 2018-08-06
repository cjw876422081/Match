/*
　　读入10个复数，建立对应链表，然后求所有复数的和。
样例输入
1 2
1 3
4 5
2 3
3 1
2 1
4 2
2 2
3 3
1 1
样例输出
23+23i
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
	FS head = { 0 , 0 , NULL };
	shuru( &head , 10 ); 
	printf("%d+%di\n" , js_sb( head.next , 10 ) , js_xb( head.next , 10 ) );
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

