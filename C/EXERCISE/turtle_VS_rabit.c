//乌龟与兔子进行赛跑，跑场是一个矩型跑道，跑道边可以随地进行休息。乌龟每分钟可以前进3米，兔子每分钟前进9米；兔子嫌乌龟跑得慢，觉得肯定能跑赢乌龟，于是，每跑10分钟回头看一下乌龟，若发现自己超过乌龟，就在路边休息，每次休息30分钟，否则继续跑10分钟；而乌龟非常努力，一直跑，不休息。假定乌龟与兔子在同一起点同一时刻开始起跑，请问T分钟后乌龟和兔子谁跑得快？
#include<stdio.h>
#define TURTLE 3
#define RABIT 9
int main()
{
    int turtle=0,rabit=0;
    int time;
    scanf("%d",&time);
    int i;
    int p=1;//if p=0,the rabit won't run
    int countdown=0;
    for(i=1;i<=time;i++)
    {
        turtle=turtle+TURTLE;
        if((i-1)%10==0&&i>=10)
        {
            if(rabit>turtle&&p==1)
            {
                p=0;
                countdown=-30;
            }
        }
        if(p==1)
            rabit=rabit+RABIT;
        else if(p==0)
            countdown++;
        if(countdown==0)
            p=1;
    }
    if(turtle>rabit)
        printf("@_@ %d",turtle);
    if(turtle<rabit)
        printf("^_^ %d",rabit);
    if(turtle==rabit)
        printf("-_- %d",turtle);
    return 0;
}