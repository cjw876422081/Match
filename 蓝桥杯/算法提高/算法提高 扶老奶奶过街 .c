/*　　一共有5个红领巾，编号分别为A、B、C、D、E，
	老奶奶被他们其中一个扶过了马路。
　　五个红领巾各自说话：
　　A ：我和E都没有扶老奶奶
　　B ：老奶奶是被C和E其中一个扶过大街的
　　C ：老奶奶是被我和D其中一个扶过大街的
　　D ：B和C都没有扶老奶奶过街
　　E ：我没有扶老奶奶
　　已知五个红领巾中有且只有２个人说的是真话，请问是谁扶这老奶奶过了街？
　　若有多个答案，在一行中输出，编号之间用空格隔开。
　　例如
　　A B C D E（这显然不是正确答案）?
*/
#include<stdio.h>
void shuchu( int [] , int );
int main( void )
{
	int sz[5]={0} , sum ;
	shuchu( sz , sum );
	return 0 ; 
}
void shuchu( int sz[] , int sum)
{
	int i ; 
	for( i = 0 ;  i < 5 ; i ++ )
	{
		sz[i] = 1 ;
		sum = 0 ;  
        if( sz[0] == 0 && sz[4] == 0 )
        {
        	sum ++ ;
		}
        if( sz[2] == 1 || sz[4] == 1 )
        {
        	sum ++ ;  
		}
        if( sz[2] == 1 || sz[3] == 1) 
		{
			sum ++ ;  
		} 
        if( sz[1] == 0 && sz[2] == 0) 
		{
        	sum ++ ;  
		} 
        if( sz[4] == 0 )
        {
        	sum ++ ; 
		}
        if( sum == 2 )
        {
        	printf("%c ",'A' + i ); 
		}
		sz[i] = 0 ;
	}
}

