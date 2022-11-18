//现有一个矩阵，请你写程序求出某个数周围数字的和。
#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int ju[m+1][n+1];
    int i1,i2;
    for(i1=1;i1<=m;i1++)
    {
        for(i2=1;i2<=n;i2++)
        {
            scanf("%d",&ju[i1][i2]);
        }
    }
    int x,y;
    scanf("%d%d",&x,&y);
    int ans=0;
    for(i1=x-1;i1<=x+1;i1++)
    {
        for(i2=y-1;i2<=y+1;i2++)
        {
            if(i1>0&&i2>0&&i1<=m&&i2<=n)
                ans+=ju[i1][i2];
        }
    }
    ans-=ju[x][y];
    printf("%d",ans);
    return 0;
}