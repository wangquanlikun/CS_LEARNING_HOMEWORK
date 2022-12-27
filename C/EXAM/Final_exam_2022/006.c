#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int light[m+5][n+5];
    int i1,i2;
    for(i1=1;i1<=m;i1++)
    {
        for(i2=1;i2<=n;i2++)
            scanf("%d",&light[i1][i2]);
    }
    int k,i3,x,y;
    scanf("%d",&k);
    for(i3=0;i3<k;i3++)
    {
        scanf("%d%d",&x,&y);
        if(light[x][y]==0)
            light[x][y]=1;
        else
            light[x][y]=0;
        if(light[x+1][y+1]==0)
            light[x+1][y+1]=1;
        else
            light[x+1][y+1]=0;
        if(light[x-1][y+1]==0)
            light[x-1][y+1]=1;
        else
            light[x-1][y+1]=0;
        if(light[x+1][y-1]==0)
            light[x+1][y-1]=1;
        else
            light[x+1][y-1]=0;
        if(light[x-1][y-1]==0)
            light[x-1][y-1]=1;
        else
            light[x-1][y-1]=0;
    }
    for(i1=1;i1<=m;i1++)
    {
        for(i2=1;i2<=n;i2++)
        {
            printf("%d",light[i1][i2]);
            if(i2!=n)
                printf(" ");
            else if(i2==n)
                printf("\n");
        }
    }
    return 0;
}