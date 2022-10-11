#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int a,b,c;
    for(a=0;a<=m&&a<=n/2;a++)
    {
        for(b=0;b<=m&&b<=n/4;b++)
        {
            for(c=0;c<=m&&c<=n/6;c++)
            {
                if((a+b+c==m)&&(2*a+4*b+6*c==n))
                {
                    printf("%d %d %d\n",a,b,c);
                }
            }
        }
    }
    return 0;
}
