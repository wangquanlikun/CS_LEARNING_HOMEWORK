#include<stdio.h>
int isPrim(int);
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    for (i = 1; i * i <= n;i++)
    {
        if(isPrim(i)==1&&isPrim(n/i)==1&&n%i==0)
        {
            printf("%d", n / i);
            return 0;
        }
    }
}

int isPrim(int x)
{
    int i;
    int p = 1;
    for (i = 2; i * i <= x;i++)
    {
        if(x%i==0)
        {
            p = 0;
        }
    }
    return p;
}
