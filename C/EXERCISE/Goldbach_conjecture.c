#include<stdio.h>
#define MAX 200
int isPrim(int);
int main()
{
    int i, i2;
    int p = 0;
    for (i = 4; i <= MAX;i=i+2)
    {
        for (i2 = 2; i2 <= i / 2; i2++)
        {
            if(isPrim(i2)==1&&isPrim(i-i2)==1)
            {
                p = 1;
            }
            if(p==1)
            {
                printf("%d=%d+%d\n", i, i2, i - i2);
            }
            p = 0;
        }
    }
    return 0;
}
int isPrim(int x)
{
    int i, p = 1;
    for (i = 2; i < x;i++)
    {
        if(x%i==0)
        {
            p = 0;
            break;
        }
    }
    if(x==1)
        p = 0;
    return p;
}