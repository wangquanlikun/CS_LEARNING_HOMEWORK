//任意给定一个字符串，字符串中包含除了空白符、换行符之外的的任意字符。你的任务是统计出现在该字符串中的各字母（即“A—Z”，“a—z”）的个数(区分大小写)。
#include<stdio.h>
int main()
{
    int a[128]={0};//数组位数为其ASCII码对应的字符，各位数据为该字符个数。初始化为0
    char input[101];//字符型数组读入字符串
    scanf("%s",input);
    int i;
    for(i=0;i<=100&&input[i]!='\0';i++)
    {
        char c=input[i];//将c的ASCII码对应a位数
        a[c]++;
    }
    char ii;
    for(ii='A';ii<='z';ii++)//ii对应ASCII码
    {
        if(a[ii]!=0)
            printf("The character %c has presented %d times.\n",ii,a[ii]);
        if(ii=='Z')
            ii='a'-1;
    }
}
