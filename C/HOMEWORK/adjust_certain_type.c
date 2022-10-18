#include<stdio.h>
int main()
{
    long long input;
    scanf("%lld",&input);
    int p=0;
    int i;
    if(input>=1&&input<=10000)
    {
        long long input2=input*input;
        long long cache=input2;
        int q = 100000000;
        for(i=9;i>0;i--,q=q/10)
        {
            if(cache==input)
            {
                p=1;
                break;
            }
            cache=cache%q;
        }
        if(p==1)
            printf("Yes");
        else if(p==0)
            printf("No");
    }
    else
        printf("%d out of range",input);
    return 0;
}