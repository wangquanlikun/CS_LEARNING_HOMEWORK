#include<stdio.h>
#include <ctype.h>
int main()
{
    char a[201 * 201];
    int pr[200 * 200];
    int max = 201 * 201;
    int i, max_len, ii = 1;
    int num_0=0, num_1=0;
    int p = 0;
    for (i = 1; i < max;i++)
    {
        scanf("%c", &a[i]);
        if(isspace(a[i])&&p==0)
        {
            max_len = i - 1;
            max = i * (i + 1);
            p = 1;
        }
        if(a[i]=='0')
        {
            if(num_0==0&&num_1!=0)
            {
                pr[ii] = num_1;
                ii++;
            }
            num_1 = 0;
            num_0++;
        }
        else if(a[i]=='1')
        {
            if(i==1&&a[1]=='1')
            {
                pr[ii] = 0;
                ii++;
            }
            if(num_1==0&&num_0!=0)
            {
                pr[ii] = num_0;
                ii++;
            }
            num_0 = 0;
            num_1++;
        }
    }
    if(num_1==0)
        pr[ii] = num_0;
    else if(num_0==0)
        pr[ii] = num_1;
    printf("%d ", max_len);
    for (i = 1; i <= ii;i++)
    {
        printf("%d ", pr[i]);
    }
    return 0;
}
