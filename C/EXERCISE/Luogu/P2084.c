#include<stdio.h>
#include<string.h>
int main()
{
    int m;
    char bit[1005];
    scanf("%d %s", &m, bit);
    int i;
    int numlen = strlen(bit);
    for (i = 0; i <= numlen - 1; i++)
    {
        if(i!=0&&bit[i]!='0')
            printf("+");
        if(bit[i]!='0')
            printf("%c*%d^%d", bit[i], m, (numlen - i) - 1);
    }
    return 0;
}
