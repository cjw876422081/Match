/*��дһ������������һ���ַ��������ַ�������ĵ��������
���������һ�У�������ʣ�ÿ�����ʼ���һ���ո������
���ʽ���Сд��ĸ��ɡ����е��ʵĳ��ȺͲ�����100000��
���ж������ʣ�������ȳ��ֵġ�
��������
I am a student
�������
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
