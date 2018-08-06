///*    
//问题描述
//　　妈妈给小B买了N块糖！但是她不允许小B直接吃掉。
//　　假设当前有M块糖，小B每次可以拿P块糖，其中P是M的一个不大于根号下M的质因数。这时，妈妈就会在小B拿了P块糖以后再从糖堆里拿走P块糖。
//	然后小B就可以接着拿糖。
//　　现在小B希望知道最多可以拿多少糖。
//输入格式
//　　一个整数N
//输出格式
//　　最多可以拿多少糖
//样例输入
//15
//样例输出
//6
//数据规模和约定
//　　N <= 100000
//*/
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h> 
//void create( int []  , int * ) ; 
//void Output( int [], int [] , int , int ) ; 
//int max( int , int ); 
//int main(void) 
//{
//	int n , cnt ;
//	scanf("%d" , & n ) ; 
//	static int sz[100005] = { 0 } ;
//	static int bg[40000] = { 0 } ;
//	create( bg  ,& cnt ) ; 
//	printf("%d" , cnt) ;
//	Output( bg , sz  , n  , cnt ) ;  	 
//	return 0;
//}
//int max( int a, int b)
//{
//	return a > b ? a : b ; 
//}
//void Output( int bg[], int sz[] , int n, int cnt) 
//{
//	int i , j ;  
//    for( i = 1; i <= n; i ++) 
//	{  
//        for( j = 0; j < cnt ; j ++)
//		{  
//            if( bg[j] > sqrt(i)) 
//			{
//				break; 
//			} 
//            if(i % bg[j] == 0 )
//			{
//				 sz[i] = max(sz[i], sz[i - 2 * bg[j]] + bg[j]);
//			}  
//        }  
//    }  
//    printf("%d\n" ,sz[n] ) ; 
//}
//
//void create( int bg[]  , int * cnt) 
//{
//	int bj[40000] = { 0 }  , i , j  , len = sqrt( 100005 ) ;
//	for( i = 2 ; i <= len ; i ++ )
//	{
//		if( bj[i] == 0  )
//		{
//			bg[*cnt] =  i ;
//			++ * cnt ;  
//		}
//		for( j = i * i ; j <= len ; j += i )
//		{
//			bj[j] = 1 ; 
//		}
//	 } 
//}
