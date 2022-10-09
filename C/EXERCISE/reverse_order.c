#include<stdio.h>
int main()
{
    int input;
    scanf("%d",&input);
    int a,b,c;
    int cache;
    c=input%10;
    cache=input/10;
    b=cache%10;
    cache=cache/10;
    a=cache%10;
    if(c==0)
    {
        if(b==0)
            printf("%d",a);
        else
            printf("%d%d",b,a);
    }
    else
        printf("%d%d%d",c,b,a);
    return 0;
}
