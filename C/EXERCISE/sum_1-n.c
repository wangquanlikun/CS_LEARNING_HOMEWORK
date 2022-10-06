#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a, sum;
    sum = 0;
    for (a = 1; a <= n;a++)
    {
        sum = sum + a;
    }
    printf("The sum is %d", sum);
    return 0;

}
