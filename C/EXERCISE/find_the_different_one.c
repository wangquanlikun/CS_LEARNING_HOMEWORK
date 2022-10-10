#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a==b)
        printf("C");
    else if(a==c)
        printf("B");
    else if(b==c)
        printf("A");
    return 0;
}
