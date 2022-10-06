#include<stdio.h>

int main()
{
    int a, b, c;
    int yunsuanfu;

    printf("Please import the first number\n");
    scanf("%d", &a);

    printf("Please import the second number\n");
    scanf("%d", &b);

    printf("Please select the way to calculate\t");
    printf("1 equals to +,2 equals to -,3 equals to ×,4 equals to ÷\n");
    scanf("%D", &yunsuanfu);

    printf("So,the result is:");

    if(yunsuanfu==1)
    {
        c = a + b;
        printf("%d+%d=%d\n",a,b,c);
    }

    if(yunsuanfu==2)
    {
        c = a - b;
        printf("%d-%d=%d\n",a,b,c);
    }

    if(yunsuanfu==3)
    {
        c = a * b;
        printf("%d×%d=%d\n",a,b,c);
    }

    if(yunsuanfu==4)
    {
        c = a / b;
        printf("%d÷%d=%d\n",a,b,c);
    }

    printf("\n");
    printf("OK,Hallo world!\n");

    return (0);
}
