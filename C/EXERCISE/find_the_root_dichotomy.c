#include<stdio.h>
#define MIN 1e-5
float f(float a3,float a2,float a1,float a0,float x)
{
    float ans=a3*x*x*x+a2*x*x+a1*x+a0;
    return ans;
}
int main()
{
    float a3,a2,a1,a0,a,b;
    float half;
    scanf("%f%f%f%f%f%f",&a3,&a2,&a1,&a0,&a,&b);
    for(;b-a>=MIN;)
    {
        if(f(a3,a2,a1,a0,a)*f(a3,a2,a1,a0,b)<0)
        {
            half=(a+b)/2;
            if(f(a3,a2,a1,a0,half)==0)
                goto end1;
            else if(f(a3,a2,a1,a0,half)*f(a3,a2,a1,a0,a)>0)
                a=half;
            else if(f(a3,a2,a1,a0,half)*f(a3,a2,a1,a0,b)>0)
                b=half;
        }
        else if(f(a3,a2,a1,a0,a)==0)
        {
            printf("%.2f",a);
            goto end2;
        }
        else if(f(a3,a2,a1,a0,b)==0)
        {
            printf("%.2f",b);
            goto end2;
        }  
    }
    if(b-a<MIN)
        half=(a+b)/2;
    end1:
    printf("%.2f",half);
    end2:
    return 0;
}