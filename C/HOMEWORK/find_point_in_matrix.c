//任意给定一个n*m的矩阵，矩阵的行数为n,列数为m。你的任务是寻找该矩阵的鞍点。一个矩阵的鞍点即该位置上的元素在所在行上最大，在所在列上最小。有的矩阵也可能没有鞍点。
#include<stdio.h>
int findmax(int ju[][101],int n,int m,int p)
{
    int max=ju[n][1];
    int m_max=1;
    int i;
    for(i=1;i<=m;i++)
    {
        if(ju[n][i]>max)
        {
            max=ju[n][i];
            m_max=i;
        }
    }
    if(p==2)
        return m_max;
    else if(p==1)
        return max;
}

int findmin(int ju[][101],int n,int m,int p)
{
    int min=ju[1][m];
    int n_min=1;
    int i;
    for(i=1;i<=n;i++)
    {
        if(ju[i][m]<min)
        {
            min=ju[i][m];
            n_min=i;
        }
    }
    if(p==2)
        return n_min;
    else if(p==1)
        return min;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int ju[101][101];
    int i1,i2;
    for(i1=1;i1<=n;i1++)
    {
        for(i2=1;i2<=m;i2++)
        {
            scanf("%d",&ju[i1][i2]);
        }
    }
    int p=0;
    for(i1=1;i1<=n;i1++)
    {
        int point1=findmax(ju,i1,m,1);
        int m_max=findmax(ju,i1,m,2);
        int point2=findmin(ju,n,m_max,1);
        int n_min=findmin(ju,n,m_max,2);
        if(point1==point2)
        {
            p=1;
            printf("The saddle point is (%d,%d)=%d.",n_min-1,m_max-1,point1);
            return 0;
        }
    }
    if(p==0)
        printf("There is no saddle point in the matrix.");
    return 0;
}