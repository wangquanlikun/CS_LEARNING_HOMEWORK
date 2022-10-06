#include<stdio.h>
int main()
{
    int input, p;//p is used to adjust.1=TRUE,0=FALSE
    scanf("%d", &input);
    p = 1;
    int i;
    for (i = 2; i < input;i++)
    {
        if(input%i==0)
        {
            p = 0;
            break;
        }
    }
    if(p==0)
        printf("FALSE");
    if(p==1)
        printf("TRUE");
    return 0;
}