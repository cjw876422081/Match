/*
��������
���ڳ���Ϊ5λ��һ��01����ÿһλ��������0��1��һ����32�ֿ��ܡ����ǵ�ǰ�����ǣ�
00000
00001
00010
00011
00100
�밴��С�����˳�������32��01����
�����ʽ
������û�����롣
�����ʽ
���32�У�����С�����˳��ÿ��һ������Ϊ5��01����
�������
00000
00001
00010
00011
<���²���ʡ��>

*/ 
#include <stdio.h>
#include<stdlib.h>

void Ouput( int [] , int   ) ; 
int main(void) 
{
	int sz[5] = { 0 } ; 
//	FILE * fp = fopen ("cai.txt" , "w") ; 
	Ouput( sz , 0  ) ; 
	//fclose( fp ) ; 
	return 0;
}
void Ouput( int sz[] , int  i  )
{ 
	if(i == 5 )
	{

		int j ; 
		for( j = 0 ; j < 5 ; j ++ )
		{
			printf("%d" ,sz[j] ) ; 
		//	fprintf( fp , "%d" , sz[j] ) ;
		}
		//fputc('\n', fp); 
		putchar('\n') ; 
		return ; 
	}
	for( sz[i] = 0 ; sz[i] < 2 ; sz[i] ++ )
	{
		Ouput( sz  , i + 1   ) ;

	} 
} 
