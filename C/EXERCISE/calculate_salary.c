#include<stdio.h>
int main()
{
    int year,time;
    int basic;
    float money;
    scanf("%d%d",&year,&time);
    if(year>=5)//老员工
        basic=50;
    else if(year<5)//新员工
        basic=30;
    if(time<=40)
        money=basic*time;
    else if(time>40)
        money=40*basic+1.5*basic*(time-40);
    printf("%.2f",money);
    return 0;
}
