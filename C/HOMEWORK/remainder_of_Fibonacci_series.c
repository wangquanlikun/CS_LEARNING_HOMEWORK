#include<stdio.h>
int main()
{
    unsigned long long n, an = 0, i;
    scanf("%llu", &n);
    unsigned long long a_1 = 1, a_2 = 1;
    for (i = 3; i <= n;i++)
    {
        an = a_1 + a_2;
        if(an>101)
            an = an - 101;
        a_2 = a_1;
        a_1 = an;
    }
    printf("%llu", an % 101);
    return 0;
}