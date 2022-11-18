//某程要开习题课，由于教室座位有限，所以决定限制参加人数。于是规定：1、最多允许一半的班级里的同学参加；2、可以参加的班级最多允许一半的同学参加。现请你写一段程序来计算习题课最多可能有多少个学生参加
//输入为两行，第一行为一个整数n(0<n<100),代表班级的个数，第二行为n个正整数，分别代表每个班级的人数
#include<stdio.h>
int findMax(int m[],int n,int max_num)
{
    int max=m[n];
    int i;
    for(i=n;i<=max_num;i++)
    {
        if(m[i]>max)
        {
            max=m[i];
            int cache=m[i];
            m[i]=m[n];
            m[n]=cache;
        }
    }
    return max;
}

int main()
{
    int n;
    scanf("%d",&n);
    int m[n+1];
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&m[i]);
    }
    int ans=0;
    int ans_n=n/2;
    for(i=1;i<=ans_n;i++)
    {
        ans=ans+findMax(m,i,n)/2;
    }
    printf("%d",ans);
    return 0;
}