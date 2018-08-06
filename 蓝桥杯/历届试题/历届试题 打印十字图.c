/*问题描述
小明为某机构设计了一个十字型的徽标（并非红十字会啊），如下所示：
..$$$$$$$$$$$$$..
..$...........$..
$$$.$$$$$$$$$.$$$
$...$.......$...$
$.$$$.$$$$$.$$$.$
$.$...$...$...$.$
$.$.$$$.$.$$$.$.$
$.$.$...$...$.$.$
$.$.$.$$$$$.$.$.$
$.$.$...$...$.$.$
$.$.$$$.$.$$$.$.$
$.$...$...$...$.$
$.$$$.$$$$$.$$$.$
$...$.......$...$
$$$.$$$$$$$$$.$$$
..$...........$..
..$$$$$$$$$$$$$.. 
对方同时也需要在电脑dos窗口中以字符的形式输出该标志，并能任意控制层数。
输入格式
一个正整数 n (n<30) 表示要求打印图形的层数。 
输出格式
对应包围层数的该标志。 
样例输入1
1 
样例输出1
..$$$$$..
..$...$..
$$$.$.$$$
$...$...$
$.$$$$$.$
$...$...$
$$$.$.$$$
..$...$..
..$$$$$.. 
样例输入2
3 
样例输出2
..$$$$$$$$$$$$$..
..$...........$..
$$$.$$$$$$$$$.$$$
$...$.......$...$
$.$$$.$$$$$.$$$.$
$.$...$...$...$.$
$.$.$$$.$.$$$.$.$
$.$.$...$...$.$.$
$.$.$.$$$$$.$.$.$
$.$.$...$...$.$.$
$.$.$$$.$.$$$.$.$
$.$...$...$...$.$
$.$$$.$$$$$.$$$.$
$...$.......$...$
$$$.$$$$$$$$$.$$$
..$...........$..
..$$$$$$$$$$$$$.. 
提示
请仔细观察样例，尤其要注意句点的数量和输出位置。 
*/
#include <stdio.h>  
int pd_sc(int  , int ,  int  ) ;
void shuchu( int );
int main( void ) 
{      
    int n;      
    scanf("%d", &n);  
	shuchu( n ) ;           
    return 0; 
} 
void shuchu( int n)
{
	int i , j , m = 4 * n + 5 ;      
    for ( i = 1 ; i <= m ; i ++ )     
    {          
        for ( j = 1 ; j <= m ; j ++ )         
        {       
            putchar( pd_sc(i , j , n ) ? '$': '.' );
        }          
        putchar('\n');    
    }         
}
int pd_sc(int i, int j, int n) 
{      
  	//上下对称
    if (i > n * 2 + 3 )
	{
		i = n * 4 + 6 - i;
	}         
    //左右对称
    if (j > n * 2 + 3) 
	{
		j = n * 4 + 6 - j;
	}       
   	if( j  >  i )
	{
		int tmp = j;
		j = i;
		i = tmp;
	}
    //前两行时显示的为 '.'      
    if (i <= 2 && j <= 2)
	{
		return 0;
	}  
    //每一奇数行连续的三个$     
    if (i % 2 == 1 && j >= i - 2) 
	{
		return 1;
	}
    //每一个奇数列中奇异点     
    if (j % 2 == 1 && j != i - 1) 
	{
		return 1; 
	}    
    return 0; 
}
