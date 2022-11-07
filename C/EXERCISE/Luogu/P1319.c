#include<stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    int sum=0;//if sum == N*N, pause
    int i, p, a = 0, b=1;
    for (;;)
    {
        b++;
        scanf("%d", &i);
        for (p = 1; p <= i;p++)
        {
            if(a==N)
            {
                printf("\n");
                a = 0;
            }
            a++;
            if(b%2==0)
                printf("0");
            else
                printf("1");
        }
        sum = sum + i;
        if(sum==N*N)
            break;
    }
    return 0;
}