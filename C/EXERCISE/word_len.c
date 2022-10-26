#include<stdio.h>
int main()
{
    char c;
    int time = 0, len = 0, spacelen = 0;
    int p = 0;
    for (; p == 0;)
    {
        scanf("%c", &c);
        if(c=='.')
        {
            p = 1;
            goto lable1;
            lable2:
            break;
        }
        if(c!=' ')
        {
            len++;
            spacelen = 0;
        }
        if(c==' ')
        {
            lable1:
            if(time>0&&spacelen==0&&len!=0)
                printf(" ");
            if(spacelen==0&&len!=0)
            {
                printf("%d", len);
                len = 0;
                time++;
            }
            spacelen++;
            if(c=='.')
                goto lable2;
        }
    }
    return 0;
}