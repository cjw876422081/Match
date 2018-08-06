/*
�������ʵ���������������㡣������������ �� �������ǵ����㹫ʽΪ��

����Ҫ�󣺣�1������һ���ṹ������������������
������2������֮��ļӷ����������˷��ͳ����ֱ��ò��õĺ�����ʵ�֡�
������3������ʹ�ýṹ��ָ��ķ����Ѻ����ļ��������ء�
����˵�����û����룺�������(+,-,*,/) a b c d.
���������a+bi�����ʱ����a,b��С��0�����0�����ø�ʽ��������ʱa,b��������λ��
���룺
����- 2.5 3.6 1.5 4.9
�����
����1.00+-1.30i
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
