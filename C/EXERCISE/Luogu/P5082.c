#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int full[n], score[n];
    double ans = 0;
    for (i = 0; i < n;i++)
    {
        scanf("%d", &full[i]);
        ans += full[i] * 3;
    }
    for (i = 0; i < n;i++)
    {
        scanf("%d", &score[i]);
        ans -= score[i] * 2;
    }
    double ans_chu;
    for (i = 0; i < n;i++)
        ans_chu += full[i] - score[i];
    ans = ans / ans_chu;
    printf("%.6lf", ans);
    return 0;
}
