/*
问题描述
　　C国由n个小岛组成，为了方便小岛之间联络，C国在小岛间建立了m座大桥，每座大桥连接两座小岛。
	两个小岛间可能存在多座桥连接。然而，由于海水冲刷，有一些大桥面临着不能使用的危险。
　　如果两个小岛间的所有大桥都不能使用，则这两座小岛就不能直接到达了。然而，
	只要这两座小岛的居民能通过其他的桥或者其他的小岛互相到达，他们就会安然无事
	但是，如果前一天两个小岛之间还有方法可以到达，后一天却不能到达了，居民们就会一起抗议。
　　现在C国的国王已经知道了每座桥能使用的天数，超过这个天数就不能使用了。现在他想知道居民们会有多少天进行抗议。
输入格式
　　输入的第一行包含两个整数n, m，分别表示小岛的个数和桥的数量。
　　接下来m行，每行三个整数a, b, t，分别表示该座桥连接a号和b号两个小岛，能使用t天。小岛的编号从1开始递增。
输出格式
　　输出一个整数，表示居民们会抗议的天数。
样例输入
4 4
1 2 2
1 3 2
2 3 1
3 4 3
样例输出
2
样例说明
　　第一天后2和3之间的桥不能使用，不影响。
　　第二天后1和2之间，以及1和3之间的桥不能使用，居民们会抗议。
　　第三天后3和4之间的桥不能使用，居民们会抗议。
数据规模和约定
　　对于30%的数据，1<=n<=20，1<=m<=100；
　　对于50%的数据，1<=n<=500，1<=m<=10000；
　　对于100%的数据，1<=n<=10000，1<=m<=100000，1<=a, b<=n， 1<=t<=100000。
*/
#if 1
#include<stdio.h>
typedef
	struct
	{
		int a ;
		int b ;
		int day ;  
	}Qiao_t ;
	
void Input( Qiao_t [] , int ) ; 
void qsort( Qiao_t [] , int , int ) ; 
void cs_way( int [] , int  ); 
int jisuan( int [] , Qiao_t [] , int ); 
int pd( int ,  int  , int []) ; 
int pbj( int ,  int [] ) ; 

int main(void)
{
	int n , m ; 
	scanf("%d%d" , & n , & m ) ;
	Qiao_t sz[100001];
	Input( sz , m ) ; 
	qsort( sz , 0 ,  m - 1 ) ;
	int way[10001] = { 0 } ; 
	cs_way( way , n ) ; 
	printf("%d\n" , jisuan( way , sz  , m )) ; 
	 /*
	int i ; 
	for( i = 0 ; i < m  ; i ++ )
	{
		printf("%d %d %d\n" ,sz[i].a , sz[i].b , sz[i].day  ); 
	}*/
	return 0 ;
}

int pbj( int n ,  int bj[] )
{
	if( bj[n] == n )
	{
		return n ; 
	}
	return  bj[n] = pbj( bj[n] , bj ) ; 
}
int pd( int a,  int b , int way[])
{
	a = pbj( a , way) ; 
	b = pbj( b , way) ; 
	if( a !=  b )
	{
		way[a] = b ; 
		return 1 ;
	}
	return 0 ; 
}
int jisuan( int way[] , Qiao_t sz[] , int  m )
{
	int i , sum = 0 , p = -1 ; 
	for( i = 0 ; i < m ; i ++ )
	{
		if( pd( sz[i].a , sz[i].b  , way ) && p != sz[i].day )
		{
			sum ++ ; 
			p= sz[i].day ; 
		}  
	}
	return sum ; 
}
void cs_way( int way[] , int n )
{
	int i  ;
	for( i = 0 ; i <  n ; i ++ )
	{
		way[i] = i ; 
	} 
}
void qsort( Qiao_t sz[] , int left , int  right )
{
	if( left >= right )
	{
		return ; 
	}
	int i = left , j = right ; 
	Qiao_t key = sz[left] ;
	while( i < j )
	{
		while( i < j && key.day >= sz[j].day )
		{
			j -- ; 
		}
		sz[i] = sz[j] ; 
		while(  i < j && key.day <= sz[i].day )
		{
			i ++ ; 
		}
		sz[j] = sz[i] ; 
	 } 
	 sz[i] = key ; 
	 qsort( sz , left , i - 1 ) ; 
	 qsort( sz  , i + 1 , right ) ; 
	 
}

void Input( Qiao_t sz[] , int  m )
{
	int i ; 
	for( i = 0 ; i < m  ; i ++ )
	{
		scanf("%d%d%d" , &sz[i].a , & sz[i].b , & sz[i].day ) ; 
	}
}
#endif
