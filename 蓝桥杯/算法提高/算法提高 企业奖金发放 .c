/*
　　企业发放的奖金根据利润提成。利润低于或等于10万元时，奖金可提10%；
利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，
可提成7.5%；20万到40万之间时，高于20万元的部分，可提成5%；40万元到60万元之间时高于40万元的部分，
可提成3%；60万到100万之间时，高于60万元的部分，可提成1.5%；高于100万元时，超过100万元的部分按1%提成。
从键盘输入当月利润，求应发放奖金总数？（保留两位小数）利润的大小在double以内
样例输入
210000
样例输出
18000.00
*/
#include<stdio.h>
void shuchu( double );
int main( void )
{
	double n ; 
	scanf("%lf", &n );
	shuchu( n );
	return 0 ; 
}
void shuchu( double n)
{
	double sum = 0 ;  
	if(n <= 100000)
	{
		sum += n * 0.1 ;
	}
	else
	{
		sum += 100000 * 0.1;
		if( n <= 200000 && n > 100000)
		{
			sum +=(n - 100000) * 0.075;
		}
		else
		{
			sum += 100000 * 0.075;
			if( n <= 400000 && n > 200000)
			{
				sum +=(n - 200000) * 0.05;
			}
			else
			{
				sum += 200000 * 0.05;
				if( n <= 600000 && n > 400000)
				{
					sum +=(n - 400000) * 0.03;
				}
				else
				{
					sum += 200000 * 0.03;
					if( n <= 1000000 && n > 600000 )
					{
						sum +=(n - 600000) * 0.015;
					}
					else
					{
						sum += 400000 * 0.015;
						if(  n > 1000000 )
						{
							sum +=(n - 1000000) * 0.01;
						}
					}
				}
			}
			
		}
		
	}
	printf("%.2lf" , sum );

}
