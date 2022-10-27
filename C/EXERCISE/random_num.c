#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(NULL));//运用时间设置伪随机数种子
    int a, b;//输出从a到b的随机数
    scanf("%d%d", &a, &b);
    int num;//输出多少个随机数
    scanf("%d", &num);
    int i;
    for (i = 1; i <= num;i++)
    {
        printf("%d ", a + rand() % (b - a + 1));
    }
    return 0;
}