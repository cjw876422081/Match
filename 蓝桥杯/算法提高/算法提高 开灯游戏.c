/*    
问题描述
　　有9盏灯与9个开关，编号都是1~9。
　　每个开关能控制若干盏灯，按下一次会改变其控制的灯的状态(亮的变成不亮，不亮变成亮的)。
　　具体如下：
　　第一个开关控制第二，第四盏灯；
　　第二个开关控制第一，第三，第五盏灯；
　　第三个开关控制第二，第六盏灯；
　　第四个开关控制第一，第五，第七盏灯；
　　第五个开关控制第二，第四，第六，第八盏灯；
　　第六个开关控制第三，第五，第九盏灯；
　　第七个开关控制第四，第八盏灯；
　　第八个开关控制第五，第七，第九盏灯；
　　第九个开关控制第六，第八盏灯。
　　开始时所有灯都是熄灭的，
开关是关闭着的。要求按下若干开关后，使得只有4盏灯亮着。
输出格式
　　输出所有可能的方案，每行一个方案，每一行有9个字符，
从左往右第i个字符表示第i个开关的状态("0"表示关闭，
"1"表示打开)，按字典序输出。下面的样例输出只是部分方案。
样例输出
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
