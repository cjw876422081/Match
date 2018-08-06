/*
问题描述
　　Hanks 博士是BT (Bio-Tech，生物技术) 领域的知名专家，他的儿子名叫Hankson。
现 在，刚刚放学回家的Hankson 正在思考一个有趣的问题。 
今天在课堂上，老师讲解了如何求两个正整数c1 和c2 的最大公约数和最小公倍数。
现 在Hankson 认为自己已经熟练地掌握了这些知识，
他开始思考一个“求公约数”和“求公 倍数”之类问题的“逆问题”，
这个问题是这样的：已知正整数a0,a1,b0,b1，
设某未知正整 数x 满足： 1． x 和a0 的最大公约数是a1； 2．
 x 和b0 的最小公倍数是b1。 Hankson 的“逆问题”就是求出满足条件的正整数x。
 但稍加思索之后，他发现这样的 x 并不唯一，甚至可能不存在。
 因此他转而开始考虑如何求解满足条件的x 的个数。请你帮 助他编程求解这个问题。
输入格式
　　输入第一行为一个正整数n，表示有n 组输入数据。
　　接下来的n 行每 行一组输入数据，为四个正整数a0，a1，b0，b1，每两个整数之间用一个空格隔开。
	输入 数据保证a0 能被a1 整除，b1 能被b0 整除。
输出格式
　　输出共n 行。每组输入数据的输出结果占一行，为一个整数。
　　对于每组数据：若不存在这样的 x，请输出0； 若存在这样的 x，请输出满足条件的x 的个数；
样例输入
2
41 1 96 288
95 1 37 1776
样例输出
6
2
样例说明
　　第一组输入数据，x 可以是9、18、36、72、144、288，共有6 个。
　　第二组输入数据，x 可以是48、1776，共有2 个。
数据规模和约定
　　对于 50%的数据，保证有1≤a0，a1，b0，b1≤10000 且n≤100。
　　对于 100%的数据，保证有1≤a0，a1，b0，b1≤2,000,000,000 且n≤2000。
*/




#include<stdio.h>
void jisuan( int , int , int , int , int * );
int gcd( int , int ); 
int main( void )
{
	int n ; 
	scanf("%d" , & n ) ; 
	while( n -- )
	{
		int a0 , a1, b0 , b1 ;
		int sum = 0 ; 
		scanf("%d%d%d%d" ,& a0 , & a1 , & b0 , & b1  );
		if( b1 % a1 == 0 )
		{
			jisuan( a0 , a1 , b0 , b1 , &sum );
		}
		printf("%d\n", sum );
	}
	return 0 ; 
}
int gcd(int a, int b)
{
	if( b == 0 )
	{
		return a ; 
	}
	return gcd( b , a%b );
}
void jisuan( int a0, int a1, int b0, int b1, int * sum )
{
	int i , x ; 
	for( i = 1 ; i * i <= b1 ; i ++ )
	{
		if( b1 % i == 0 )
		{
			if(i % a1 == 0) 
			if(gcd( b1 / b0 , b1 / i ) == 1 && gcd( a0 / a1 , i / a1 ) == 1)
			{
				++ * sum ; 
			}
			int j = b1 / i ;
            if( j % a1 != 0 || i == j )
			{
				continue;	
			} 
			if( gcd( b1 / b0 ,  b1 / j  ) == 1 &&  gcd( a0 / a1 , j / a1 ) == 1)
			{
				++ * sum ; 
			}
		} 
	
	
	}
} 
