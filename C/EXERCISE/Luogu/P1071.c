#include<stdio.h>
#include<string.h>
int main()
{
    char a[101], b[101], c[101];
    scanf("%s%s", a, b);
    scanf("%s", c);
    char rule[128] = {'\0'};
    char re_rule[128] = {'\0'};
    int i, len;
    len = strlen(a);
    int adjust = 0;
    for (i = 0; i < len;i++)
    {
        if(rule[a[i]]!='\0'&&rule[a[i]]!=b[i])
        {
            printf("Failed");
            return 0;
        }
        else if(re_rule[b[i]]!='\0'&&re_rule[b[i]]!=a[i])
        {
            printf("Failed");
            return 0;
        }
        else if(rule[a[i]]=='\0'&&re_rule[b[i]]=='\0')
        {
            adjust += 1;
            rule[a[i]] = b[i];
            re_rule[b[i]] = a[i];
        }
        else
        {
            rule[a[i]] = b[i];
            re_rule[b[i]] = a[i];
        }
            
    }
    if(adjust!=26)
    {
        printf("Failed");
        return 0;
    }
    len = strlen(c);
    for (i = 0; i < len;i++)
        printf("%c", rule[c[i]]);
    return 0;
}
