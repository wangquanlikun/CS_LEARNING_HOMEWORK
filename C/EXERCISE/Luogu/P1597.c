#include<stdio.h>
int main()
{
    char aa[256+1]={'\0'};
    int i;
    int a = 0, b = 0, c = 0;
    for (i = 1; i <= 255;i++)
    {
        scanf("%c", &aa[i]);
        if(aa[i]=='\n')
            break;
    }
    for (i = 1; i <= 255;i+=5)
    {
        if(aa[i]=='\0')
            break;
        if(aa[i+3]=='a')
        {
        if(aa[i]=='a')
            a = a;
        else if(aa[i]=='b')
            b = a;
        else if(aa[i]=='c')
            c = a;
        }
        else if(aa[i+3]=='b')
        {
        if(aa[i]=='a')
            a = b;
        else if(aa[i]=='b')
            b = b;
        else if(aa[i]=='c')
            c = b;
        }
        else if(aa[i+3]=='c')
        {
        if(aa[i]=='a')
            a = c;
        else if(aa[i]=='b')
            b = c;
        else if(aa[i]=='c')
            c = c;
        }
        else
        {
        int y_num = aa[i+3] - '0';
        if(aa[i]=='a')
            a = y_num;
        else if(aa[i]=='b')
            b = y_num;
        else if(aa[i]=='c')
            c = y_num;
        }
    }
    printf("%d %d %d", a, b, c);
}
