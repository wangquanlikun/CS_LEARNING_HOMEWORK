#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int i, ans = 0;
    for (i = 1; ans < n;i++)
    {
        ans = ans + i;
        if(ans>=n)
            break;
    }
    ans = ans - i;
    int remain = n - ans;
    if(i%2!=0)
        printf("%d/%d", i + 1 - remain, remain);
    else if(i%2==0)
        printf("%d/%d", remain, i + 1 - remain);
    return 0;
}
