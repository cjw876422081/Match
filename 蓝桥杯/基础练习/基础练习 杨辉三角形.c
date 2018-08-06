/*

问题描述

杨辉三角形又称Pascal三角形，它的第i+1行是(a+b)i的展开式的系数。
　　

它的一个重要性质是：三角形中的每个数字等于它两肩上的数字相加。
　　

下面给出了杨辉三角形的前4行：
　　

   1
　　

  1 1
　　

 1 2 1
　　

1 3 3 1
　　

给出n，输出它的前n行。
输入格式

输入包含一个数n。
输出格式
输出杨辉三角形的前n行。每一行从这一行的第一个数开始依次输出，中间使用一个空格分隔。请不要在前面输出多余的空格。
样例输入
4
样例输出
1
1 1
1 2 1
1 3 3 1
数据规模与约定
1 <= n <= 34。

*/
#include<stdio.h> 
  
 void tx_sjx( int [][34] , int ); 
 void sc_sjx( int (*)[34] , int ); 
  
 int main(void) 
 { 
 	int yh[34][34] = {0}; 
 	int n ; 
 	scanf("%d", & n ); 
 	tx_sjx(yh,n); 
 	sc_sjx(yh,n); 
 	return 0; 
 } 
  
 void sc_sjx( int (*p_h)[34] , int n ) 
 { 
 	int i ; 
 	for( i = 0 ; i < n ; i ++ ) 
 	{ 
 		int j ; 
 		for( j = 0 ; j <= i ; j ++ ) 
 		{ 
 			printf("%d " ,  * ( * (p_h + i ) + j ) );//p_h[i][j] 
 		} 
 		putchar('\n'); 
 	} 
 } 
  
 void tx_sjx( int yh[][34] , int n ) 
 { 
 	int i ; 
 	for( i = 0 ; i < n ; i ++ ) 
 	{ 
 		yh[i][0] = 1; 
 		int j ; 
 		for( j = 1 ; j <= i ; j ++ )  
 		{ 
 			yh[i][j] = yh[i - 1][j] + yh[i - 1][j - 1] ; 
 		} 
 	} 
 }  
