#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i,ii;
    for(i=1;i<=n;i++)
    {
        for(ii=1;ii<=i;ii++)
        {
            printf("%d*%d=%d",ii,i,ii*i);
            if(i*ii<=9)
                printf("   ");
            else if(ii*i>=10&&ii*i<=99)
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}
