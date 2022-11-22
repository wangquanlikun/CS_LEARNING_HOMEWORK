#include<stdio.h>
int main()
{
    int m, n;//有m个人，数到n出局
    scanf("%d%d", &m, &n);
    int order[m + 1];//数组下标i代表其标号，数组a[i]储存值代表其下一个人编号
    int i;
    for (i = 1; i <= m - 1;i++)
        order[i] = i + 1;
    order[m] = 1;
    int in;
    int prei;
    for (i = m, in = 1;;in++)
    {
        if(order[i]==i)
            break;
        prei = i;
        i = order[i];
        if(in%n==0)
        {
            order[prei] = order[i];
            i = prei;
        }
    }
    printf("%d", i);
    return 0;
}