//设计程序，已知一段数据范围[a,b]，要求对其中的每一个数进行素数分解
#include<stdio.h>

void printFactor( int, int ); 

int main()
{
    int a,b,i ;
    
    scanf( "%d%d", &a, &b );
    for( i = a ; i <= b ; i++ )
        printFactor( i , 1 ) ;    
    
    return 0;
}

/* 请在这里填写答案 */
int isPrim(int x)
{
    int i, p = 1;
    for (i = 2; i < x;i++)
    {
        if(x%i==0)
        {
            p = 0;
            break;
        }
    }
    if(x==1)
        p = 0;
    return p;
}

void printFactor(int in, int p)
{
    if(in==1)
        printf("1=1\n");
    else if(isPrim(in)==1)
    {
        if(p==1)
            printf("%d=%d\n", in, in);
        else if(p!=1)
            printf("*%d\n",in);
    }
    else if(isPrim(in)==0)
    {
        int i;
        if(p==1)
        {
            for (i = 2; i*i<=in; i++)
            {
                if(isPrim(i)==1&&in%i==0)
                {
                    printf("%d=%d", in, i);
                    printFactor(in / i, i);
                    break;
                }
            }
        }
        if(p!=1)
        {
            for (i = p; i*i<=in;i++)
            {
                if(isPrim(i)==1&&in%i==0)
                {
                    printf("*%d", i);
                    printFactor(in / i, i);
                    break;
                }
            }
        }
    }
}
