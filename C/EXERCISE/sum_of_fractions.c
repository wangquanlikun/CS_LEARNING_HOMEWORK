//计算两个有理数（分数形式）的和
#include<stdio.h>
int GCD(int,int);
long long LCM(long long,long long);
void simplify_pr(long long,long long);

int main()
{
    int a1,b1,a2,b2;
    scanf("%d/%d %d/%d",&a1,&b1,&a2,&b2);
    int a,b;
    a=a2*(LCM(b1,b2)/b2)+a1*(LCM(b1,b2)/b1);
    b=LCM(b1,b2);
    simplify_pr(a,b);
    return 0;
}

int GCD(int a,int b)
{
    int ans;
    int cache;
    if(a<b)
    {
        cache=a;
        a=b;
        b=cache;
    }
    int m, n;
    m = a, n = b;
    int adjust = 0;
    do
    {
        int remain = m % n;
        if(remain==0)
            {
                adjust = 1;
                ans = n;
            }
        else
        m = n, n = remain;
    } while (adjust == 0);
    return ans;
}

long long LCM(long long a,long long b)
{
    long long ans;
    ans=(a/GCD(a,b))*b;
    return ans;
}

void simplify_pr(long long a,long long b)
{
    if(a==0)
        printf("0");
    else if(a!=0)
    {
        int gcd=GCD(a,b);
        if(a!=b)
        {
            if(b/gcd!=1)
                printf("%lld/%lld",a/gcd,b/gcd);
            else if(b/gcd==1)
                printf("%lld",a/gcd);
        }
        else if(a==b)
            printf("1");
    }
}
