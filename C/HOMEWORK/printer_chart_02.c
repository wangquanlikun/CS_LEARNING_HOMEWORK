#include<stdio.h>
int main()
{
    int t,l,c,n;
    scanf("%d",&t);
    int i;//route time
    int p,q,b,d;//route time
    for(i=1;i<=t;i++)
    {
        scanf("%d%d%d",&l,&c,&n);
        printf("*");
        for(p=1;p<=c*n+c;p++)
            printf("*");
        printf("\n");
        for(b=1;b<=l;b++)
        {
            for(q=1;q<=3;q++)
            {
                printf("*");
                for(p=1;p<=c;p++)
                {
                    for(d=1;d<=n;d++)
                    {
                        printf(".");
                    }
                    printf("*");
                }
                printf("\n");
            }
            printf("*");
            for(p=1;p<=c*n+c;p++)
                printf("*");
            printf("\n");
        }
    }
    return 0;
}
