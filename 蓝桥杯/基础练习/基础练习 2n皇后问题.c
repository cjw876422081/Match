/*
������ϰ 2n�ʺ�����
��������
��������һ��n*n�����̣���������һЩλ�ò��ܷŻʺ�����Ҫ�������з���n���ڻʺ�
��n���׻ʺ�ʹ����������ڻʺ󶼲���ͬһ�С�ͬһ�л�ͬһ���Խ����ϣ��������
���׻ʺ󶼲���ͬһ�С�ͬһ�л�ͬһ���Խ����ϡ����ܹ��ж����ַŷ���nС�ڵ���8��
�����ʽ
��������ĵ�һ��Ϊһ������n����ʾ���̵Ĵ�С��
����������n�У�ÿ��n��0��1�����������һ������Ϊ1����ʾ��Ӧ��λ�ÿ��ԷŻʺ�
���һ������Ϊ0����ʾ��Ӧ��λ�ò����ԷŻʺ�
�����ʽ
�������һ����������ʾ�ܹ��ж����ַŷ���
��������
4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
�������
2
��������
4
1 0 1 1
1 1 1 1
1 1 1 1
1 1 1 1
�������
0
*/
#include<stdio.h>
int tongji(int  , int  , int [][8] , int ,int *);
int check(int , int  ,int ,int [][8] , int );
void shuru( int , int [][8]);

int main(void)
{
    int n ,sz[8][8];
    scanf("%d",&n);
    shuru( n , sz );
    int sum=0;
    printf("%d",tongji(n , 0 , sz , 2  ,&sum));
    return 0;
}
int tongji(int n , int x , int sz[][8] , int s ,int *sum)
{
    
    if( x == n )
    {
        if( s == 2 )
		{
			tongji(n , 0, sz, 3 , sum );
		}
        else 
		{
			++ *sum ;
		}
        return 0;
    }
    int i ;
    for(i = 0 ; i < n ; i ++)
    {
        if(sz[x][i] != 1)
		{
			continue;
		}
        if(check(n , x , i , sz , s ))
		{
			sz[x][i]=s;
		}
        else 
		{
			continue;	
		}
        tongji(n , x+1 , sz , s ,sum );
        sz[x][i]=1;
    }
    return * sum;
} 
int check(int  n , int x ,int y ,int sz[][8] , int s)
{
    int i , j;
    for( i = x-1 ; i >= 0 ; i --)
    {
        if(sz[i][y] == s)
		{
			return 0;
		}
    }
    for(i=x-1,j = y-1 ; i >= 0 && j >= 0; i -- , j --)
    {
        if(sz[i][j] == s)
		{
			return 0;
		}
    }
    for(i = x-1,j = y+1;i >= 0 && j < n ; i -- , j ++)
    {
        if( sz[i][j]== s)
        {
        	return 0;
		}
    }
    return 1;
}
void shuru( int  n , int sz[][8])
{
	int i , j ;
	for( i = 0 ; i < n ; i ++)
    {
        for( j = 0 ; j < n ; j ++)
        {
            scanf("%d",&sz[i][j]);
        }
    }
}
