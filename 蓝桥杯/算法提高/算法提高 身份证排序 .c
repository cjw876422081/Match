/*
问题描述
　　安全局搜索到了一批(n个)身份证号码，希望按出生日期对它们进行从大到小排序，
如果有相同日期，则按身份证号码大小进行排序。身份证号码为18位的数字组成，出生日期为第7到第14位
输入格式
　　第一行一个整数n，表示有n个身份证号码
　　余下的n行，每行一个身份证号码。
输出格式
　　按出生日期从大到小排序后的身份证号，每行一条
样例输入
5
466272307503271156
215856472207097978
234804580401078365
404475727700034980
710351408803093165
样例输出
404475727700034980
234804580401078365
215856472207097978
710351408803093165
466272307503271156
数据规模和约定
　　n<=100000
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
