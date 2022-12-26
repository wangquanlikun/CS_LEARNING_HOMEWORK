#include<stdio.h>
#include<string.h>
int main()
{
    char k[101], c[1001];
    scanf("%s%s", k, c);
    int len, k_len;
    k_len = strlen(k);
    len = strlen(c);
    int i1, i2;
    for (i1 = 0, i2 = 0; i2 < len;i2++)
    {
        int output;
        if(k[i1]>='a'&&k[i1]<='z')
            k[i1] -= 'a'-'A';
        output = c[i2] - (k[i1] - 'A');
        if(c[i2]>='a'&&c[i2]<='z')
        {
            if(output<'a')
                output += 26;
        }
        else
        {
            if(output<'A')
                output += 26;
        }
        printf("%c", output);
        if(i1==k_len-1)
            i1 = 0;
        else
            i1++;
    }
    return 0;
}
