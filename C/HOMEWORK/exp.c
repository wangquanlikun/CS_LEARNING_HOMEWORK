#include<stdio.h>
#include<math.h>
int main()
{
    double x;
    scanf("%lf",&x);
    double sum=0;
    double an=1;
    int p=0;
    int i;
    for(i=1;p==0;i++)
    {
        sum=sum+an;
        an=an*x/i;
        if(fabs(an)<1e-8)
        {
            p = 1;
        }
    }
    printf("%.4lf",sum);
    return 0;
}