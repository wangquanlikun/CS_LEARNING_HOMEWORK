#include<stdio.h>

long long mi(int x,int n)
{
    int i;
    long long ans1 = 1;
    for (i = 1; i <= n;i++)
    {
        ans1 = ans1 * x;
    }
    return (ans1);
}

int main()
{
    int n, x;
    scanf("%d%d", &x, &n);
    long long ans=mi(x, n);
    printf("%lld", ans);
    return 0;
}