#include<stdio.h>
int len(int x)
{
    int len;
    for (len = 1;;len++)
    {
        if(x/10==0)
            break;
        else
            x = x / 10;
    }
    return len;
}
int countnum(int a,int b)
{
    int ans = 0;
    int i;
    int len_a = len(a);
    for (i = 1; i <= len_a;i++)
    {
        if(a%10==b)
            ans++;
        a = a / 10;
    }
    return ans;
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int i;
    int ans = 0;
    for (i = 1; i <= a;i++)
    {
        ans = ans + countnum(i, b);
    }
    printf("%d", ans);
    return 0;
}
