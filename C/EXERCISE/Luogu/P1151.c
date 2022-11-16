#include<stdio.h>
#define MIN 10000
#define MAX 30000
int subnum(int, int);
int main()
{
    int k;
    scanf("%d", &k);
    int i, p = 0;
    for (i = MIN; i <= MAX;i++)
    {
        if(subnum(i,1)%k==0&&subnum(i,2)%k==0&&subnum(i,3)%k==0)
        {
            printf("%d\n", i);
            p = 1;
        }
    }
    if(p==0)
        printf("No");
    return 0;
}

int subnum(int x,int a)
{
    int q[6];
    int i;
    for (i = 1; i <= 5;i++)
    {
        q[i] = x % 10;
        x = x / 10;
    }
    int ans;
    ans = q[a + 2] * 100 + q[a + 1] * 10 + q[a];
    return ans;
}
