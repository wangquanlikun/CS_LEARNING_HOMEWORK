#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    int i1,i2,i3;
    int time=0;
    for(i1=a;i1<=a+3;i1++)
    {
        for(i2=a;i2<=a+3;i2++)
        {
            if(i1!=i2)
            {
                for(i3=a;i3<=a+3;i3++)
                {
                    if(i3!=i1&&i3!=i2)
                    {
                        time++;
                        printf("%d%d%d",i1,i2,i3);
                        if(time>=1&&time<6)
                            printf(" ");
                        else if(time==6)
                        {
                            printf("\n");
                            time=0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
