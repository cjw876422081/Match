/*
问题描述
　　扑克牌排序：构造扑克牌数组，对扑克牌进行排序。
	排序原则如下：数字从小到大是2-10、J、Q、K和A，
	花色从小到大是方块（diamond）、梅花（club）、红桃（heart）、黑桃（spade）。
	两张牌比较时先看数字，数字相同时看花色。要求对输入的扑克牌进行从小到大排序。
　　输入五张牌（表示黑桃2、红桃3、黑桃3、方块A和梅花J）： 2 s 3 h 3 s A d J c
　　输出结果应为：2 s 3 h 3 s J c A d
数组长度固定为5。
样例输出
与上面的样例输入对应的输出。
例：
数据规模和约定
　　输入数据中每一个数的范围。
*/
#include<stdio.h>
typedef
	struct
	{
		char sz;
		char hs;
	}PM;
void shuru( PM [] , int  );
void shuchu( PM [] , int  );
void paixu( PM [] , int  );
int q_shu( char );
int q_hs( char );
void huan( PM * , PM *);
int main( void )
{
	PM pkp[5];
	shuru( pkp , 5);
	paixu( pkp , 5 );
	shuchu( pkp, 5 );
	return 0 ;
}
void huan( PM * a , PM * b)
{
	PM tmp = * a ; 
	* a =  * b ; 
	* b = tmp ; 
}
int q_hs( char  c )
{
	char hs[5]={'d','c','h','s'};  
	int i ;
    for (i = 0 ;i < 4;i ++)  
    {  
        if ( hs[i] == c)  
        {  
            return i ;  
        }  
    }  
}
int q_shu( char  c )
{
	char num[14]={'2','3','4','5','6','7','8','9','10','J','Q','K','A'};  
	int i ;
    for (i = 0 ;i < 13 ;i ++)  
    {  
        if (num[i] == c)  
        {  
            return i ;  
        }  
    }  
}
void paixu( PM pkp[] , int n)
{
	int i , j ; 
	for( i = 0 ; i < n ; i ++ )
	{
		for( j = 0 ; j < n - i - 1 ; j ++ )
		{
			int s1 = q_shu(pkp[j].sz ) ; 
			int s2 = q_shu(pkp[j+1].sz ) ;
			if( s1 > s2 )
			{
				huan( &pkp[j] , &pkp[j+1] );
			}
			if( s1 == s2 )
			{
				if( q_hs(pkp[j].hs) > q_hs( pkp[j+1].hs) )
				{
					huan( &pkp[j] , &pkp[j+1] );
				}
			}
		}
	}
}
void shuchu( PM pkp[] , int n)
{
	int i ; 
	for(i = 0 ; i < n ; i ++)
	{
		printf("%c%c ", pkp[i].sz ,pkp[i].hs);
	}
}
void shuru( PM pkp[] , int n)
{
	int i ; 
	for(i = 0 ; i < n ; i ++)
	{
		scanf("%c%c", &pkp[i].sz ,&pkp[i].hs);
	}
}
