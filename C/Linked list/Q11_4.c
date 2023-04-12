//已知一个正整数序列，个数未知，但至少有一个元素，你的任务是建立一个单链表，并使用该链表存储这个正整数序列，然后统计这个序列中元素的最大值与最小值，计算序列全部元素之和。正整数的输入用-1作为结束标志，注意-1不算这个正整数序列中的元素（不要统计-1）。
#include<stdio.h>
#include<stdlib.h>
struct List
{
    int num;
    struct List *nextPtr;
};

int main()
{
    int min, max, total = 0;
    int inputnum;
    scanf("%d", &inputnum);
    min = inputnum;
    max = inputnum;
    total = inputnum;

    struct List *headPtr = NULL;
    struct List *nowPtr = NULL;
    struct List *lastPtr = NULL;

    while(inputnum!=-1)
    {
        nowPtr=malloc(sizeof(struct List *));
        nowPtr->num = inputnum;
        if(headPtr==NULL)//插入的是第一个节点
        {
            headPtr = nowPtr;
            lastPtr = nowPtr;
        }
        else
        {
            lastPtr->nextPtr = nowPtr;
            lastPtr = nowPtr;
        }

        scanf("%d", &inputnum);
        if(inputnum!=-1)
        {
            total += inputnum;
            if(inputnum>max)
                max = inputnum;
            if(inputnum<min)
                min = inputnum;
        }
    }
    printf("The maximum,minmum and the total are:%d %d %d", max, min, total);
}