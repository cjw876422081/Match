/* 
��������
������ͬѧ�ǵİ����£���С���Ǳ��Խ��Խ���ˣ������˶���Ը���Լ����Զ����ˣ�ÿ��Ĺ����������ڵ���ǰ���Լ��������˻���Ǯ�Ƿ��б�ࡣ����һ��ʱ��۲���������С�������Լ��˻���Ǯ�����������������ڼ��յ�ʱ������ͭ�嶼û���������Ƶ�����Щ����Ĳ��������ˣ��ɺ޵��������⼸�컹�п��ܡ��侮��ʯ��(���۸�������˰)�������Լ��˻���Ǯ���������ˣ���С�����б�����ĸо�(̫ʹ���ˣ�)����ʱ��С������Ը���������������ٶ��ս����𣬿�ʲô�����ܹ��ս������أ�������(�ϱ���)�����У�̫Σ�գ���������û������ά����״���ܲ��ˣ�§Ǯ̫���ˣ�������ȥ��ץ���Դ�֮�������뵽���ܿ��ٷ����¸��ķ���----���Ʊ����������Ǯ�������������õĻ�������ÿ��������������ģ���ˬ�գ����������뷨����С����ʼ���������Ʊ֮�á��뷨�ǡ��õġ���̫������OR ̫���ˣ��������ַ����Լ�����ѧ����̫���Ϊ��֪�����ֶ�����Щ������У������ھ���ͬѧ��д���ݹ���򣬰�����С�����һ���������ɣ�
�����ʽ
����������6λ����������N��ע�⣺����������N�����ֿ��ظ�
�����ʽ
�������������N������λ����ȫ���У���Щ���а����������ÿ������ռһ�С�
ע�⣺��������в������ظ�������
��������
123
�������
123
132
213
231
312
321
��������
3121
�������
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
��������
4003
�������
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

