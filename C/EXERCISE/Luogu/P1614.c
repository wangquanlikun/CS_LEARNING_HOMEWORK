#include<stdio.h>
int main()
{
    long long n, m;
    scanf("%lld%lld", &n, &m);
    int a[n + 1];
    long long i;
    for (i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    int sum=0, sum_min;
    for (i = 1; i <= n - m + 1;i++)
    {
        long long ii;
        for (ii = i; ii - i + 1 <= m; ii++)
        {
            sum = sum + a[ii];
        }
        if(i==1)
            sum_min = sum;
        if(sum<sum_min)
            sum_min = sum;
        sum = 0;
    }
    printf("%d", sum_min);
    return 0;
}
