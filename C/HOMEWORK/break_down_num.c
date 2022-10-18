#include<stdio.h>
int main()
{
    long long input;
    scanf("%lld",&input);
    long long p=100000000;//10^8
    int i;
    int flag=0;
    int print;
    long long cache=input;
    for(i=1;i<=9;i++,p=p/10)
    {
        print=cache/p;
        if(print!=0)
            flag=1;
        if(flag==1)
            printf("%d",print);
        if(i<9&&flag==1)
            printf(" ");
        if(i==9)
            printf("\n");
        cache=cache%p;
    }
    return 0;
}