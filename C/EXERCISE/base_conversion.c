#include<stdio.h>
void converter(int, int);
int main()
{
    int i, p;
    scanf("%d%d", &i, &p);
    converter(i, p);
    return 0;
}
void converter(int in,int base)
{
    int p = 1;
    int bit;
    char c_bit;
    do
    {
        p = p * base;
    } while (p <= in);
    p = p / base;
    for (; p != 0;)
    {
        bit = in / p;
        if(bit<=9)
            printf("%d", bit);
        else if(bit>=10)
        {
            c_bit = bit - 10 + 'A';
            printf("%c", c_bit);
        }
        in = in % p;
        p = p / base;
    }
}