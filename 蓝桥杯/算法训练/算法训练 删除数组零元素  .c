/*.
从键盘读入n个整数放入数组中，编写函数CompactIntegers，删除数组中所有值为0的元素，
其后元素向数组首端移动。
注意，CompactIntegers函数需要接受数组及其元素个数作为参数，
函数返回值应为删除操作执行后数组的新元素个数。
输出删除后数组中元素的个数并依次输出数组元素。
样例输入: （输入格式说明：5为输入数据的个数，3 4 0 0 2 是以空格隔开的5个整数）
5 
3 4 0 0 2
样例输出:（输出格式说明：3为非零数据的个数，3 4 2 是以空格隔开的3个非零整数）
3
3 4 2
样例输入: 
7
0 0 7 0 0 9 0
样例输出:
2
7 9
样例输入: 
3
0 0 0
样例输出:
0
*/
#include<stdio.h>
void shuru( int [] , int );
int q_gs( int [] , int );
void huan( int * , int *);
void shuchu( int  , int [] );
void ydyw( int * , int * , int );
void nixu(int [] , int  );
int main( void )
{
	int n ;
	scanf("%d",&n);
	int sz[n];
	shuru( sz , n ); 
	int flgs = q_gs( sz , n );
	shuchu( flgs , sz );
	return 0 ;
}
void nixu(int sz[] , int  n)
{
	int tou , wei= n - 1 ; 
	for( tou = 0 ; tou < wei ; tou ++ )
	{
		huan( &sz[tou] , &sz[wei]);
		wei -- ;
	}
	
}
void ydyw( int * p_t , int * p_w, int  n )
{
	nixu( p_t , n );
	nixu( p_t + n , (p_w - p_t) - n );
	nixu( p_t , p_w - p_t ); 
}
void shuchu( int  p_flgs, int sz[] )
{
	printf("%d\n",p_flgs);
	while( p_flgs -- > 0 )
	{
		printf("%d " , * sz ++ );
	}
}
void huan( int *a , int * b)
{
	int tmp = * a;
	 *a = * b ;
	 * b = tmp ;  
}
int q_gs( int sz[] , int n)
{
	int tou = n , xb = n ;
	while( xb -- > 0 )
	{
		if( sz[xb] == 0 )
		{
			ydyw( &sz[xb] , &sz[tou] , 1 );
			tou -- ;
		}
	}
	 return tou ;
}
void shuru( int sz[] , int n)
{
	while( n -- > 0 )
	{
		scanf("%d", sz ++ );
	} 
}
