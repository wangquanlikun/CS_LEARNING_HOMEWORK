//任意给定一个n*m的矩阵，矩阵的行数为n,列数为m。你的任务是实现矩阵的转置，即行列互换
#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int i1,i2;
    int ju[n+1][m+1];
    for(i1=1;i1<=n;i1++)
    {
        for(i2=1;i2<=m;i2++)
        {
            scanf("%d",&ju[i1][i2]);
        }
    }
    for(i1=1;i1<=m;i1++)
    {
        for(i2=1;i2<=n;i2++)
        {
            printf("%d",ju[i2][i1]);
            if(i2!=n)
                printf(" ");
            else if(i2==n)
                printf("\n");
        }
    }
    return 0;
}