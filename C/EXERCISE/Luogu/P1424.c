#include<stdio.h>
int main()
{
    int x, n;
    scanf("%d%d", &x, &n);
    int i1,i2=x;
    int ans = 0;
    for (i1 = 1; i1 <= n;i1++)
    {
        if(i2!=6&&i2!=7)
        {
            ans = ans + 250;
        }
        if(i2==7)
            i2 = 0;
        i2++;
    }
    printf("%d", ans);
    return 0;
}
