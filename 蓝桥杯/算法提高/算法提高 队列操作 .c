/*问题描述
　　?队列操作题。根据输入的操作命令，操作队列（1）入队、（2）出队并输出、（3）计算队中元素个数并输出。
输入格式
　　第一行一个数字N。
　　下面N行，每行第一个数字为操作命令（1）入队、（2）出队并输出、（3）计算队中元素个数并输出。
输出格式
　　若干行每行显示一个2或3命令的输出结果。注意：2.出队命令可能会出现空队出队（下溢），请输出“no”，并退出。
样例输入
7
1 19
1 56
2
3
2
3
2
样例输出
19
1
56
0
no
数据规模和约定
　　1<=N<=50
*/
#include<stdio.h>
void shuchu( int , int []); 
int main( void )
{
	int n , sz[50]; 
	scanf("%d", &n );
	shuchu( n , sz );
	return 0 ; 
}
void shuchu( int  n , int sz[])
{
	int  gs = 0 , i = 0 ;
	while( n -- > 0 )
	{
		int m ; 
		scanf("%d" , &m );   
        if( m == 1 )   
        {    
			scanf("%d" , &sz[gs]);  
			gs ++ ;
        }    
        if( m == 2 )
        {    
            if( gs == 0 ) 
            {    
  				puts("no");
  				return ; 
            }    
            else    
            {    
				printf("%d\n", sz[i]);
				i ++ ; 
            }    
           	gs -- ; 
        }    
        if( m == 3 )    
        {    
			printf("%d\n" , gs );         
        }    
	}
}
