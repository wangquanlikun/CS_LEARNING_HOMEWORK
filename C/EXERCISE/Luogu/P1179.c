#include<stdio.h>
int len_simple(int);
int main()
{
    int l, r;
    scanf("%d%d", &l, &r);
    int i;
    int ans=0;
    for (i = l; i <= r;i++)
    {
        int bit;
        int ii;
        int i_cache = i;
        for (ii = 1; ii <= len_simple(i);ii++)
        {
            bit = i_cache % 10;
            i_cache = i_cache / 10;
            if(bit==2)
                ans++;
        }
    }
    printf("%d", ans);
    return 0;
}

int len_simple(int x)
{
    if(x<=9)
        return 1;
    else if(x>=10&&x<=99)
        return 2;
    else if(x>=100&&x<=999)
        return 3;
    else if(x>=1000&&x<=9999)
        return 4;
    else if(x>=10000&&x<=99999)
        return 5;
    else if(x>=100000&&x<=999999)
        return 6;
}
