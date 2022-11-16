#include<stdio.h>
#include<math.h>
int main()
{
    int a;
    scanf("%d",&a);
    int input[a+1];
    int i;
    for(i=1;i<=a;i++)
        scanf("%d",&input[i]);
    int checkpause[a];
    for(i=1;i<=a-1;i++)
        checkpause[i]=0;
    for(i=1;i<=a-1;i++)
    {
        int pause=fabs(input[i+1]-input[i]);
        if(fabs(pause)<=a)
            checkpause[pause]=1;
    }
    int p=1;
    for(i=1;i<=a-1;i++)
    {
        if(checkpause[i]==0)
        p=0;
    }
    if(p==1)
        printf("Jolly");
    else if(p==0)
        printf("Not jolly");
    return 0;
}
