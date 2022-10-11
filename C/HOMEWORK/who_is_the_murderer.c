#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i;//i是凶手的号码
    int t = 0; //说真话的人数，要与n相等
    int a[6],b[6];
    int p;
    for (p = 1; p <= 5;p++)
    {
        scanf("%d%d", &a[p], &b[p]);
    }
    for (i = 5; i >= 5 && i <= 9;i++)//从5开始轮查，假设此时i是凶手
    {
        t = 0;//注意要让其初始化
        int q;
        for (q = 1; q <= 5;q++)
        {
            if((i==a[q]&&b[q]==1)||(i!=a[q]&&b[q]==0))
            {
                t = t + 1;
            }
        }
        if(t==n)
        {
            printf("%d", i);
            break;
        }
    }
    return 0;
}
