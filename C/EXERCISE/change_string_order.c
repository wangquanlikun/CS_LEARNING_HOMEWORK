//输入一个字符串和一个非负整数N，要求将字符串循环左移N次
#include<stdio.h>
int main()
{
    char c[101],getc;
    int i=1;
    while((getc=getchar())!='\n')
    {
        if(getc=='\n')
            break;
        c[i]=getc;
        i++;
    }
    i=i-1;
    int n;
    scanf("%d",&n);
    int i1;
    for(i1=1;i1<=n;i1++)
    {
        int i2;
        char cache=c[1];
        for(i2=1;i2<=i;i2++)
        {
            if(i2<i)
                c[i2]=c[i2+1];
            else if(i2==i)
                c[i2]=cache;
        }
    }
    int i2;
    for(i2=1;i2<=i;i2++)
    {
        printf("%c",c[i2]);
    }
    return 0;
}
