#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int i,n;
    int sum=0;
    int cache=a;
    for(i=1,n=1;i<=b-a+1;i++,n++,cache++)
    {
        sum=sum+cache;
        if(cache>=0&&cache<=9)
            printf("    %d",cache);
        else if((cache<0&&cache>=-9)||(cache>=10&&cache<=99))
            printf("   %d",cache);
        else if((cache<=-10&&cache>=-99)||cache==100)
            printf("  %d",cache);
        else if(cache==-100)
            printf(" %d",cache);
        if(n==5&&i<b-a+1)
        {
            printf("\n");
            n=0;
        }
    }
    printf("\nSum = %d",sum);
    return 0;
}
