//已知一个正整数组成的无序序列，个数未知，但至少有一个元素，你的任务是建立一个单链表，并使用该链表存储这个正整数序列，然后将这个链表进行排序，使得排序后的链表为递增序列。正整数的输入用-1作为结束标志，注意-1不算这个正整数序列中的元素（不要统计-1）。在排序的过程中，你可以自己选择排序算法（冒泡排序、选择排序等），但必须是通过修改结点的指针域来进行排序，而不是对结点的数据域进行修改。程序结束后要释放所有节点占据的空间
#include<stdio.h>
#include<stdlib.h>
struct List
{
    int num;
    struct List *nextPtr;
};
typedef struct List LIST;
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
void outputLIST(LIST *headPtr);
void orderLIST(LIST **headPtr,int num);
int main()
{
    int inputnum;
    scanf("%d", &inputnum);
    int num = 0;
    LIST *headPtr = NULL, *nowPtr = NULL, *lastPtr = NULL;
    while(inputnum!=-1)
    {
        nowPtr = malloc(sizeof(LIST *));
        nowPtr->num = inputnum;
        if(headPtr==NULL)
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
        num++;
    }
    lastPtr->nextPtr = NULL;
    orderLIST(&headPtr,num);
    outputLIST(headPtr);
    freeHead(headPtr);
    return 0;
}
void outputLIST(LIST *headPtr)
{
    LIST *currentPtr = headPtr, *frontPtr = headPtr;
    printf("The new list is:");
    for (;;)
    {
        if(currentPtr!=headPtr)
            printf(" ");
        if(currentPtr!=NULL)
        {
            printf("%d", currentPtr->num);
            frontPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        if(currentPtr==NULL)
        {
            printf("\n");
            break;
        }
    }
    return;
}
void orderLIST(LIST **headPtr,int num)
{
    LIST *beforePtr, *nowPtr, *afterPtr;
    LIST *cache;
    int i;
    if(num==1||num==2)
    {
        if(num==1)
            return;
        if(num==2)
        {
            beforePtr = *headPtr;
            nowPtr = beforePtr->nextPtr;
            if(beforePtr->num > nowPtr->num)
            {
                cache = beforePtr;
                beforePtr->nextPtr = nowPtr->nextPtr;
                nowPtr->nextPtr = cache;
                *headPtr = nowPtr;
            }
            return;
        }
    }
    for (i = 1; i <= num;i++)
    {
        beforePtr = *headPtr;
        nowPtr = beforePtr->nextPtr;
        afterPtr = nowPtr->nextPtr;
        if(beforePtr->num > nowPtr->num)
        {
            cache = beforePtr;
            beforePtr->nextPtr = nowPtr->nextPtr;
            nowPtr->nextPtr = cache;
            *headPtr = nowPtr;
        }
        beforePtr = *headPtr;
        nowPtr = beforePtr->nextPtr;
        afterPtr = nowPtr->nextPtr;
        while(1)
        {
            if(nowPtr->num > afterPtr->num)
            {
                cache = afterPtr->nextPtr;
                beforePtr->nextPtr = afterPtr;
                afterPtr->nextPtr = nowPtr;
                nowPtr->nextPtr = cache;
            }
            beforePtr = beforePtr->nextPtr;
            nowPtr = beforePtr->nextPtr;
            afterPtr = nowPtr->nextPtr;
            if(afterPtr==NULL)
                break;
        }
    }
}