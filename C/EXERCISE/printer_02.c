/*
example:
2222
2112
2112
2222

33333
32223
32123
32223
33333
*/

#include<stdio.h>
int main()
{
    int inputnum;
    scanf("%d",&inputnum);
    int i1,i2,i3;
    for(i1=(inputnum/2)*2,i2=inputnum;i1>=1;i1--,i2--)
    {
        if(inputnum%2==0)
        {
            for(i3=inputnum;i3>=1;i3--)
            {
                if(i3>i2)
                    printf("%d",i3);
                else
                    printf("%d",i2);
            }
            for(i3=1;i3<=inputnum;i3++)
            {
                if(i3>i2)
                    printf("%d",i3);
                else
                    printf("%d",i2);
            }
            printf("\n");
        }
        else if(inputnum%2==1)
        {
            for(i3=inputnum;i3>=1;i3--)
            {
                if(i3>i2)
                    printf("%d",i3);
                else
                    printf("%d",i2);
            }
            for(i3=2;i3<=inputnum;i3++)
            {
                if(i3>i2)
                    printf("%d",i3);
                else
                    printf("%d",i2);
            }
            printf("\n");
        }
    }
    
    if(inputnum%2==1)
    {
        for(i3=inputnum;i3>=1;i3--)
            printf("%d",i3);
        for(i3=2;i3<=inputnum;i3++)
            printf("%d",i3);
        printf("\n");
    }

    int k;
    if(inputnum%2==0)
        k=1;
    else
        k=2;
    
    for(i1=1,i2=k;i1<=(inputnum/2)*2;i1++,i2++)
    {
        if(inputnum%2==0)
        {
            for(i3=inputnum;i3>=1;i3--)
            {
                if(i3>i2)
                    printf("%d",i3);
                else
                    printf("%d",i2);
            }
            for(i3=1;i3<=inputnum;i3++)
            {
                if(i3>i2)
                    printf("%d",i3);
                else
                    printf("%d",i2);
            }
            printf("\n");
        }
        else if(inputnum%2==1)
        {
            for(i3=inputnum;i3>=1;i3--)
            {
                if(i3>i2)
                    printf("%d",i3);
                else
                    printf("%d",i2);
            }
            for(i3=2;i3<=inputnum;i3++)
            {
                if(i3>i2)
                    printf("%d",i3);
                else
                    printf("%d",i2);
            }
            printf("\n");
        }
    }
}
