#include<stdio.h>
int main()
{
    int l, m;
    scanf("%d%d", &l, &m);
    int tree[l+1];
    int i;
    for (i = 0; i <= l;i++)
    {
        tree[i] = 1;
    }
    int ans = l+1;
    for (i = 1; i <= m;i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int p;
        for (p = a; p <= b;p++)
        {
            if(tree[p]==1)
                ans--;
            tree[p] = 0;
        }
    }
    printf("%d", ans);
    return 0;
}
