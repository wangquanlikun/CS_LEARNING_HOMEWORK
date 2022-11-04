//计算N个有理数的平均值.给出N个分数形式的有理数
#include<stdio.h>
int GCD(int,int);
long long LCM(long long,long long);
void simplify_pr(long long,long long);

int main()
{
    int N;
    scanf("%d",&N);
    int i;
    int a,b;
    long long a_sum=0,b_sum=1;
    int cache;
    for(i=1;i<=N;i++)
    {
        scanf("%d/%d",&a,&b);
        if(a>=0)
        {
            a_sum=a_sum*(LCM(b,b_sum)/b_sum)+a*(LCM(b,b_sum)/b);
            b_sum=LCM(b,b_sum);
        }
        else if(a<0)
        {
            a=-a;
            a_sum=a_sum*(LCM(b,b_sum)/b_sum)-a*(LCM(b,b_sum)/b);
            b_sum=LCM(b,b_sum);
        }
        if(a_sum!=0)
        {
            cache=GCD(a_sum,b_sum);
            a_sum=a_sum/cache;
            b_sum=b_sum/cache;
        }
        
    }
    simplify_pr(a_sum,b_sum*N);
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