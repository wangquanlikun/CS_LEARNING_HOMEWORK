#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    if(n%10==0)
        printf("The number cannot be changed.");
    else
    {
        int len;
        int nn = n;
        for (len = 1;;len++)
        {
            if(nn/10==0)
                break;
            else
                nn = nn / 10;
        }
        int i;
        int cache = n, bit;
        for (i = 1;i<=len;i++)
        {
            bit = cache % 10;
            cache = cache / 10;
            printf("%d", bit);
        }
    }
    return 0;
}