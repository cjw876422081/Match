/*
问题描述
　　题目很简单，给出N个数字，不改变它们的相对位置，在中间加入K个乘号和N-K-1个加号，（括号随便加）使最终结果尽量大。因为乘号和加号一共就是N-1个了，所以恰好每两个相邻数字之间都有一个符号。例如：
　　N=5，K=2，5个数字分别为1、2、3、4、5，可以加成：
　　1*2*(3+4+5)=24
　　1*(2+3)*(4+5)=45
　　(1*2+3)*(4+5)=45
　　……
输入格式
　　输入文件共有二行，第一行为两个有空格隔开的整数，表示N和K，其中（2<=N<=15, 0<=K<=N-1）。第二行为 N个用空格隔开的数字（每个数字在0到9之间）。
输出格式
　　输出文件仅一行包含一个整数，表示要求的最大的结果
样例输入
5 2
1 2 3 4 5
样例输出
120
样例说明
　　(1+2+3)*4*5=120
15 14
9 9 9 9 9 9 9 9 9 9 9 9 9 9 9

*/ 
#include<stdio.h>
void shuru( long long  [] , int , long long  [][16]);
long long jisuan( long long  [] , int , int  ,long long  [][16] );
long long  max( long long  , long long  );
long long  min( long long , long long  );
int main( void )
{
	int n , m ; 
	scanf("%d%d" ,& n , &m );
	long long  sz[16]={0} , jg[16][16] = {0 };
	shuru( sz , n , jg );
	printf("%lld\n" , jisuan( sz , n , m , jg ));
	return 0 ; 
} 
long long  min( long long  a , long long  b )
{
	return a < b ? a : b ;   
}
long long  max( long long  a, long long  b)
{
	return a > b ? a : b ;
}
long long  jisuan( long long  sz[] , int n , int m ,long long  jg[][16] )
{
	int i , j , k ; 
    for( i = 1 ; i <= n ; i ++ ) 
	{   
   		for( j = 1 ; j <= m ; j ++ ) 
		{  
        	for(k = 2 ; k <= i ; k ++) 
			{ 
            	jg[i][j] = max( jg[i][j] , jg[k - 1][j - 1] * (sz[i] - sz[k - 1]));  
        	}  
    	}  
	}  
	return jg[n][m] ; 
}
void shuru( long long  sz[] , int n , long long  jg[][16])
{
	int i , shu ;
	for( i = 1 ; i <= n ; i ++ )
	{
		scanf("%d", & shu );
		sz[i] = sz[ i -1 ] + shu ; 
		jg[i][0] = sz[i] ; 
	}
}
