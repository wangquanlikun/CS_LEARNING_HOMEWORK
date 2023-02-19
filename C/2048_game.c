#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void creat(int space[5][5]);

void moveA(int space[5][5],int a);
void moveW(int space[5][5],int b);
void moveS(int space[5][5],int b);
void moveD(int space[5][5],int a);

int main()
{
    int space[5][5]={0};//4×4的2048格子
    int zero_num = 0;//0的个数 如果只有0个零则游戏结束
    int a, b;
    char c;
    system("cls");
    creat(space);
    do
    {
        creat(space);
        for (a = 1; a <= 4;a++)
        {
            for (b = 1; b <= 4;b++)
            {
                if(space[a][b]!=0)
                    printf("%d\t", space[a][b]);
                else if(space[a][b]==0)
                    printf("X\t");
            }
            printf("\n");
        }

        redo1:
        scanf("%c", &c);
        int k;
        if(c=='A'||c=='a')
        {
            for (a = 1; a <= 4;a++)
            {
                moveA(space, a);
                moveA(space, a);
            }
            for (a = 1; a <= 4;a++)
            {
                for (b = 1; b <= 3;b++)
                {
                    if(space[a][b]==space[a][b+1])
                    {
                        space[a][b] *= 2;
                        space[a][b + 1] = 0;
                        moveA(space, a);
                    }
                }
            }
        }
        else if(c=='W'||c=='w')
        {
            for (b = 1; b <= 4;b++)
            {
                moveW(space, b);
                moveW(space, b);
            }
            for (b = 1; b <= 4;b++)
            {
                for (a = 1; a <= 3;a++)
                {
                    if(space[a][b]==space[a+1][b])
                    {
                        space[a][b] *= 2;
                        space[a + 1][b] = 0;
                        moveW(space, b);
                    }
                }
            }
        }
        else if(c=='S'||c=='s')
        {
            for (b = 1; b <= 4;b++)
            {
                moveS(space, b);
                moveS(space, b);
            }
            for (b = 1; b <= 4;b++)
            {
                for (a = 4; a >= 2; a--)
                {
                    if(space[a][b]==space[a-1][b])
                    {
                        space[a][b] *= 2;
                        space[a - 1][b] = 0;
                        moveS(space, b);
                    }
                }
            }
        }
        else if(c=='D'||c=='d')
        {
            for (a = 1; a <= 4;a++)
            {
                moveD(space, a);
                moveD(space, a);
            }
            for (a = 1; a <= 4;a++)
            {
                for (b = 4; b >= 2;b--)
                {
                    if(space[a][b]==space[a][b-1])
                    {
                        space[a][b] *= 2;
                        space[a][b - 1] = 0;
                        moveD(space, a);
                    }
                }
            }
        }
        else
            goto redo1;

        zero_num = 0;
        for (a = 1; a <= 4;a++)
        {
            for (b = 1; b <= 4;b++)
            {
                if(space[a][b]==0)
                    zero_num++;
            }
        }
        if(zero_num==0)
            break;
        system("cls");
    } while (zero_num!=0);
    
    if(zero_num==0)
        printf("LOSE");
    
    return 0;
}

void creat(int space[5][5])
{
    int x, y;
    int k = 0;
    do
    {
        srand(time(NULL));
        x = rand() % 4 + 1;
        y = rand() % 4 + 1;
        if(space[x][y]==0)
        {
            k = 1;
            space[x][y] = 2;
        }
        if(k==1)
            break;
    } while (k == 0);

    return;
}

void moveA(int space[5][5],int a)
{
    int b,k;
    for (b = 1; b <= 4 - 1;b++)
    {
        if(space[a][b]==0)
        {
            for (k = b; k <= 4 - 1;k++)
                space[a][k] = space[a][k + 1];
            space[a][k] = 0;
        }
    }
}
void moveW(int space[5][5],int b)
{
    int a, k;
    for (a = 1; a <= 4 - 1;a++)
    {
        if(space[a][b]==0)
        {
            for (k = a; k <= 4 - 1;k++)
                space[k][b] = space[k + 1][b];
            space[k][b] = 0;
        }
    }
}
void moveS(int space[5][5],int b)
{
    int a, k;
    for (a = 4; a >= 1 + 1; a--)
    {
        if(space[a][b]==0)
        {
            for (k = a; k >= 1 + 1; k--)
                space[k][b] = space[k - 1][b];
            space[k][b] = 0;
        }
    }
}
void moveD(int space[5][5],int a)
{
    int b, k;
    for (b = 4; b >= 1 + 1; b--)
    {
        if(space[a][b]==0)
        {
            for (k = b; k >= 1 + 1; k--)
                space[a][k] = space[a][k - 1];
            space[a][k] = 0;
        }
    }
}