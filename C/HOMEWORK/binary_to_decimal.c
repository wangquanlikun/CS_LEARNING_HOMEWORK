#include<stdio.h>
int main()
{
    int input;
    scanf("%d", &input);
    int inputadjust = input, len;
    for (len = 1;;len++)
    {
        if(inputadjust/10==0)
            break;
        else
            inputadjust = inputadjust / 10;
    }
    int i, ans = 0, time = 1, a;
    for (i = 1; i <= len;i++)
    {
        a = input % 10;
        input = input / 10;
        ans = ans + a * time;
        time = time * 2;
    }
    printf("%d", ans);
    return 0;
}