#include<stdio.h>
int main()
{
    int k;
    scanf("%d", &k);
    int i;
    double sn=0;
    for (i = 1;sn<=k;i++)
    {
        double ii = i;
        sn = sn + 1 / ii;
        if(sn>k)
            break;
    }
    printf("%d", i);
    return 0;
}
