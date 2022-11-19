#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[4][3];
    int i1, i2;
    for (i1 = 1; i1 <= 3;i1++)
    {
        for (i2 = 1; i2 <= 2;i2++)
        {
            scanf("%d", &a[i1][i2]);
        }
    }
    int money[4];
    for (i1 = 1; i1 <= 3;i1++)
    {
        int num = n / a[i1][1];
        if((n%a[i1][1])!=0)
            num += 1;
        money[i1] = num * a[i1][2];
    }
    int min = money[1];
    for (i1 = 1; i1 <= 3;i1++)
    {
        if(money[i1]<min)
            min = money[i1];
    }
    printf("%d", min);
    return 0;
}
