//最高气温一直上升的最长连续天数
#include<stdio.h>
int main()
{
    long long N;
    scanf("%lld", &N);
    long long i;
    long long day=1, day_max=1;
    long long p;
    scanf("%lld", &p);
    long long p_cache = p;
    for (i = 2; i <= N;i++)
    {
        scanf("%lld", &p);
        if(p>p_cache)
            day++;
        if(p<=p_cache)
            day = 1;
        if(day>day_max)
            day_max = day;
        p_cache = p;
    }
    printf("%lld", day_max);
    return 0;
}
