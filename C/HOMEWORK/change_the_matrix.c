//任意给定一个n*n的矩阵，矩阵的行数与列数均为n。你的任务是通过行变换，使得矩阵每行元素的平均值按递增顺序排列。如果出现有的行平均值相同的情况，则按照原顺序输出
#include<stdio.h>
int findmin(long n[],int limit)
{
    int ans=1;
    int min=n[1];
    int i;
    for(i=1;i<=limit;i++)
    {
        if(n[i]<min)
        {
            min=n[i];
            ans=i;
        }
    }
    n[ans]=100*1000000;
    return ans;
}

int main()
{
    int n;
    scanf("%d",&n);
    int i1,i2;
    long p[n+1][n+2];
    long sum[101]={0};
    for(i1=1;i1<=n;i1++)
    {
        for(i2=1;i2<=n;i2++)
        {
            scanf("%ld",&p[i1][i2]);
            sum[i1]=sum[i1]+p[i1][i2];
        }
    }
    int order[n+1];
    int i;
    for(i=1;i<=n;i++)
    {
        order[i]=findmin(sum,n);
    }
    for(i=1;i<=n;i++)
    {
        int a=order[i];
        for(i1=1;i1<=n;i1++)
        {
            printf("%d",p[a][i1]);
            if(i1!=n)
                printf(" ");
            else if(i1==n)
                printf("\n");
        }
    }
    return 0;
}