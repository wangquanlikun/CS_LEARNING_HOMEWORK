//给定一个长度为n的整数数组，数组中连续的相等元素构成的子序列称为平台。试设计算法，求出数组中最长平台的长度。
#include<stdio.h>
int main()
{
    int i;
    scanf("%d",&i);
    int num;
    int ii=1;
    scanf("%d",&num);
    int num_cache;
    num_cache=num;
    int ans=1,ans_max=ans;
    for(ii=2;ii<=i;ii++)
    {
        scanf("%d",&num);
        if(num_cache==num)
            ans++;
        else if(num_cache!=num)
            ans=1;
        num_cache = num;
        if(ans>ans_max)
            ans_max=ans;
    }
    printf("%d",ans_max);
    return 0;
}