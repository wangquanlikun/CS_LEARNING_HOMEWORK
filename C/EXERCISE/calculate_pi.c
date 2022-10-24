#include<stdio.h>
int main()
{
    double input,an=1,sum=1;
    scanf("%lf",&input);
    int i=1;
    do
    {
        an=an*i/(2*i+1);
        i=i+1;
        sum=sum+an;
    }while(an>=input);
    printf("%.6lf",2*sum);
    return 0;
}
