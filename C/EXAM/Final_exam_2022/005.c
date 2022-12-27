#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int num[n];
    int p=0;
    for(i=0;i<n;i++)
        scanf("%d",&num[i]);
    for(i=0;i<n;i++)
    {
        if(num[i]%3==0)
        {
            printf("%d",num[i]);
            p++;
            if(p!=n)
                printf(" ");
            else if(p==n)
                printf("\n");
        }
    }
    for(i=0;i<n;i++)
    {
        if(num[i]%3==1)
        {
            printf("%d",num[i]);
            p++;
            if(p!=n)
                printf(" ");
            else if(p==n)
                printf("\n");
        }
    }
    for(i=0;i<n;i++)
    {
        if(num[i]%3==2)
        {
            printf("%d",num[i]);
            p++;
            if(p!=n)
                printf(" ");
            else if(p==n)
                printf("\n");
        }
    }
    return 0;
}