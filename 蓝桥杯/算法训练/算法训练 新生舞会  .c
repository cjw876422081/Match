/*

  �㷨ѵ�� �������  
ʱ�����ƣ�1.0s   �ڴ����ƣ�512.0MB
    
��������
����������Ὺʼ�ˡ�n������ÿ�����������ԣ�������ѧ�š��Ա����У�
�����ó��Ȳ�����20�Ľ��ɴ�Сд��ĸ���ɵ��ַ�����ʾ��ѧ���ó��Ȳ�����10�Ľ������ֹ��ɵ��ַ�����ʾ��
�Ա���һ����д�ַ���F����M����ʾ���������˵�������ѧ�ž�������ͬ������֮��ÿ���˿ɱ���������ѧ��Ψһȷ����
����m�����˵���Ϣ��������ѧ�ţ����ж������Ƿ��ܹ��衣�����ܹ���ĳ�Ҫ����Ϊ�����Ա����졣

����
������һ��һ������n��2<=n<=1000������ʾѧ��������
��������n��ÿ�����ΰ���һ��������������ѧ�š��Ա𣬷ֱ���һ���ո������
����֮���һ����һ������m(1<=m<=1000)����ʾѯ�ʵ���Ŀ��
���ŵ�m��ÿ�а���������Ϣ��������ѧ�ţ�����֤������Ϣ������ͬһ�ˣ��м���һ���ո������
���
��������ÿ��ѯ�����һ�У�������˿��Թ��裬
���һ����д��ĸ��Y�����������һ����д��ĸ��N����
��������
4
John 10 M
Jack 11 M
Kate 20 F
Jim 21 M
3
John 11
20 Jack
Jim Jack
�������
����N
����Y
����N

*/
#include<stdio.h>
#include<string.h>
typedef 
	struct 
	{
		char name[21];
		char num[21];
		char sex ;
	}tstudent;

void solve( tstudent student[] , int , int );
void readdata( tstudent student[] , int );
int findstudent(tstudent student[] , int  , char *);

int main( void )
{
	int n , m ;
	tstudent student[1010];
	scanf("%d\n" ,&n );
	readdata( student , n );
	scanf("%d" ,&m );
	solve( student , n , m );
	return 0 ; 
} 
void solve(tstudent student[] , int n , int m )
{
	int i ; 
	char x[21], y[21];
	for ( i = 0 ; i < m ; i ++ )   
	{
		scanf("%s%s", x , y );
		int a = findstudent( student ,  n  , x ) ;
		int b = findstudent( student ,  n  , y ) ;
		if(  a != b && student[a].sex != student[b].sex )
		{
			printf("Y\n");
		}
		else
		{
			printf("N\n");
		}
	}
}
void readdata( tstudent student[], int n)
{
	int i ; 
	for(i = 0 ; i < n ; i ++ )
	{
		scanf("%s%s %c" ,student[i].name ,student[i].num , &student[i].sex );
	}
}
int findstudent(tstudent student[] , int n , char * data)
{
	int i ;
	for(i = 0 ; i < n ; i ++ )
	{
		if( strcmp( student[i].name , data ) == 0 )
		{
			return i ; 
		}
		if( strcmp( student[i].num , data ) == 0 )
		{
			return i ;
		}
	} 
}
