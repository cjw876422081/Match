/*
������ϰ Huffuman�� 
 
��������
����Huffman���ڱ��������Ź㷺��Ӧ�á����������ֻ����Huffman���Ĺ�����̡�
��������һ����{pi}={p0, p1, ��, pn-1}��������������Huffman���Ĺ������£�
����1. �ҵ�{pi}����С������������Ϊpa��pb����pa��pb��{pi}��ɾ������Ȼ�����ǵ�

�ͼ��뵽{pi}�С�������̵ķ��ü�Ϊpa + pb��
����2. �ظ�����1��ֱ��{pi}��ֻʣ��һ������
����������Ĳ��������У������еķ�����ӣ��͵õ��˹���Huffman�����ܷ��á�
�����������񣺶��ڸ�����һ�����У�������������ø����й���Huffman�����ܷ��á�

�������磬��������{pi}={5, 3, 8, 2, 9}��Huffman���Ĺ���������£�
����1. �ҵ�{5, 3, 8, 2, 9}����С�����������ֱ���2��3����{pi}��ɾ�����ǲ�����5���룬

�õ�{5, 8, 9, 5}������Ϊ5��
����2. �ҵ�{5, 8, 9, 5}����С�����������ֱ���5��5����{pi}��ɾ�����ǲ�����10���룬��

��{8, 9, 10}������Ϊ10��
����3. �ҵ�{8, 9, 10}����С�����������ֱ���8��9����{pi}��ɾ�����ǲ�����17���룬��

��{10, 17}������Ϊ17��
����4. �ҵ�{10, 17}����С�����������ֱ���10��17����{pi}��ɾ�����ǲ�����27���룬��

��{27}������Ϊ27��
����5. ���ڣ�������ֻʣ��һ����27��������̽������ܷ���Ϊ5+10+17+27=59��
�����ʽ
��������ĵ�һ�а���һ��������n��n<=100����
������������n������������ʾp0, p1, ��, pn-1��ÿ����������1000��
�����ʽ
�����������Щ������Huffman�����ܷ��á�
��������
5
5 3 8 2 9
�������
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
