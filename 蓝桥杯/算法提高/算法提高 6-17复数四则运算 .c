/*
��Ƹ����⣬ʵ�ֻ����ĸ����Ӽ��˳����㡣
��������ʱֻ��ֱ����ʵ�����鲿���Կո�ָ
	��������֮����������ָ���
	���ʱ��a+bi�ĸ�ʽ����Ļ�ϴ�ӡ�����
	�μ�������������������
����ע�⿼������������޷�����ʱ����ַ���"error"��
��������
2 4 * -3 2
�������
-14-8i
��������
3 -2 + -1 3
�������
2+1i*/
#include<stdio.h>
typedef
struct
{
	double sb ; 
	double xb ; 
}Fs_t ; 
void Input( Fs_t * , Fs_t *, char *) ; 
void Solve( Fs_t  ,Fs_t  , char ); 
void add(Fs_t  ,Fs_t);
void sub(Fs_t  ,Fs_t);
void mul(Fs_t  ,Fs_t);
void div(Fs_t  ,Fs_t);
double main(void)
{
	Fs_t fs1 , fs2 ;
	char ch ;  
	Input( &fs1 , &fs2  , & ch );
	Solve( fs1 , fs2 , ch ) ; 
	return 0 ; 
}
void add(Fs_t fs1 , Fs_t fs2 )
{
	printf("%.0lf+%.0lfi" , fs1.sb+fs2.sb , fs1.xb+fs2.xb );	
}
void sub(Fs_t fs1 , Fs_t fs2)
{
	printf("%.0lf" , fs1.sb - fs2.sb);
	if( fs1.xb - fs2.xb >= 0 )
	{
		putchar('+'); 
	}
	printf("%.0lfi", fs1.xb - fs2.xb) ;
}
void mul(Fs_t fs1 , Fs_t fs2)
{
	printf("%.0lf" , fs1.sb * fs2.sb - fs1.xb*fs2.xb) ; 
	if( fs1.sb*fs2.xb + fs1.xb*fs2.sb >= 0 )
	{
		putchar('+'); 
	}
	printf("%.0lfi", fs1.sb*fs2.xb + fs1.xb*fs2.sb ) ;
}
void div(Fs_t fs1 , Fs_t fs2)
{
	if( fs2.sb == 0 && fs2.xb == 0 )
	{
		printf("error\n") ; 
		return ;  
	}
	printf("%g" , (fs1.sb * fs2.sb + fs1.xb*fs2.xb) / ( fs2.sb * fs2.sb + fs2.xb * fs2.xb)) ; 
	if( fs1.xb*fs2.sb - fs1.sb*fs2.xb >= 0 )
	{
		putchar('+');
	}
	printf("%gi" , (fs1.xb*fs2.sb - fs1.sb*fs2.xb) / ( fs2.sb * fs2.sb + fs2.xb * fs2.xb)); 
}
void Solve(Fs_t fs1, Fs_t fs2, char c)
{
	switch( c )
	{
		case '+': add( fs1 , fs2 );
		break ; 
		case'-': sub( fs1 , fs2 );
		break ; 
		case'*': mul( fs1 , fs2 );
		break ; 
		case'/': div( fs1 , fs2 );
		break ; 
	}
}
void Input( Fs_t *fs1 , Fs_t *fs2 , char * ch) 
{
	scanf("%lf%lf %s %lf%lf",&fs1->sb , &fs1->xb  , ch , &fs2->sb , & fs2->xb);
} 
