#include<stdio.h>
int main()
{
    int n,u,d;
    scanf("%d%d%d",&n,&u,&d);
    int up=0;
    int time=0;
    for(time=0;;)
    {
        up=up+u;
        time++;
        if(up>=n)
            goto end1;
        else
        {
            time++;
            up=up-d;
        }
    }
    end1:
    printf("%d",time);
    return 0;
}
