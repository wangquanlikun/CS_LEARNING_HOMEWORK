#include<stdio.h>
double ax(double a,int x)
{
    int i;
    double ans = 1;
    for (i = 1; i <= x;i++)
    {
        ans = ans * a;
    }
    return ans;
}

double speed(int time)
{
    double speed_time;
    speed_time = 7 * ax(0.98, time);
    return speed_time;
}

int main()
{
    double s, x;
    scanf("%lf%lf", &s, &x);
    int time=0;
    double len = 0;
    for (time = 0;;time++)
    {
        if(len>=s-x)
            break;
        len = len + speed(time) * 1;
    }
    time++;
    if((len + speed(time))>s+x)
        printf("n");
    else
        printf("y");
    return 0;
}
