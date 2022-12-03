//已知正整数n，n的范围是1—100。你要从键盘读入n个字符串，每个字符串的长度不确定，但是n个字符串的总长度不超过100000。你要利用字符指针数组将这n个字符串按照ASCII码顺序进行升序排序，然后再打印到屏幕上。字符串中可能包含ASCII码中的任意字符，每个字符串以换行符结束输入
#include <stdio.h>
#include<string.h>
void swap(char *m[],int n)
{
    char *a;
    a=m[n];
    m[n]=m[n+1];
    m[n+1]=a;
}
int main()
{
    char str[100000];
    int n;
    scanf("%d",&n);
    char *n_loc[n];
    n_loc[0]=str;
    getchar();
    int i, j;
    for (i=0;i<n;i++)
    {
        gets(n_loc[i]);
        if (i!=n-1)
            n_loc[i+1]=n_loc[i]+strlen(n_loc[i])+1;
    }
    for (i = 1; i <=n-1 ; i++)
    {
        for (j = 0; j <n-i ; j++)
        {
            if (strcmp(n_loc[j],n_loc[j+1])>0)
                swap(n_loc,j);
        }
    }
    for (i=0;i<n;i++)
        puts(n_loc[i]);
    return 0;
}
