#include<stdio.h>
int main()
{
    int a, b, c, d, e, f;//input six numbers to put them into rigth order
    int p = 0;//to see if it is in right order
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    do
    {
        p = 0;
        if(a>b)
        {
            int aa = a;
            a = b;
            b = aa;
            p = 1;
        }
        if(b>c)
        {
            int bb = b;
            b = c;
            c = bb;
            p = 1;
        }
        if(c>d)
        {
            int cc = c;
            c = d;
            d = cc;
            p = 1;
        }
        if(d>e)
        {
            int dd = d;
            d = e;
            e = dd;
            p = 1;
        }
        if(e>f)
        {
            int ee = e;
            e = f;
            f = ee;
            p = 1;
        }
    } while (p!=0);
    printf("%d%d%d%d%d%d", a, b, c, d, e, f);
}
