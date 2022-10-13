#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int main()
{
    int n;//方格有几行几列
    input1:
    printf("Please enter the size of the area\n");
    scanf("%d", &n);
    if(n>MAX)
    {
        printf("The size is too large.\nPlease enter it again.\n");
        goto input1;
    }
    system("cls");
    int a[n][n];
    int p, q;
    for (p = 0; p <= n;p++)
    {
        for (q = 0; q <= n;q++)
        {
            a[p][q] = 0;//变量初始化
        }
    }
    int win = 0;
    int pp, qq;
    for (p = 0; p <= n;p++)
    {
        for (q = 0; q <= n;q++)
        {
            printf("%d ", a[p][q]);//打印初始表格
        }
        printf("\n");
    }
    printf("\n");
    do
    {
        printf("Choose a plase to plase yours.\n");
        input2:
        scanf("%d%d", &pp, &qq);
        if(a[pp-1][qq-1]==0)
            a[pp-1][qq-1] = 1;
        else if((a[pp-1][qq-1]==1)||pp>=n||qq>=n)
        {
            printf("ERROR\nPlease try again.\n");
            goto input2;
        }
        system("cls");
        for (p = 0; p <= n;p++)
        {
            for (q = 0; q <= n;q++)
            {
                printf("%d ", a[p][q]);
            }
            printf("\n");
        }

        //adjust if it wins.
        for (p = 0; p <= n;p++)
        {
            for (q = 0; q <= n;q++)
            {
                if(a[p][q]==1)
                {
                    //竖排满足
                    if((a[p-2][q]==1&&a[p-1][q]==1&&a[p][q]==1)||(a[p-1][q]==1&&a[p][q]==1&&a[p+1][q]==1)||(a[p][q]==1&&a[p+1][q]==1&&a[p+2][q]==1))
                        {
                            win = 1;
                            break;
                        }
                    //竖排满足
                    else if((a[p][q-2]==1&&a[p][q-1]==1&&a[p][q]==1)||(a[p][q-1]==1&&a[p][q]==1&&a[p][q+1]==1)||(a[p][q]==1&&a[p][q+1]==1&&a[p][q+2]==1))
                        {
                            win = 1;
                            break;
                        }
                    //斜着满足
                    else if((a[p-2][q-2]==1&&a[p-1][q-1]==1&&a[p][q]==1)||(a[p-1][q-1]==1&&a[p][q]==1&&a[p+1][q+1]==1)||(a[p][q]==1&&a[p+1][q+1]==1&&a[p+2][q+2]==1))
                        {
                            win = 1;
                            break;
                        }
                    else if((a[p+2][q-2]==1&&a[p+1][q-1]==1&&a[p][q]==1)||(a[p+1][q-1]==1&&a[p][q]==1&&a[p-1][q+1]==1)||(a[p][q]==1&&a[p-1][q+1]==1&&a[p-2][q+2]==1))
                        {
                            win = 1;
                            break;
                        }
                    //只能做三子棋了:(
                }
                else
                    ;
            }
        }

    } while (win==0);
    if(win==1)
        system("cls");
        printf("WIN!\n");
    return 0;
}
