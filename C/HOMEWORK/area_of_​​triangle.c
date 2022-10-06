#include<stdio.h>
#include<math.h>

int main()
{
    double a, b, c;
    double s;
    double area;
    scanf("%lf%lf%lf", &a, &b, &c);

    if((a+b>c)&&(b+c>a)&&(a+c>b)&&a!=0&&b!=0&&c!=0)
    {
        s = (a + b + c) / 2;
        area = sqrt((s * (s - a) * (s - b) * (s - c)));
        printf("%.3lf", area);
    }
    else
        printf("The edges cannot make up of a triangle.");
    return 0;
}
