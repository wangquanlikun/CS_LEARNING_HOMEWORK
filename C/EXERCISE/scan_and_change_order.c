//从头到尾比较相邻两个元素，如果前面的元素大于其紧随的后面元素，则交换它们。输出扫描完第K遍后的中间结果数列
#include<stdio.h>
int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    int i;
    int a[N+1];
    for(i=1;i<=N;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=K;i++)
    {
        int p;
        int cache;
        for(p=1;p<N;p++)
        {
            if(a[p]>a[p+1])
            {
                cache=a[p];
                a[p]=a[p+1];
                a[p+1]=cache;
            }
        }
    }
    for(i=1;i<=N;i++)
    {
        if(i==1)
            printf("%d",a[i]);
        else
            printf(" %d",a[i]);
    }
    return 0;
}
