/*    
��������
������9յ����9�����أ���Ŷ���1~9��
����ÿ�������ܿ�������յ�ƣ�����һ�λ�ı�����ƵĵƵ�״̬(���ı�ɲ����������������)��
�����������£�
������һ�����ؿ��Ƶڶ�������յ�ƣ�
�����ڶ������ؿ��Ƶ�һ������������յ�ƣ�
�������������ؿ��Ƶڶ�������յ�ƣ�
�������ĸ����ؿ��Ƶ�һ�����壬����յ�ƣ�
������������ؿ��Ƶڶ������ģ��������ڰ�յ�ƣ�
�������������ؿ��Ƶ��������壬�ھ�յ�ƣ�
�������߸����ؿ��Ƶ��ģ��ڰ�յ�ƣ�
�����ڰ˸����ؿ��Ƶ��壬���ߣ��ھ�յ�ƣ�
�����ھŸ����ؿ��Ƶ������ڰ�յ�ơ�
������ʼʱ���еƶ���Ϩ��ģ�
�����ǹر��ŵġ�Ҫ�������ɿ��غ�ʹ��ֻ��4յ�����š�
�����ʽ
����������п��ܵķ�����ÿ��һ��������ÿһ����9���ַ���
�������ҵ�i���ַ���ʾ��i�����ص�״̬("0"��ʾ�رգ�
"1"��ʾ��)�����ֵ��������������������ֻ�ǲ��ַ�����
�������
000001011
000001110
000001111
*/
#include<stdio.h>  
void dengpao(int ,int [],int [])  ;
void panduan(int [],int []) ;
void Solve( int , int , int [] , int [] )   ;
int main(void)  
{  
    int kaiguan[10]={0};
    int dengpao[10]={0};
    Solve( 1 , 9 , kaiguan , dengpao ) ;   
    return 0;  
} 
void dengpao(int start , int p_kg[] , int p_d[] )  
{  
    if(start==1 && p_kg[start]==1)  
    {  
        p_d[2]=!p_d[2];  
        p_d[4]=!p_d[4];  
    }  
    if(start==2 && p_kg[start]==1)  
    {  
        p_d[1]=!p_d[1];  
        p_d[3]=!p_d[3];  
        p_d[5]=!p_d[5];  
    }  
    if(start==3 && p_kg[start]==1)  
    {  
        p_d[2]=!p_d[2];  
        p_d[6]=!p_d[6];  
    }  
    if(start==4 && p_kg[start]==1)  
    {  
        p_d[1]=!p_d[1];  
        p_d[5]=!p_d[5];  
        p_d[7]=!p_d[7];  
    }  
    if(start==5 && p_kg[start]==1)  
    {  
        p_d[2]=!p_d[2];  
        p_d[4]=!p_d[4];  
        p_d[6]=!p_d[6];  
        p_d[8]=!p_d[8];  
    }  
    if(start==6 && p_kg[start]==1)  
    {  
        p_d[3]=!p_d[3];  
        p_d[5]=!p_d[5];  
        p_d[9]=!p_d[9];  
    }  
    if(start==7 && p_kg[start]==1)  
    {  
        p_d[4]=!p_d[4];  
        p_d[8]=!p_d[8];  
    }  
    if(start==8 && p_kg[start]==1)  
    {  
        p_d[5]=!p_d[5];  
        p_d[7]=!p_d[7];  
        p_d[9]=!p_d[9];  
    }  
    if(start==9 && p_kg[start]==1)  
    {  
        p_d[6]=!p_d[6];  
        p_d[8]=!p_d[8];  
    }  
}    
void panduan( int p_kg[] , int p_d[] )  
{  
    int sum = 0 , i ;  
    for( i = 1 ; i < 10 ; i ++)  
    {  
        sum+=p_d[i];  
    }  
    if(sum==4)  
    {  
        for( i = 1 ; i < 10 ; i ++ )  
        {  
            printf("%d",p_kg[i]);  
        }  
        printf("\n");  
  }  
}  
 
void Solve(int start , int end , int p_kg[] , int p_d[] )  
{  
    int i , kaiguan[10] , deng[10];  
    for( i = 1 ; i < 10 ; i ++ )  
    {  
        kaiguan[i] = p_kg[i];  
    }  
    for( i = 1 ; i < 10 ; i ++ )    
    {  
        deng[i]=p_d[i];  
    }  
    if( start > end )  
    {  
        panduan( kaiguan , deng );  
    }  
    else  
    {  
        for( i = 0 ; i <= 1 ; i ++ )  
        {  
            kaiguan[start] = i ;  
            dengpao( start , kaiguan , deng );  
            Solve( start + 1 , end , kaiguan , deng ) ;  
        }  
    }  
}  
