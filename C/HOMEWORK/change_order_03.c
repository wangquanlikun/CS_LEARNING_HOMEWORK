//设有整数数组A和B，它们长度均为n。A数组中的元素为任意整数，不超过int型数据范围。B数组中元素的值互不相同，且取值介于0至n-1之间。现要求按数组B的内容调整A中数据的次序，比如当B[i]=j时，则要求将A[i]的内容与A[j]互换
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int A[n],B[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&B[i]);
    }
    int cache,number;
    for(i=0;i<n;i++)
    {
        number=B[i];
        cache=A[i];
        A[i]=A[number];
        A[number]=cache;
    }
    for(i=0;i<n;i++)
    {
        if(i<n-1)
            printf("%d ",A[i]);
        else if(i==n-1||n==1)
            printf("%d\n",A[i]);
    }
    return 0;
}