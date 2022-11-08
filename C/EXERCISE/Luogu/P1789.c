#include<stdio.h>
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int space[n + 1][n + 1];
    int i1, i2;
    int ans = 0;
    for (i1 = 1; i1 <= n;i1++)
    {
        for (i2 = 1; i2 <= n;i2++)
        {
            space[i1][i2] = 0;
        }
    }
    int i;
    int x, y;
    int p1, p2;
    for (i = 1; i <= m;i++)
    {
        scanf("%d%d", &x, &y);
        for (p1 = 1; p1 <= 5;p1++)
        {
            for (p2 = 1; p2 <= 5;p2++)
            {
                if((x-3+p1>0&&y-3+p2>0&&x-3+p1<=n&&y-3+p2<=n))
                {
                    if((p1>=2&&p1<=4&&p2>=2&&p2<=4)||(p1==3)||(p2==3))
                        space[x - 3 + p1][y - 3 + p2] = 1;
                }
            }
        }
    }
    for (i = 1; i <= k;i++)
    {
        scanf("%d%d", &x, &y);
        
        for (p1 = 1; p1 <= 5;p1++)
        {
            for (p2 = 1; p2 <= 5;p2++)
            {
                if(x-3+p1>0&&y-3+p2>0&&x-3+p1<=n&&y-3+p2<=n)
                    space[x - 3 + p1][y - 3 + p2] = 1;
            }
        }
    }
    for (i1 = 1; i1 <= n;i1++)
    {
        for (i2 = 1; i2 <= n;i2++)
        {
            if(space[i1][i2]==0)
                ans++;
        }
    }
    printf("%d", ans);
    return 0;
}
