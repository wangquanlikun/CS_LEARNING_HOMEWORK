#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int floor, max_f = 0;
    int time = 0;
    int adjust[20000000]={0};
    for (i = 1; i <= n;i++)
    {
        scanf("%d", &floor);
        if(floor>max_f)
            max_f = floor;
        if(adjust[floor]==0)
            time += 6;
        else
            time += 1;
        adjust[floor] += 1;
    }
    time += max_f * 10;
    printf("%d", time);
    return 0;
}
