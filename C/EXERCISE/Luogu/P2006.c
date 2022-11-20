#include<stdio.h>
int main()
{
    int k, m, n;
    scanf("%d%d%d", &k, &m, &n);
    int skill[m + 1][2];
    int i;
    for (i = 1; i <= m;i++)
    {
        scanf("%d%d", &skill[i][1], &skill[i][2]);
    }
    int p = 0;
    for (i = 1; i <= m;i++)
    {
        int times;
        if(skill[i][1]!=0)
            times = k / skill[i][1];
        else if(skill[i][1]==0)
        {
            if(skill[i][2]!=0)
                goto print;
            else if(skill[i][2]==0)
                goto end;
        }
        if(times*skill[i][2]>=n)
        {
            print:
            if(p==0)
            printf("%d", i);
            else if(p==1)
            printf(" %d", i);
            p = 1;
        }
    end:;
    }
    if(p==0)
        printf("-1");
    return 0;
}
