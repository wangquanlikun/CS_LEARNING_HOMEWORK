//蛇形矩阵是一个n*n的矩阵，将整数1到n*n按照蛇形的顺序装入一个 n*n 的蛇形矩阵中
//只有一行，为一个整数n，代表蛇形矩阵的阶数
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i=1;
    int p[n+1][n+1];
    int k;//定义四种状态：k=1向下走，k=2向右上方走，k=3向右走，k=4向左下角走
    
    int a=1,b=1;
    p[a][b]=i;
    k=1;
    i++;
    
    while(i<=n*n)
    {
        if(k==1)
        {
            a=a+1;
            p[a][b]=i;
            if(b==1)
                k=2;
            else if(b==n)
                k=4;
        }
        else if(k==2)
        {
            a=a-1;
            b=b+1;
            p[a][b]=i;
            if(b!=n&&a==1)
                k=3;
            else if(b==n)
                k=1;
            else
                k=2;
        }
        else if(k==3)
        {
            b=b+1;
            p[a][b]=i;
            if(a==1)
                k=4;
            else if(a==n)
                k=2;
        }
        else if(k==4)
        {
            a=a+1;
            b=b-1;
            p[a][b]=i;
            if(a!=n&&b==1)
                k=1;
            else if(a==n)
                k=3;
            else
                k=4;
        }
        i=i+1;
    }
    for(a=1;a<=n;a++)
    {
        for(b=1;b<=n;b++)
        {
            printf("%d",p[a][b]);
            if(b!=n)
                printf(" ");
            else if(b==n)
                printf("\n");
        }
    }
    return 0;
}