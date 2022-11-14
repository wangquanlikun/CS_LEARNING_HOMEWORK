#include<stdio.h>
int main()
{
    int budget;
    int i, remain=0, store=0;
    int p = 0;
    for (i = 1; i <= 12;i++)
    {
        scanf("%d", &budget);
        remain = remain + 300;
        if(remain<budget)
        {
            p = 1;
            printf("-%d", i);
            break;
        }
        while(remain-budget>=100)
        {
            remain = remain - 100;
            store = store + 100;
        }
        remain = remain - budget;
    }
    if(p==0)
    {
        int ans = remain + 1.2 * store;
        printf("%d", ans);
    }
    return 0;
}
