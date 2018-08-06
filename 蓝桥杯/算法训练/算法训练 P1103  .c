/*
　　编程实现两个复数的运算。设有两个复数 和 ，则他们的运算公式为：

　　要求：（1）定义一个结构体类型来描述复数。
　　（2）复数之间的加法、减法、乘法和除法分别用不用的函数来实现。
　　（3）必须使用结构体指针的方法把函数的计算结果返回。
　　说明：用户输入：运算符号(+,-,*,/) a b c d.
　　输出：a+bi，输出时不管a,b是小于0或等于0都按该格式输出，输出时a,b都保留两位。
输入：
　　- 2.5 3.6 1.5 4.9
输出：
　　1.00+-1.30i
*/ 
#include <stdio.h>

typedef
 	struct
	{
		double ss ;
		double xs ;
	} fs_t;
	
void shuru(fs_t *);
void q_jia(fs_t,fs_t,fs_t *);
void q_jian(fs_t,fs_t,fs_t *);
void q_cheng(fs_t,fs_t,fs_t *);
void q_chu(fs_t,fs_t,fs_t *);

int main(void)
{
	fs_t fs1 ;
	fs_t fs2 ;
	fs_t jg ;
	char fh ;
	scanf("%c", &fh );
	shuru(&fs1);
	shuru(&fs2);
	switch(fh)
	{
		case '+':
				q_jia(fs1,fs2,&jg);
				break;
		case '-':
				q_jian(fs1,fs2,&jg);
				break;
		case '*':
				q_cheng(fs1,fs2,&jg);
				break;
		case '/':
				q_chu(fs1,fs2,&jg);
				break;	
	}
	printf("%.2lf+%.2lfi\n", jg.ss , jg.xs );
	return 0;
}

void q_chu(fs_t fs1,fs_t fs2,fs_t * jg)
{
	jg->ss = ( fs1.ss * fs2.ss + fs1.xs * fs2.xs ) / ( ( fs2.ss * fs2.ss) + ( fs2.xs * fs2.xs) );
	jg->xs = ( fs1.xs * fs2.ss - fs1.ss * fs2.xs ) / ( ( fs2.ss * fs2.ss) + ( fs2.xs * fs2.xs) );
}

void q_cheng(fs_t fs1,fs_t fs2,fs_t * jg)
{
	jg->ss = fs1.ss * fs2.ss - fs1.xs * fs2.xs;
	jg->xs = fs1.xs * fs2.ss + fs1.ss * fs2.xs;
}

void q_jian(fs_t fs1,fs_t fs2,fs_t * jg)
{
	jg->ss = fs1.ss - fs2.ss ;
	jg->xs = fs1.xs - fs2.xs ;
}

void q_jia(fs_t fs1,fs_t fs2,fs_t * jg)
{
	jg->ss = fs1.ss + fs2.ss ;
	jg->xs = fs1.xs + fs2.xs ;
}

void shuru(fs_t * fs)
{
	scanf("%lf", &fs->ss );
	scanf("%lf", &fs->xs );
}
