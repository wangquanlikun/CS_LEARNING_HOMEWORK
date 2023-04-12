//已知有两个递增的正整数序列A和B，序列中元素个数未知，同一序列中不会有重复元素出现，有可能某个序列为空。现要求将序列B归并到序列A中，且归并后序列A的数据仍然按递增顺序排列。如果序列B中某些数据在序列A中也存在，则这些数据所在节点仍然留在序列B中，而不被归并到序列A中；否则这些数据所在节点将从序列B中删除，添加到序列A中
//注意：建立两个单链表A、B用于存储两个正整数序列，然后按照题目的要求，将链表B中的元素归并到链表A中。在归并的过程中，不要释放B中的节点空间、然后建立新节点，而要改变指针的指向，使元素从B中删除并添加到A中。正整数序列按照递增顺序输入，用-1作为结束标志，注意-1不算这个正整数序列中的元素（不要统计-1）。在程序结束前要释放链表A、B中的所有节点
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
        if(currentPtr!=NULL)
            break;
        if(currentPtr!=NULL&&currentPtr->nextPtr!=NULL)
            currentPtr = currentPtr->nextPtr;
        else
            break;
        free(frontPtr);
    }
    return;
}

void ListOperation(LIST **headPtr_A, LIST **headPtr_B,LIST *lastPtr_A, int num);
void orderLIST(LIST **headPtr, int num);
void PrintList(LIST *headPtr_A, LIST *headPtr_B);
int main()
{
    int inputnum, num = 0;
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
        num++;
    }
    if(lastPtr_A!=NULL)
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
        num++;
    }
    if(lastPtr_B!=NULL)
        lastPtr_B->nextPtr = NULL;

    ListOperation(&headPtr_A, &headPtr_B, lastPtr_A, num);
    PrintList(headPtr_A, headPtr_B);

    freeHead(headPtr_A);
    freeHead(headPtr_B);
    return 0;
}

void PrintList(LIST *headPtr_A, LIST *headPtr_B)
{
    if(headPtr_A==NULL)
        printf("There is no item in A list.\n");
    else
    {
    LIST *currentPtr = headPtr_A, *frontPtr = headPtr_A;
    printf("The new list A:");
    for (;;)
    {
        if(currentPtr!=headPtr_A)
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
    }
    if(headPtr_B==NULL)
        printf("There is no item in B list.\n");
    else
    {
    LIST *currentPtr = headPtr_B, *frontPtr = headPtr_B;
    printf("The new list B:");
    for (;;)
    {
        if(currentPtr!=headPtr_B)
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
            if(nowPtr==NULL)
                return;
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
void ListOperation(LIST **headPtr_A, LIST **headPtr_B, LIST *lastPtr_A, int num)
{
    //遍历A、B，不同项插入A中，然后再A排序
    LIST *currentPtr_A = *headPtr_A, *currentPtr_B, *beforePtr_B;
    beforePtr_B = *headPtr_B;
    if(*headPtr_B==NULL)
        return;
    else if(*headPtr_A==NULL)
    {
        LIST *cache = *headPtr_A;
        *headPtr_A = *headPtr_B;
        *headPtr_B = cache;
        return;
    }
    currentPtr_B = beforePtr_B->nextPtr;
    while(1)
    {
        currentPtr_A = *headPtr_A;
        if(currentPtr_B==NULL)
            break;
        int B_value = currentPtr_B->num;
        int adjust = 0;//0表示没有相同项
        while(1)
        {
            if(B_value==currentPtr_A->num)
            {
                adjust = 1;
                num--;
                break;
            }
            else
                currentPtr_A = currentPtr_A->nextPtr;
            if(currentPtr_A==NULL)
                break;
        }
        if(adjust==0)//没有相同项，尾插
        {
            beforePtr_B->nextPtr = currentPtr_B->nextPtr;
            lastPtr_A->nextPtr = currentPtr_B;
            lastPtr_A = currentPtr_B;
            currentPtr_B->nextPtr = NULL;
        }

        if(adjust==1)
        {
            beforePtr_B = beforePtr_B->nextPtr;
            currentPtr_B = beforePtr_B->nextPtr;
        }
        else if(adjust==0)
            currentPtr_B = beforePtr_B->nextPtr;

        if(currentPtr_B==NULL)
            break;
    }
    //B头节点比较、处理
    int k = 0;
    int B_value = (*headPtr_B)->num;
    currentPtr_A = *headPtr_A;
    while(1)
    {
        if(B_value==currentPtr_A->num)
        {
            k = 1;
            num--;
            break;
        }
        else
            currentPtr_A = currentPtr_A->nextPtr;
        if(currentPtr_A==NULL)
            break;
    }
    if(k==0)
    {
        LIST *cache = (*headPtr_B)->nextPtr;
        (*headPtr_B)->nextPtr = *headPtr_A;
        *headPtr_A = *headPtr_B;
        *headPtr_B = cache;
    }
    orderLIST(headPtr_A, num);
    return;
}