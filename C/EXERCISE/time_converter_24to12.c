#include<stdio.h>
int main()
{
    int hour,minute;
    scanf("%d:%d",&hour,&minute);
    if(hour>=0&&hour<12)
        printf("%d:%d AM",hour,minute);
    else if(hour==12)
        printf("%d:%d PM",hour,minute);
    else if(hour>12&&hour<24)
        printf("%d:%d PM",hour-12,minute);
    else if(hour>=24)
        printf("%d:%d AM",hour-24,minute);
    return 0;
}
