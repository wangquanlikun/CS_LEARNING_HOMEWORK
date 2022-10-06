#include<stdio.h>
int main()
{
    long long n;
    scanf("%lld",&n);
    long long sum=0;
    long long an=0;
    long long i,p;//循环项数
    if(n<3)
        sum=0;
    else
    {
        for(i=3;i<=n;i++)
        {
            for(p=3;p<=i;p++)
            {
                an=an+p*(p-1)*(p-2);
            }
            sum=sum+an;
            an=0;
        }
    }
    printf("%lld",sum);
    return 0;
}
