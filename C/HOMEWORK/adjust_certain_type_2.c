#include<stdio.h>
long long mi(int x,int n)
{
    int ii;
    long long ans1 = 1;
    for (ii = 1; ii <= n;ii++)
    {
        ans1 = ans1 * x;
    }
    return (ans1);
}
int main()
{
    int input;
    scanf("%d",&input);
    int inputadjust = input;
    int i;
    int len;
    for (len = 1;;len++)
    {
        if(inputadjust/10==0)
            break;
        else
            inputadjust = inputadjust / 10;
    }
    int a,b;
    int lenlen=len;
    int p=1;
    for(i=1;i<=len/2;i++)
    {
        a=input%10;
        input=input/10;
        b=input/mi(10,lenlen-2);
        input=input%mi(10,lenlen-2);
        lenlen=lenlen-2;
        if(a!=b)
        {
            p=0;
            break;
        }
    }
    if(p==1)
        printf("Yes");
    else if(p==0)
        printf("No");
    return 0;
}