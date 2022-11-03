#include<stdio.h>
void move(int, int, int, int);//子程序move
int time=0;//全局变量，移动次数
int main()
{
    int n;
    //共有n个盘子
    scanf("%d", &n);
    move(n, 1, 2, 3);
    //n个盘子从1（借助2）到3
    printf("You need to move %d time(s)", time);
    return 0;
}
void move(int n, int from, int via, int to)//n个盘子从from（借助via）到to
{
    time++;
    if(n==1)//最后只有一个盘子时，直接从from到to
        printf("%d-->%d\n", from, to);
    else if(n>1)//n个盘子从from（借助via）到to,看作以下三步
    {
        move(n - 1, from, to, via);//将（n－1）个盘子从柱from移到柱via，借助于柱to
        printf("%d-->%d\n", from, to);//将柱from上的最后一个盘子直接移动到柱to
        move(n - 1, via, from, to);//将（n－1）个盘子从柱via，移到柱to，借助于柱from
    }
}