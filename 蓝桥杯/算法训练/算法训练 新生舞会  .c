/*

  算法训练 新生舞会  
时间限制：1.0s   内存限制：512.0MB
    
问题描述
　　新生舞会开始了。n名新生每人有三个属性：姓名、学号、性别。其中，
姓名用长度不超过20的仅由大小写字母构成的字符串表示，学号用长度不超过10的仅由数字构成的字符串表示，
性别用一个大写字符‘F’或‘M’表示。任意两人的姓名、学号均互不相同。换言之，每个人可被其姓名或学号唯一确定。
给出m对两人的信息（姓名或学号），判断他们是否能共舞。两人能共舞的充要条件为两人性别相异。

输入
　　第一行一个整数n（2<=n<=1000），表示学生人数。
接下来的n行每行依次包含一名新生的姓名、学号、性别，分别用一个空格隔开。
　　之后的一行是一个整数m(1<=m<=1000)，表示询问的数目。
接着的m行每行包含两个信息（姓名或学号），保证两个信息不属于同一人，中间用一个空格隔开。
输出
　　对于每个询问输出一行，如果两人可以共舞，
输出一个大写字母‘Y’，否则输出一个大写字母‘N’。
样例输入
4
John 10 M
Jack 11 M
Kate 20 F
Jim 21 M
3
John 11
20 Jack
Jim Jack
样例输出
　　N
　　Y
　　N

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
