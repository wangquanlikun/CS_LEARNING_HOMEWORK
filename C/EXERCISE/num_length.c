#include<stdio.h>
int main()
{
    long long input;
    int len;
    scanf("%lld", &input);
    for (len = 1;;len++)
    {
        if(input/10==0)
            break;
        else
            input = input / 10;
    }
    printf("%d", len);
    return 0;
}