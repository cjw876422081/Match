/*

��������
���������m�����ȥ�׶�԰��С��������ȥ��~
����ÿ��С���Ѷ��õ���һЩ��ľ�����Ǹ�����Ҫ��ͬ�����Ļ�ľ��ƴһЩ������Ҫ�Ķ�����
�����е�С�����õö࣬�е�С�����õ��٣���ЩС������Ҫ�õ�����С���ѵĻ�ľ����������Ĵ�����
���ĳ��С���������������Ʒ����ô���ͻ���Լ�����Ʒ�Ƶ�������˽�ذ��������л�ľ�����׳�����
���ǣ��������û������Լ�����Ʒ�����ǲ���ѻ�ľ�ó�ȥ��Ӵ~
�������񿴵���ô��г��С�����Ǹе��ǳ����ģ�
������������������˶�������Ǹ��Ե���Ʒ�������������룬���������û�п���ʵ���أ�
���ǰ�������⽻���������������㡣
�����ʽ
������һ��Ϊһ����m��
������������m�����ݡ�ÿһ��ĵ�һ��Ϊn����ʾ������n��С���ѡ���������n��ÿ����������
�ֱ��ʾ������ӵ�еĻ�ľ������һ����Ҫ�Ļ�ľ����
�����ʽ
�������m�У������i����˳�����������Ʒ�����YES���������NO��
��������
2
2
1 3
2 2
3
1 5
3 3
0 4
�������
YES
NO
���ݹ�ģ��Լ��
����1<=n<=10000��1<=m<=10��
*/
#include <stdio.h>
#define N (10000)
typedef
	struct
	{
		int yy;
		int xy;
		int qt;
	}xpy;
void shuru( xpy [], int );
void paixu( xpy [], int , int );
void shuchu( xpy [], int );
int main(void)
{
	int m ;
	xpy jm[N];
	scanf("%d" ,&m );
	while( m -- > 0 )
	{
		int n ;
		scanf("%d" , &n );
		shuru( jm , n  );
		paixu( jm , 0  , n - 1);
		shuchu( jm , n );
	} 
	return 0;
}
void shuchu( xpy jm[] , int n)
{
	int i , s = 0  ; 
	for( i = n - 1 ; i  >= 0 ; i --)
	{
		if( jm[i].qt + s >= 0)
		{
			s += jm[i].yy ; 
		}
		else
		{
			printf("NO\n");
			return ; 
		}
	}
	printf("YES\n");
}

void paixu(xpy a[] , int left , int right)
{
    if(left >= right)
    {
        return ;
    }
    int i = left;
    int j = right;
    xpy key ;
    key.yy = a[left].yy ;
    key.xy = a[left].xy ;
    key.qt = a[left].qt ;
    while(i < j)                           
    {
        while(i < j && key.qt <= a[j].qt)
        {
            j--;
        }
        a[i].yy = a[j].yy;
        a[i].xy = a[j].xy;
        a[i].qt = a[j].qt;
        while(i < j && key.qt >= a[i].qt)
        {
            i++;
        }
        a[j].yy = a[i].yy;
        a[j].xy = a[i].xy;
        a[j].qt = a[i].qt ;
    }
    a[i] = key;
    paixu(a, left, i - 1);
    paixu(a, i + 1, right);

}
void shuru( xpy jm[] , int  n )
{
	int i ;
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%d%d" , &jm[i].yy , &jm[i].xy );
		jm[i].qt = jm[i].yy - jm[i].xy ; 
	}

}
