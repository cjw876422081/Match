/*


��������
�����������[a,b]�������������������ֽ⡣
�����ʽ
����������������a��b��
�����ʽ
����ÿ�����һ�����ķֽ⣬����k=a1*a2*a3...(a1<=a2<=a3...��kҲ�Ǵ�С�����)(����ɿ�����)
��������
3 10
�������
3=3
4=2*2
5=5
6=2*3
7=7
8=2*2*2
9=3*3
10=2*5
��ʾ
������ɸ������������Ȼ���ٷֽ⡣
���ݹ�ģ��Լ��
����2<=a<=b<=10000

*/
#include<stdio.h>
void shuchu( int , int );
int main(void)
{
	int a , b ;
	scanf("%d%d" , & a , & b );
	while( a  <= b )
	{
		printf("%d=" , a);
		shuchu( a ,2);
		putchar('\n');
		a++;
	} 
	return 0;
}
void shuchu( int  n , int ys )
{
	if( n % ys != 0 )
	{
		shuchu( n  , ys +1);
		return ;
	} 
	printf("%d",ys);
	if( n / ys !=1)
	{
		putchar('*');
		shuchu( n / ys  , ys);
	}
}
