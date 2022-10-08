#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    int input,min,max;
    int sum=0;
    scanf("%d",&input);
    sum=sum+input;
    min=input;
    max=input;
    for(i=2;i<=n;i++)
    {
        scanf("%d",&input);
        sum=sum+input;
        if(input>max)
            max=input;
        if(input<min)
            min=input;
    }
    printf("%d %d %d",sum,max,min);
    return 0;
}
