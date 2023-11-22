#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n], b[n], g[n], k[n];
    int x, y;
    for (int i = 0; i < n; i++)
        scanf("%d%d%d%d",&a[i],&b[i],&g[i],&k[i]);
    scanf("%d%d",&x,&y);
    int num = 0;
    for (int i = 0; i < n; i++)
        if (x >= a[i] && x <= a[i] + g[i] && y >= b[i] && y <= b[i] + k[i])
            num = i + 1;
    if(num == 0)
        printf("-1");
    else
        printf("%d",num);
    return 0;
}