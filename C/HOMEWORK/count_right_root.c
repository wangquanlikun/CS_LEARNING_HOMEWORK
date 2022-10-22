#include<stdio.h>
#define MAX 1000
int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int x, y, count;
    for (x = 0; x <= MAX;x++)
    {
        for (y = 0; y <= MAX;y++)
        {
            if(a*x+b*y==c)
            {
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}