#include<stdio.h>
int main()
{
    int time,add;
    scanf("%d%d",&time,&add);
    int hour,minute;
    hour=time/100;
    minute=time-hour*100;
    int addminute=minute+add;
    int hourplus,minuteplus,hour2,minute2;
    while(addminute<0)
    {
        hour=hour-1;
        addminute=addminute+60;
    }
    hourplus=addminute/60;
    minuteplus=addminute-hourplus*60;
    hour2=hour+hourplus;
    minute2=minuteplus;
    if(hour2>24)
        hour2 = hour2 - 24;
    else if(hour2<0)
        hour2 = hour2 + 24;
    if (minute2 != 0)
        printf("%d%d",hour2,minute2);
    else if(minute2==0)
        printf("%d00",hour2);
    return 0;
}
