//输入一个整数，输出每个数字对应的拼音。当整数为负数时，先输出fu字
#include<stdio.h>
int main()
{
    int i=1;
    char c;
    c=getchar();
    while((c>='0'&&c<='9')||c=='-')
    {
        if(i>1)
            printf(" ");
        switch(c)
        {
            case '0':
                printf("ling");
                break;
            case '1':
                printf("yi");
                break;
            case '2':
                printf("er");
                break;
            case '3':
                printf("san");
                break;
            case '4':
                printf("si");
                break;
            case '5':
                printf("wu");
                break;
            case '6':
                printf("liu");
                break;
            case '7':
                printf("qi");
                break;
            case '8':
                printf("ba");
                break;
            case '9':
                printf("jiu");
                break;
            case '-':
                printf("fu");
                break;
        }
        i++;
        c=getchar();
    }
    return 0;
}
