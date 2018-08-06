/*

问题描述
　　最近的m天盾神都去幼儿园陪小朋友们玩去了~
　　每个小朋友都拿到了一些积木，他们各自需要不同数量的积木来拼一些他们想要的东西。
但是有的小朋友拿得多，有的小朋友拿得少，有些小朋友需要拿到其他小朋友的积木才能完成他的大作。
如果某个小朋友完成了他的作品，那么他就会把自己的作品推倒，而无私地把他的所有积木都奉献出来；
但是，如果他还没有完成自己的作品，他是不会把积木让出去的哟~
　　盾神看到这么和谐的小朋友们感到非常开心，
于是想帮助他们所有人都完成他们各自的作品。盾神现在在想，这个理想有没有可能实现呢？
于是把这个问题交给了他最信赖的你。
输入格式
　　第一行为一个数m。
　　接下来有m组数据。每一组的第一行为n，表示这天有n个小朋友。接下来的n行每行两个数，
分别表示他现在拥有的积木数和他一共需要的积木数。
输出格式
　　输出m行，如果第i天能顺利完成所有作品，输出YES，否则输出NO。
样例输入
2
2
1 3
2 2
3
1 5
3 3
0 4
样例输出
YES
NO
数据规模和约定
　　1<=n<=10000，1<=m<=10。
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
