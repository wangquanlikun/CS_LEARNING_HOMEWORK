//使用辗转相除法
#include<stdio.h>
int main()
{
    int a, b;//a>=b
    scanf("%d%d", &a, &b);
    int m, n;
    m = a, n = b;
    int ans;
    int adjust = 0;
    do
    {
        int remain = m % n;
        if(remain==0)
            {
                adjust = 1;
                ans = n;
            }
        else
        m = n, n = remain;
    } while (adjust == 0);
    printf("%d", ans);
    return 0;
}