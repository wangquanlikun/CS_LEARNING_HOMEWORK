#include<stdio.h>
int main()
{
    int n,m;
    int i;
    scanf("%d%d", &n, &m);
    for(i=1;i<=n;i++)
    {
        int cache=i;
        int sum1,sum2=0;
        sum1=i/m;
        int p;
        for (p = 1; p <= 5; p++)
        {
            sum2=sum2+(cache%10)*(cache%10);
            cache=cache/10;
        }
        if(sum1==sum2)
        {
            printf("%d\n",i);
        }
    }
    return 0;
}