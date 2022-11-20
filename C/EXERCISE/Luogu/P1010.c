#include<stdio.h>
void print(int n);
int main()
{
    int n;
    scanf("%d", &n);
    print(n);
    return 0;
}

void print(int n)
{
    if(n==0)
        printf("0");
    else if(n==1)
        printf("2(0)");
    else if(n==2)
        printf("2");
    else
    {
        int base02[16]={0};
        int i;
        int nn = n;
        for (i = 0; i <= 15;i++)
        {
            if(n==0)
                break;
            base02[i] = n % 2;
            n = n / 2;
        }
        i--;
        int ii;
        for (ii = i; ii >= 0;ii--)
        {
            if(base02[ii]!=0&&ii!=1)
            {
                if(ii!=i)
                    printf("+");
                printf("2(");
                print(ii);
                printf(")");
            }
            else if(base02[ii]!=0&&ii==1)
            {
                if(ii!=i)
                    printf("+");
                printf("%d", 2);
            }
        }
    }
    return;
}
