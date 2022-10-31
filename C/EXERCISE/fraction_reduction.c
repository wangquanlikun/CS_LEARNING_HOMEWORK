#include<stdio.h>
int gcd(int,int);
int main()
{
    int a,b;
    scanf("%d/%d",&a,&b);
    int i;
    i=gcd(a, b);
    a=a/i;
    b=b/i;
    printf("%d/%d",a,b);
    return 0;
}

int gcd(int a,int b)
{
    int cache;
    if(a<b)
    {
        cache=a;
        a=b;
        b=cache;
    }
    int m, n;
    m = a, n = b;
    int ans1;
    int adjust = 0;
    do
    {
        int remain = m % n;
        if(remain==0)
            {
                adjust = 1;
                ans1 = n;
            }
        else
        m = n, n = remain;
    } while (adjust == 0);
    return ans1;
}