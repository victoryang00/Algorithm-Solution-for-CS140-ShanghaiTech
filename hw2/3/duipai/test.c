#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define random(a,b) ((a)+rand()%((b)-(a)+1))   //random(a,b)生成[a,b]的随机整数
int main( )
{

    srand( time( NULL ) );
    int t,n = 10000 ;
    while( n-- )
    {
           printf("%d\n",rand() );      //rand()的范围是0~RAND_MAX(即[0,32767])
    }
    return 0;
}