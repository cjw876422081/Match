/*
��������
������ȫ����������һ��(n��)���֤���룬ϣ�����������ڶ����ǽ��дӴ�С����
�������ͬ���ڣ������֤�����С�����������֤����Ϊ18λ��������ɣ���������Ϊ��7����14λ
�����ʽ
������һ��һ������n����ʾ��n�����֤����
�������µ�n�У�ÿ��һ�����֤���롣
�����ʽ
�������������ڴӴ�С���������֤�ţ�ÿ��һ��
��������
5
466272307503271156
215856472207097978
234804580401078365
404475727700034980
710351408803093165
�������
404475727700034980
234804580401078365
215856472207097978
710351408803093165
466272307503271156
���ݹ�ģ��Լ��
����n<=100000
*/
#include<stdio.h>
#include<stdlib.h>
#define N (100000)
typedef
struct
{
	int dzm ;
	int srm ;
	int yzm ;
}Sfz;
void shuru( int , Sfz []);
int cmp( const void* , const void* );
void shuchu( int n , Sfz number[]);
int main( void )
{
	int n ;
	scanf("%d" ,&n );
	Sfz number[N];
	shuru( n  ,number ); 
	qsort( number , n , sizeof( Sfz ) , cmp ); 
	shuchu( n , number );
	return 0 ; 
}
void shuchu( int n , Sfz number[])
{
	int i ;
	for( i = 0 ; i < n ; i ++ )
	{
		printf("%6d%8d%4d\n" , number[i].dzm , number[i].srm , number[i].yzm );
	}
}
int cmp( const void*p , const void*q )
{
	if( (*((Sfz *)p)).srm != (*((Sfz *)q)).srm )
	{
		return (*((Sfz *)q)).srm - (*((Sfz *)p)).srm ; 
	}
	if( (*((Sfz *)p)).dzm != (*((Sfz *)q)).dzm )
	{
		return (*((Sfz *)q)).dzm - (*((Sfz *)p)).dzm ;
	}
	return (*((Sfz *)q)).yzm - (*((Sfz *)p)).yzm ;
}

void shuru( int n , Sfz number[])
{
	int i ;
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%6d%8d%4d" , &number[i].dzm , &number[i].srm , &number[i].yzm );
	}
}
