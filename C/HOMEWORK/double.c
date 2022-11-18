//有若干个互不相同的正整数，你的任务是计算这些数里面有多少个数对满足：数对中一个数是另一个数的两倍。
#include<stdio.h>
int main()
{
    int num[1000];
    scanf("%d",&num[1]);
    int a=num[1];
    int i=2;
    while(a!=0)
    {
        scanf("%d",&num[i]);
        a=num[i];
        i++;
    }
    i=i-2;
    int ans=0;
    int i1,i2;
    for(i1=1;i1<=i;i1++)
    {
        for(i2=i1;i2<=i;i2++)
        {
            if(num[i2]==2*num[i1]||num[i1]==2*num[i2])
                ans++;
        }
    }
    printf("%d",ans);
}