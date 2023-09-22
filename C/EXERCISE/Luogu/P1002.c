//有关心得 https://wangquanlikun.blog.luogu.org/p1002-chao-chu-shi-jian-xian-zhi-wen-ti

#include<stdio.h>
int b1, b2, h1, h2;
long long total = 0;

long long combine(int x,int y)
{
    if (y > x - y) 
        y = x - y;

    long long result = 1;
    for (int i = 0; i < y; i++)
    {
        result *= (x - i);
        result /= (i + 1);
    }
    return result;
}

void move(int x, int y);
int main()
{
    scanf("%d%d%d%d", &b1, &b2, &h1, &h2);
    move(0, 0);
    printf("%lld", total);
    return 0;
}

void move(int x, int y)
{
    if (x == b1 && y == b2)//达成目标
    {
        total++;
        return;
    }
    else if (x > b1 || y > b2)//超过范围
        return;

    if (x > h1 + 2 || y > h2 + 2)//大数直接运算
    {
        total += combine(b1 + b2 - x - y, b1 - x);
        return;
    }

    if ((x == h1 && y == h2) || (x == h1 - 1 && y == h2 - 2) || (x == h1 - 2 && y == h2 - 1) || (x == h1 - 1 && y == h2 + 2) || (x == h1 - 2 && y == h2 + 1) || (x == h1 + 1 && y == h2 - 2) || (x == h1 + 2 && y == h2 - 1) || (x == h1 + 1 && y == h2 + 2) || (x == h1 + 2 && y == h2 + 1)) // 遇到马及其周围方格
        return;
    else // 继续向下或向右移动
    {
        move(x + 1, y);
        move(x, y + 1);
        return;
    }
    return;
}
