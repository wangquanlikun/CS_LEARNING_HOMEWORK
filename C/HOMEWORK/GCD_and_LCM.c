#include<stdio.h>
int main()
{
    int a, b;//a>=b
    scanf("%d%d", &a, &b);
    int cache;
    if(a<b)
    {
        cache=a;
        a=b;
        b=cache;
    }
    int m, n;
    m = a, n = b;
    int ans1;
    long int ans2;
    int adjust = 0;
    do
    {
        int remain = m % n;
        if(remain==0)
            {
                adjust = 1;
                ans1 = n;
            }
        else
        m = n, n = remain;
    } while (adjust == 0);
    ans2 = (a / ans1) * b;
    printf("%d %ld", ans1,ans2);
    return 0;
}