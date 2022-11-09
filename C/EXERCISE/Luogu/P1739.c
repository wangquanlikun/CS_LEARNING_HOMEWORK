#include<stdio.h>
int main()
{
    int p = 0;//p=1 equals to yes
    char c;
    int a = 0, b = 0;
    while((c=getchar())!='@')
    {
        if(c=='(')
            a++;
        if(c==')')
            b++;
        if(a<b)
        {
            printf("NO");
            return 0;
        }
    }
    if(a==b)
        printf("YES");
    else if(a!=b)
        printf("NO");
    return 0;
}
