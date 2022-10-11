#include<stdio.h>
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int p;
    if(a<=b)
        p = a;
    else
        p = b;
    for (; p > 0;p--)
    {
        if(a%p==0&&b%p==0)
        {
            break;
        }
    }
    printf("%d", p);
}