//已知两个由正整数组成的无序序列A、B，每个序列的元素个数未知，但至少有一个元素。你的任务是判断序列B是否是序列A的连续子序列。假设B是“1 9 2 4 18”，A是“33 64 1 9 2 4 18 7”，B是A的连续子序列；假设B是“1 9 2 4 18”，A是“33 1 9 64 2 4 18 7”，B不是A的连续子序列。
#include<stdio.h>
int main()
{
    int A[1001];
    int B[1001];
    int ia=1;
    scanf("%d",&A[ia]);
    while(A[ia]!=-1)
    {
        ia=ia+1;
        scanf("%d",&A[ia]);
    }
    int ib=1;
    scanf("%d",&B[ib]);
    while(B[ib]!=-1)
    {
        ib=ib+1;
        scanf("%d",&B[ib]);
    }
    int p=0;
    int a1=1,a2=1;
    for(a1=1;a1<ia;a1++)
    {
        if(A[a1]==B[1])
        {
            p=1;
            int a1_cache=a1;
            for(a2=1;a2<ib;a1_cache++,a2++)
            {
                if(A[a1_cache]!=B[a2])
                    p=0;
            }
            if(p==1)
                break;
        }
    }
    
    if(p==0)
    {
        printf("ListB is not the sub sequence of ListA.");
    }
    else if(p==1)
        printf("ListB is the sub sequence of ListA.");
    return 0;
}