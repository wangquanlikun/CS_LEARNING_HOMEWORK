#include<stdio.h>
void findmax(int a[][6], int n);
int main()
{
    int n;
    scanf("%d", &n);
    int score[n + 1][6];
    int i;
    for (i = 1; i <= n;i++)
    {
        scanf("%d%d%d", &score[i][1], &score[i][2], &score[i][3]);
        score[i][4] = score[i][1] + score[i][2] + score[i][3];
        score[i][5] = i;
    }
    findmax(score, n);
    for (i = 1; i <= 5;i++)
    {
        printf("%d %d\n", score[i][5], score[i][4]);
    }
    return 0;
}

void findmax(int a[][6], int n)
{
    int k1, k2;
    for (k1 = 1; k1 < n;k1++)
    {
        for (k2 = 1; k2 < n;k2++)
        {
            if(a[k2][4]<a[k2+1][4])
            {
                int i;
                for (i = 1; i <= 5;i++)
                {
                    int cache = a[k2][i];
                    a[k2][i] = a[k2 + 1][i];
                    a[k2 + 1][i] = cache;
                }
            }
            else if(a[k2][4]==a[k2+1][4])
            {
                if(a[k2][1]<a[k2+1][1])
                {
                    int i;
                    for (i = 1; i <= 5;i++)
                    {
                        int cache = a[k2][i];
                        a[k2][i] = a[k2 + 1][i];
                        a[k2 + 1][i] = cache;
                    }
                }
                else if(a[k2][1]==a[k2+1][1])
                {
                    if(a[k2][5]>a[k2+1][5])
                    {
                        int i;
                        for (i = 1; i <= 5;i++)
                        {
                            int cache = a[k2][i];
                            a[k2][i] = a[k2 + 1][i];
                            a[k2 + 1][i] = cache;
                        }
                    }
                }
            }
        }
    }
}
