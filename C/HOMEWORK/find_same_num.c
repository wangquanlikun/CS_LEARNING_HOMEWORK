//有n个互不相同的整数，存储在数组中。在这n个整数中查找m个整数，如果存在，则打印出与之相邻的整数；否则就显示无此数
#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d",&n);
    int num[n+1];
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
    }
    scanf("%d",&m);
    int testnum[m+1];
    for(i=1;i<=m;i++)
    {
        int p = 0;
        scanf("%d",&testnum[i]);
        int ii;
        for(ii=1;ii<=n;ii++)
        {
            if(testnum[i]==num[ii])
            {
                if(ii==1&&n!=1)
                    printf("%d",num[ii+1]);
                else if(ii==n&&n!=1)
                    printf("%d",num[ii-1]);
                else if(n==1)
                    printf("NULL");
                else
                    printf("%d %d",num[ii-1],num[ii+1]);
                p = 1;
            }
        }
        if(p==0)
            printf("NULL");
        printf("\n");
    }
    return 0;
}