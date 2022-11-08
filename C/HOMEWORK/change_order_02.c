//已知一个长度为n的整数数组，在保证原顺序的前提下，将该数组中所有的偶数放到所有的奇数之前，存到一个新数组中，并将新数组输出
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int num[n+1],ans[n+1];
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
    }
    int ii=1;
    for(i=1;i<=n;i++)
    {
        if(num[i]%2==0)
        {
            ans[ii]=num[i];
            ii++;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(num[i]%2!=0)
        {
            ans[ii]=num[i];
            ii++;
        }
    }
    for(ii=1;ii<=n;ii++)
    {
        if(ii<n)
            printf("%d ",ans[ii]);
        if(ii==n)
            printf("%d\n",ans[ii]);
    }
    return 0;
}