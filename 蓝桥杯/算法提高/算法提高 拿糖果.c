///*    
//��������
//���������СB����N���ǣ�������������СBֱ�ӳԵ���
//�������赱ǰ��M���ǣ�СBÿ�ο�����P���ǣ�����P��M��һ�������ڸ�����M������������ʱ������ͻ���СB����P�����Ժ��ٴ��Ƕ�������P���ǡ�
//	Ȼ��СB�Ϳ��Խ������ǡ�
//��������СBϣ��֪���������ö����ǡ�
//�����ʽ
//����һ������N
//�����ʽ
//�����������ö�����
//��������
//15
//�������
//6
//���ݹ�ģ��Լ��
//����N <= 100000
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
