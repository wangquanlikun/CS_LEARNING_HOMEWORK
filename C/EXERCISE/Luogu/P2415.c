#include<stdio.h>
long long ax(int a, int x);
int main()
{
    int a[30 + 1];
    int i;
    for (i = 1; i <= 30;i++)
    {
        scanf("%d", &a[i]);
        if(getchar()=='\n')
            break;
    }
    long long ans = 0;
    int ii;
    for (ii = 1; ii <= i;ii++)
    {
        ans = ans + a[ii] * ax(2, i - 1);
    }
    printf("%lld", ans);
    return 0;
}

long long ax(int a, int x)
{
    int i;
    long long ans = 1;
    for (i = 1; i <= x;i++)
        ans = ans * a;
    return ans;
}
