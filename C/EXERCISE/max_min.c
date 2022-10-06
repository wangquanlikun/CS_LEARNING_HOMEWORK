#include<stdio.h>
int main()
{
    int a, max, min;
    scanf("%d", &a);
    max = a;
    min = a;
    do
    {
        if(a>max)
            max = a;
        if(a<min)
            min = a;
        scanf("%d", &a);
    } while (a!=0);
    printf("MAX=%d,MIN=%d", max, min);
    return 0;
}
