//设有一个nXm方格的棋盘。求出该棋盘中包含正方形与长方形（长方形中不包括正方形)的个数
#include<stdio.h>
int main()
{
    int n,m;
    int a=0,b;
    int sum=0;
    scanf("%d%d",&n,&m);
    int i,ii;
    int nn=n,mm=m;
    for(i=1;i<=n&&i<=m;i++)
    {
        a=a+nn*mm;
        nn--,mm--;
    }
    nn=n,mm=m;
    for(i=1;i<=n;i++)
    {
        for(ii=1,mm=m;ii<=m;ii++)
        {
            sum=sum+nn*mm;
            mm--;
        }
        nn--;
    }
    b=sum-a;
    printf("%d %d",a,b);
}