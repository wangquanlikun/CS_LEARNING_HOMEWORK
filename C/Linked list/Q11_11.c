//你的任务是判断序列B是否是序列A的连续子序列。假设B是“1 9 2 4 18”，A是“33 64 1 9 2 4 18 7”，B是A的连续子序列；假设B是“1 9 2 4 18”，A是“33 1 9 64 2 4 18 7”，B不是A的连续子序列。
//要求：建立两个单链表A、B用于存储两个正整数序列，然后按照题目的要求，判断链表B是否是链表A的连续子序列。正整数的输入用-1作为结束标志，注意-1不算这个正整数序列中的元素（不要统计-1）。在程序结束前要释放链表A、B中的所有节点。
#include<stdio.h>
#include<stdlib.h>
struct List
{
    int num;
    struct List *nextPtr;
};
typedef struct List LIST;

void adjust(LIST *headPtr_A, LIST *headPtr_B);
void freeHead(LIST *heatPtr);
int main()
{
    int inputnum;
    scanf("%d", &inputnum);
    LIST *headPtr_A = NULL, *nowPtr_A = NULL, *lastPtr_A = NULL;
    while(inputnum!=-1)
    {
        nowPtr_A = malloc(sizeof(LIST *));
        nowPtr_A->num = inputnum;
        if(headPtr_A==NULL)
        {
            headPtr_A = nowPtr_A;
            lastPtr_A = nowPtr_A;
        }
        else
        {
            lastPtr_A->nextPtr = nowPtr_A;
            lastPtr_A = nowPtr_A;
        }
        scanf("%d", &inputnum);
    }
    lastPtr_A->nextPtr = NULL;
    scanf("%d", &inputnum);
    LIST *headPtr_B = NULL, *nowPtr_B = NULL, *lastPtr_B = NULL;
    while(inputnum!=-1)
    {
        nowPtr_B = malloc(sizeof(LIST *));
        nowPtr_B->num = inputnum;
        if(headPtr_B==NULL)
        {
            headPtr_B = nowPtr_B;
            lastPtr_B = nowPtr_B;
        }
        else
        {
            lastPtr_B->nextPtr = nowPtr_B;
            lastPtr_B = nowPtr_B;
        }
        scanf("%d", &inputnum);
    }
    lastPtr_B->nextPtr = NULL;
    adjust(headPtr_A, headPtr_B);
    freeHead(headPtr_A);
    freeHead(headPtr_B);
    return 0;
}

void adjust(LIST *headPtr_A, LIST *headPtr_B)
{
    LIST *currentPtr_A = headPtr_A, *currentPtr_B = headPtr_B;
    lab1:
    while(currentPtr_A!=NULL&&(currentPtr_B->num!=currentPtr_A->num))
    {
        currentPtr_A = currentPtr_A->nextPtr;
    }
    if(currentPtr_A==NULL)
    {
        printf("ListB is not the sub sequence of ListA.");
        return;
    }

    if(currentPtr_B->num==currentPtr_A->num)
    {
        LIST *cachePtr_A = currentPtr_A, *cachePtr_B = currentPtr_B;
        int p = 1;
        for (;;)
        {
            if(currentPtr_B->num!=currentPtr_A->num)
            {
                p = 0;
                break;
            }
            else if(currentPtr_B->num==currentPtr_A->num)
            {
                currentPtr_A = currentPtr_A->nextPtr;
                currentPtr_B = currentPtr_B->nextPtr;
            }
            if(currentPtr_B==NULL)
                break;
            if(currentPtr_A==NULL&&currentPtr_B!=NULL)
            {
                p = 0;
                break;
            }
        }

        if (p == 1)
            printf("ListB is the sub sequence of ListA.");
        else if (p == 0)
        {
            currentPtr_A = cachePtr_A->nextPtr;
            currentPtr_B = cachePtr_B;
            goto lab1;
        }
    }
    return;
}

void freeHead(LIST *heatPtr)
{
    LIST *currentPtr, *frontPtr;
    currentPtr = heatPtr;
    for (;;)
    {
        frontPtr = currentPtr;
        if(currentPtr->nextPtr!=NULL)
            currentPtr = currentPtr->nextPtr;
        else
            break;
        free(frontPtr);
    }
    return;
}