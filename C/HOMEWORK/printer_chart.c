#include<stdio.h>
int main()
{
    int a,b;//行数，列数
    scanf("%d%d",&b,&a);
    int aa,bb;
    printf("|");
    for(aa=1;aa<=a;aa++)
    {
        printf("*****|");
    }
    printf("\n");
    for(bb=1;bb<=b;bb++)
    {
        printf("|");
        for(aa=1;aa<=a;aa++)
        {
            printf("  |  |");
        }
        printf("\n");
        printf("|");
        for(aa=1;aa<=a;aa++)
        {
            printf("--+--|");
        }
        printf("\n");
        printf("|");
        for(aa=1;aa<=a;aa++)
        {
            printf("  |  |");
        }
        printf("\n");
        printf("|");
        for(aa=1;aa<=a;aa++)
        {
            printf("*****|");
        }
        printf("\n");
    }
    return 0;
}
