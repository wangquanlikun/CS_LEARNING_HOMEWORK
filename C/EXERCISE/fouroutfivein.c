#include<stdio.h>

int main()
{
    float inputnum;
    float outputnum;

    scanf("%f", &inputnum);

    if(inputnum>=0)
    {
        int a = inputnum;
        float b = inputnum - a;
    
        if(b<0.5)
        {
            outputnum = a;
        }
        else
        {
            outputnum = a + 1;
        }
    }
    else
    {
        int a = inputnum;
        float b = a - inputnum;

        if(b<0.5)
        {
            outputnum = a;
        }
        else
        {
            outputnum = a - 1;
        }
    }
    printf("%.1f", outputnum);

    return (0);
}