#include<stdio.h>
#include<math.h>
int main()
{
    int a, b, c, i, count = 0, adjust = 0;
    scanf("%d%d%d", &a, &b, &c);
    for (i = a; i <= b;i++)
    {
        int p = 1, sum=0;
        for (p = 1; p < i;p++)
        {
            if(i%p==0)
                sum = sum + p;
        }
        if(i==1)
            sum = 0;
        if(count>=5&&fabs(i-sum)<=c)
        {
            printf("\n");
            count = count - 5;
        }        
        if(count>=1&&fabs(i-sum)<=c)
            printf("\t");
        if(fabs(i-sum)<=c)
        {
            count++;
            adjust++;
            printf("%d", i);
        }
    }
    if(count==0)
        printf("There is no proper number in the interval.");
    return 0;
}