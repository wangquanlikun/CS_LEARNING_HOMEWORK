#include<stdio.h>
int main()
{
    float i;
    int input;
    float n3,n5,n7;
    n3=n5=n7=0;
    for(i=0;;)
    {
        scanf("%d",&input);
        if(input==0)
            break;
        else
        {
            if(input%3==0&&input%5!=0&&input%7!=0)
                n3++;
            else if(input%5==0&&input%3!=0&&input%7!=0)
                n5++;
            else if(input%7==0&&input%5!=0&&input%3!=0)
                n7++;
            i++;
        }
    }
    float i1,i2,i3;
    i1=n3/i;
    i2=n5/i;
    i3=n7/i;
    printf("%.2f%%\n",i1*100);
    printf("%.2f%%\n",i2*100);
    printf("%.2f%%\n",i3*100);
    return 0;
}
