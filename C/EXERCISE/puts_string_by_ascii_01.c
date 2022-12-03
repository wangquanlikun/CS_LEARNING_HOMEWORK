//根据字符串整体ASCII大小进行比较。虽然是因为理解错误题意造成的“小”问题
#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    getchar();//读取缓冲区的回车换行符
    char str[100000]={'\0'};
    int n_times;
    char *n_loc[n];
    int ascii_num[n];
    int i;
    int p=0;
    for(n_times=0,i=0;n_times<n&&i<100000;i++)
    {
        scanf("%c",&str[i]);
        if(str[i]=='\n')
        {
            n_times++;
            if(n_times==n)
            {
                str[i]='\0';
                break;
            }
            p=1;
            str[i]='\0';
            goto lab1;
        }
        if(p==1||i==0)
        {
            p=0;
            n_loc[n_times]=&str[i];
            ascii_num[n_times]=str[i];
        }
        if(p==0&&n_loc[n_times]!=&str[i])
        {
            ascii_num[n_times]+=str[i];
        }
        lab1:
        ;
    }
    int order[n];
    int i1;
    for(i1=0;i1<n;i1++)
    {
        order[i1]=0;
        int i2;
        for(i2=0;i2<n;i2++)
        {
            if(ascii_num[order[i1]]>ascii_num[i2])
            {
                order[i1]=i2;
            }
        }
        ascii_num[order[i1]]=100000*127;
    }
    for(i=0;i<n;i++)
    {
        puts(n_loc[order[i]]);
    }
    return 0;
}
