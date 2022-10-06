#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i,p,q; //i是第几行，p是行里打几个*，q是行里打几个空格
    for(i=1;i<=n;i++)
    {
        for(q=n-i;q>0;q--)
            printf(" ");
        for(p=1;p<=2*i-1;p++)
            printf("*");
        printf("\n");
    }
    for(i=1;i<=n-1;i++)
    {
        for(q=1;q<=i;q++)
            printf(" ");
        for(p=2*(n-i)-1;p>0;p--)
            printf("*");
        printf("\n");
    }
    return 0;
}