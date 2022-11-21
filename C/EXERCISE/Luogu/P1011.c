#include<stdio.h>
int fib(int n)//斐波那契数列
{
    int a_1 = 1, a_2 = 1;
    int an = 0, i;
    for (i = 3; i <= n;i++)
    {
        an = a_1 + a_2;
        a_2 = a_1;
        a_1 = an;
    }
    if(n==1||n==2)
        an = 1;
    return an;
}

int main()
{
    int a, n, m, x;//始发站上车人数a，车站数n，终点站下车人数m，和所求的站点编号x
    scanf("%d%d%d%d", &a, &n, &m, &x);
    int people[n + 4];//第n站开出时车上的人数
    people[1] = a;
    people[2] = a;
    int b;//第二站上车人数
    int i;
    int ans_a = 2, ans_b = 0;
    for (i = 4; i <= n - 1; i++)
    {
        ans_a += fib(i - 4);
        ans_b += fib(i - 3);
    }
    b = (m - ans_a * a) / ans_b;
    people[3] = 2 * a;
    for (i = 4; i <= n;i++)
    {
        people[i] = people[i - 1] + fib(i - 4) * a + fib(i - 3) * b;
    }
    printf("%d", people[x]);
    return 0;
}
