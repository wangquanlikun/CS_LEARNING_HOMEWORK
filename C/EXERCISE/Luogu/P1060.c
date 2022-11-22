#include<stdio.h>
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    int money[n + 1][3], total[n + 1];
    int i;
    for (i = 1; i <= n;i++)
    {
        scanf("%d%d", &money[i][1], &money[i][2]);
        total[i] = money[i][1] * money[i][2];
    }
    int p[30000] = {0};
    for (i = 1; i <= n;i++)
    {
        int k;
        for (k = m; k >= money[i][1];k--)//k大于i的钱，说明钱还够买第i件商品
        {
            if(p[k]<=p[k-money[i][1]]+total[i])
                p[k] = p[k - money[i][1]] + total[i];
        }
    }
    printf("%d", p[m]);
    return 0;
}
