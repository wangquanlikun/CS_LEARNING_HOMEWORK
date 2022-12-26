#include<stdio.h>
struct info
{
    int id;
    int score;
};
void sort(struct info a[], int n);
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int i;
    struct info a[n];
    for (i = 0; i < n;i++)
        scanf("%d%d", &a[i].id, &a[i].score);
    m = m * 1.5;
    int scoreline;
    int num;
    sort(a, n);
    scoreline = a[m - 1].score;
    while(a[m-1].score==a[m].score)
        m += 1;
    num = m;
    printf("%d %d\n", scoreline, num);
    for (i = 0; i < m;i++)
        printf("%d %d\n", a[i].id, a[i].score);
    return 0;
}
void sort(struct info a[], int n)
{
    int i1, i2;
    for (i1 = 1; i1 < n;i1++)
    {
        for (i2 = 0; i2 < n - 1;i2++)
        {
            if((a[i2].score<a[i2+1].score)||((a[i2].score==a[i2+1].score)&&a[i2].id>a[i2+1].id))
            {
                struct info cache = a[i2];
                a[i2] = a[i2 + 1];
                a[i2 + 1] = cache;
            }
        }
    }
    return;
}
