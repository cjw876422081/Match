/*
基础练习 Huffuman树 
 
问题描述
　　Huffman树在编码中有着广泛的应用。在这里，我们只关心Huffman树的构造过程。
　　给出一列数{pi}={p0, p1, …, pn-1}，用这列数构造Huffman树的过程如下：
　　1. 找到{pi}中最小的两个数，设为pa和pb，将pa和pb从{pi}中删除掉，然后将它们的

和加入到{pi}中。这个过程的费用记为pa + pb。
　　2. 重复步骤1，直到{pi}中只剩下一个数。
　　在上面的操作过程中，把所有的费用相加，就得到了构造Huffman树的总费用。
　　本题任务：对于给定的一个数列，现在请你求出用该数列构造Huffman树的总费用。

　　例如，对于数列{pi}={5, 3, 8, 2, 9}，Huffman树的构造过程如下：
　　1. 找到{5, 3, 8, 2, 9}中最小的两个数，分别是2和3，从{pi}中删除它们并将和5加入，

得到{5, 8, 9, 5}，费用为5。
　　2. 找到{5, 8, 9, 5}中最小的两个数，分别是5和5，从{pi}中删除它们并将和10加入，得

到{8, 9, 10}，费用为10。
　　3. 找到{8, 9, 10}中最小的两个数，分别是8和9，从{pi}中删除它们并将和17加入，得

到{10, 17}，费用为17。
　　4. 找到{10, 17}中最小的两个数，分别是10和17，从{pi}中删除它们并将和27加入，得

到{27}，费用为27。
　　5. 现在，数列中只剩下一个数27，构造过程结束，总费用为5+10+17+27=59。
输入格式
　　输入的第一行包含一个正整数n（n<=100）。
　　接下来是n个正整数，表示p0, p1, …, pn-1，每个数不超过1000。
输出格式
　　输出用这些数构造Huffman树的总费用。
样例输入
5
5 3 8 2 9
样例输出
59

*/
#include <stdio.h>
typedef 
	struct
	{
	    int a[100];
	    int len;
	}Huffuman;
	
void zxlgd(Huffuman*  ,int * );
void paixu(Huffuman* );
void chuli(Huffuman* );
void jiaru(Huffuman*  ,int );
int main(void)
{
    Huffuman shu;
    int n , i , j ;
    scanf("%d",&n) ;
    shu.len = n ;
    for(i = 0 ; i < n ; i ++)
    {
    	scanf("%d",&shu.a[i]);
	}
	int sum = 0;
    while(1)
    {
        if(shu.len==2)
        {
            sum=sum+shu.a[0]+shu.a[1];
            break;
        }
    	zxlgd(&shu ,&sum);
     	
    }
    printf("%d\n", sum );
    return 0;
}
void paixu(Huffuman * shu  )
{
	int i , j ;
	for(i = 0 ;i < shu->len-1 ; i ++)
    {
	  	for(j= i + 1 ; j < shu->len ; j ++)
	  	{
	  	    if(shu->a[i]>shu->a[j])
        	{
	            int tmp=shu->a[i];
	            shu->a[i]=shu->a[j];
	            shu->a[j]=tmp;
       	 	}
	  	}

	}
}

void zxlgd(Huffuman * shu ,int * sum)
{
    int mina,minb;
	paixu( shu );
    mina=shu->a[0];
    minb=shu->a[1];
	chuli(shu);
	chuli(shu);
	jiaru(shu,mina+minb);
	* sum = * sum + (mina + minb);
}

void chuli(Huffuman* in )
{
   	int i;
    for(i=0;i<in->len-1 ;i++)
    {
    	in->a[i]=in->a[i+1]; 
	}
    in->len--;
}

void jiaru(Huffuman * shu,int t)
{
    shu->a[shu->len]=t;
    shu->len ++;
}
