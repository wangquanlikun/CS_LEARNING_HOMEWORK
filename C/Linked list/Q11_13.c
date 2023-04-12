//已知一个正整数序列，序列元素个数未知，但至少有两个元素，你的任务是建立一个单链表用于存储这个正整数序列。然后实现交换此链表中任意指定的两段，第一段为[s1,t1]，第二段[s2,t2]。s1、t1、s2、t2代表链表的第几个节点，且满足s1<=t1，s2<=t2，t1<s2，s2一定小于等于链表节点的总个数。正整数的输入用-1作为结束标志，注意-1不算这个正整数序列中的元素（不要统计-1）。最后将链表的全部节点释放
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

void exchange(LIST **heatPtr);
void outputLIST(LIST *headPtr);
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
    exchange(&headPtr);
    outputLIST(headPtr);
    freeHead(headPtr);
    return 0;
}

void exchange(LIST **heatPtr)
{
    int s1, s2, t1, t2;//交换[s1,s2]，[t1,t2]
    scanf("%d%d%d%d", &s1, &s2, &t1, &t2);
    int a1;
    LIST *currentPtr;
    LIST *cache1, *cache2, *cache3, *cache4, *cache5, *cache6;
    currentPtr = *heatPtr;
    for (a1 = 2;a1<=t1;a1++)
    {
        if(a1==t1)
            cache1 = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }
    currentPtr = *heatPtr;
    for(a1 = 2;a1<=s1;a1++)
    {
        if(a1==s1)
            cache2 = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }
    currentPtr = *heatPtr;
    for(a1 = 2;a1<=t2+1;a1++)
    {
        if(a1==t2+1)
            cache3 = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }
    currentPtr = *heatPtr;
    for(a1 = 2;a1<=s2+1;a1++)
    {
        if(a1==s2+1)
            cache4 = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }
    currentPtr = *heatPtr;
    for(a1 = 2;a1<=t2+1;a1++)
    {
        if(a1==t2+1)
            cache5 = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }
    currentPtr = *heatPtr;
    for(a1 = 2;a1<=s1;a1++)
    {
        if(a1==s1)
            cache6 = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }
    int a;
    if(s1!=1&&s2!=t1-1)
    {
        LIST *cache_cache_2 = cache6->nextPtr;
        LIST *cache_cache_3 = cache5->nextPtr;
        cache6->nextPtr = cache1->nextPtr;
        cache5->nextPtr = cache4->nextPtr;
        cache1->nextPtr = cache_cache_2;
        cache4->nextPtr = cache_cache_3;
    }
    else if(s1!=1&&s2==t1-1)
    {
        LIST *cache_cache_2 = cache6->nextPtr;
        LIST *cache_cache_3 = cache5->nextPtr;
        cache6->nextPtr = cache1->nextPtr;
        cache5->nextPtr = cache_cache_2;
        cache4->nextPtr = cache_cache_3;
    }

    else if(s1==1&&s2!=1&&s2!=t1-1)
    {
        LIST *cache_cache_1 = cache1->nextPtr;
        LIST *cache_cache_3 = cache5->nextPtr;
        cache5->nextPtr = cache4->nextPtr;
        cache1->nextPtr = *heatPtr;
        cache4->nextPtr = cache_cache_3;
        *heatPtr = cache_cache_1;
    }
    else if(s2==1&&s2!=t1-1)
    {
        LIST *cache_cache_1 = cache1->nextPtr;
        LIST *cache_cache_3 = cache5->nextPtr;
        cache5->nextPtr = (*heatPtr)->nextPtr;
        cache1->nextPtr = *heatPtr;
        (*heatPtr)->nextPtr = cache_cache_3;
        *heatPtr = cache_cache_1;
    }

    else if(s1==1&&s2!=1&&s2==t1-1)
    {
        LIST *cache_cache_1 = cache1->nextPtr;
        LIST *cache_cache_3 = cache5->nextPtr;
        cache5->nextPtr = *heatPtr;
        cache4->nextPtr = cache_cache_3;
        *heatPtr = cache_cache_1;
    }
    else if(s2==1&&s2==t1-1)
    {
        LIST *cache_cache_1 = cache1->nextPtr;
        LIST *cache_cache_3 = cache5->nextPtr;
        cache5->nextPtr = *heatPtr;
        (*heatPtr)->nextPtr = cache_cache_3;
        *heatPtr = cache_cache_1;
    }
    return;
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