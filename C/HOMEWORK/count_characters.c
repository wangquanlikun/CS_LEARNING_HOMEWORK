#include<stdio.h>
int main()
{
    char cc;
    int a=0,b=0,c=0,d=0;
    while ((cc=getchar())!='\n')
    {
         if(cc>='a'&&cc<='z'||cc>='A'&&cc<='Z')
             a++;
        else if(cc==' ')
            b++;
        else if(cc>='0'&&cc<='9')
            c++;
        else
            d++;
    }
    printf("%d %d %d %d",a,b,c,d);
    return 0;
}
