/*编写一个函数，输入一行字符，将此字符串中最长的单词输出。
　　输入仅一行，多个单词，每个单词间用一个空格隔开。
单词仅由小写字母组成。所有单词的长度和不超过100000。
如有多个最长单词，输出最先出现的。
样例输入
I am a student
样例输出
student
*/
#if 1 
#include<stdio.h>
#include<string.h>
void Output( char [] , int ) ;  
int main(void)
{
	char zf[100000+1] ; 
	gets( zf ) ;
	int cd = strlen( zf ) ;
	Output( zf , cd ) ; 
	return 0 ; 
}
void Output( char zf[] , int cd ) 
{
	int i , x = 0 , n ;
	int sz[100000] = { 0 }; 
	for( i = 0 ; i <= cd  ; i ++ )   
    {  
        if( zf[i] == ' ' || zf[i] == '\0' )  
        {      
            n = i - x ;  
            sz[i] = n ;   
            x = i + 1 ;  
        }  
    }  
    int max = 0 , t ;   
    for( i = 0 ; i <= cd ; i ++ )  
    {  
    	//printf("sz[%d] = %d\n" , i , sz[i] ) ; 
        if( sz[i] > max )  
        {  
            max = sz[i];  
            t = i ;  
        }  
    }  
    for( i = t - max ; i <= t ; i ++ )  
    {  
        printf("%c", zf[i] ) ;  
    }  
} 
#endif 
