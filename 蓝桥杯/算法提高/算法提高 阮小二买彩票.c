/* 
问题描述
　　在同学们的帮助下，阮小二是变的越来越懒了，连算账都不愿意自己亲自动手了，每天的工作就是坐在电脑前看自己的银行账户的钱是否有变多。可是一段时间观察下来，阮小二发现自己账户的钱增长好慢啊，碰到节假日的时候连个铜板都没进，更郁闷的是这些天分文不进就算了，可恨的是银行这几天还有可能“落井下石”(代扣个人所得税)，看着自己账户的钱被负增长了，阮小二就有被割肉的感觉(太痛苦了！)，这时阮小二最大的愿望无疑是以最快的速度日进斗金，可什么方法能够日进斗金呢？抢银行(老本行)？不行，太危险，怕有命抢没命花；维持现状？受不了，搂钱太慢了！想来想去，抓破脑袋之后，终于想到了能快速发家致富的法宝----买彩票，不但挣了钱有命花，运气好的话，可以每天中他个几百万的，岂不爽哉！抱着这种想法，阮小二开始了他的买彩票之旅。想法是“好的”（太天真了OR 太蠢了），可是又发现自己的数学功底太差，因为不知道数字都有哪些组合排列？那现在就请同学们写个递归程序，帮助阮小二解决一下这个问题吧！
输入格式
　　不超过6位数的正整数N，注意：构成正整数N的数字可重复
输出格式
　　组成正整数N的所有位数的全排列，这些排列按升序输出，每个排列占一行。
注意：输出数据中不能有重复的排列
样例输入
123
样例输出
123
132
213
231
312
321
样例输入
3121
样例输出
1123
1132
1213
1231
1312
1321
2113
2131
2311
3112
3121
3211
样例输入
4003
样例输出
0034
0043
0304
0340
0403
0430
3004
3040
3400
4003
4030
4300

3677
3767
3776
6377
6737
6773
7367
7376
7637
7673
7736
7763

00345
00354
00435
00453
00534
00543
03045
03054
03405
03450
03504
03540
04035
04053
04305
04350
04503
04530
05034
05043
05304
05340
05403
05430
30045
30054
30405
30450
30504
30540
34005
34050
34500
35004
35040
35400
40035
40053
40305
40350
40503
40530
43005
43050
43500
45003
45030
45300
50034
50043
50304
50340
50403
50430
53004
53040
53400
54003
54030
54300
*/
#include<stdio.h>
void shuchu( int [], int , int  );
void shuru( int  [] , int *  );
void paixu( int [] , int ); 
void huan( int * , int * );
void xr_sc( int [] ,  int  , int , int [] , int * );
void right(int sz[] , int , int );
void left(int sz[] , int , int ); 
int qiu_shu( int [] , int );
int main( void )
{
	int sz[6]={0} , ws1 = 0 ;
	shuru( sz ,  &ws1  ); 
	int jg[720]= { 0 } , ws2 = 0 ;
	xr_sc( sz ,  0  , ws1 , jg , &ws2 );
	paixu( jg ,  ws2 ); 
	shuchu( jg , ws1  ,ws2 );
	return 0 ;	

}
int qiu_shu( int sz[] , int n)
{
	int shu = 0;
	int i;
	for( i = 0 ; i < n ; i ++ )
	{
		shu *= 10 ;
		shu += sz[i] ; 
	}
	return shu ;
}
void right(int sz[] , int strat , int end)
{
	int tmp = sz[end] , i ;
	for( i = end ; i > strat ; i -- )
	{
		sz[i] = sz[i-1] ;
	} 
	sz[strat] = tmp ;
}
void left( int sz[] , int strat , int end)
{
	int tmp = sz[strat] , i ;
	for( i = strat ; i < end ; i ++ )
	{
		sz[i] = sz[ i + 1];
		 
	}
	sz[end] = tmp ;  
}
void xr_sc( int sz[] , int  strat , int end , int jg[] , int * p_ws)
{
	if( strat == end )
	{
		jg[*p_ws] += qiu_shu( sz , end );
		++ * p_ws ;  
		return ;
	}
	int i ;
	for( i = strat ; i < end ; i ++)
	{
		right( sz , strat , i );
		xr_sc( sz ,  strat + 1  , end , jg , p_ws );
		left(sz , strat ,  i  ); 
	} 
}
void shuchu( int sz[] , int ws , int n )
{
	int i , tmp = sz[0];
	char zf[80];
	sprintf( zf , "%%0%dd\n" , ws ); 
	printf( zf , tmp );
	for( i = 1 ; i  < n ; i ++ )
	{
		if( sz[i] != tmp )
		{
			printf( zf , sz[i] );
			tmp = sz[i] ;
		}
	} 
}
void huan( int * a, int * b)
{
	int tmp = * a ; 
	* a = * b ;
	* b = tmp ; 
}
void paixu( int sz[] , int n)
{
	int i , j ; 
	for( i = 0 ; i < n ; i ++ )
	{
		for( j = 0 ; j < n - i -1 ; j ++ )
		{
			if( sz[j] > sz[j+1])
			{
				huan( sz + j , sz + j + 1  );
			}
		}
	}
}
void shuru( int sz[] , int * p_ws )
{
	char c ; 
	while( ( c = getchar()) != '\n')
	{
		sz[*p_ws] = c -'0';
		++ * p_ws ;    
	}
}

