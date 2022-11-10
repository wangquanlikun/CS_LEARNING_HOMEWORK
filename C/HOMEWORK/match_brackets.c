//任意给定一个字符串，字符串中包含除了空白符、换行符之外的任意字符。你的任务是检测字符串中的圆括号是否配对，即“(”与“)”是否配对。
#include<stdio.h>
int main()
{
    int p = 0;//p=1 equals to yes
    char c;
    int a = 0, b = 0;
    int i;
    for(i=1;i<=100;i++)
    {
        if(c=='(')
            a++;
        if(c==')')
            b++;
        if(a<b)
        {
            printf("parentheses do not match!");
            return 0;
        }
    }
    if(a==b)
        printf("parentheses match!");
    else if(a!=b)
        printf("parentheses do not match!");
    return 0;
}