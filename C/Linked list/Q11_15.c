//已知有一个乱序的字符序列L，序列中的字符可能是英文字母、数字字符或其它字符，字符的个数未知，每个字符之间用空格分开。字符序列用“-1”作为输入结束标志，这里你要把-1当做一个字符串对待，并且不算作字符序列中的元素。如下即为一个合法的字符序列：“a c 3 b a d 6 , & j m 8 7 2 V -1”。你的任务是将这个字符序列拆分为三个独立的序列A、B和C，其中序列A存放序列L中的字母，序列B存放序列L中的数字，序列C存放序列L中的其他字符，然后，将序列A、B和C分别按照ASCII码的大小关系进行升序排序。最终序列L将变为空序列。
//要求：建立四个单链表，分别存储序列L、A、B、C中的元素。字符序列的输入用“-1”作为结束标志。建立链表L时，建议使用scanf(“%s”,s);来读取字符序列中的字符，即把单独的字符看做一个字符串读取。当L建立后，你要按照问题描述中所述，将L拆分为A、B、C三个链表，然后对每个链表都进行排序，这部分的操作都应该是对指针进行修改，而不是删除节点与建立新节点。在程序结束前要释放链表A、B、C中的所有节点。
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct list
{
    char store[3];
    struct list *nextPtr;
} LIST;
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
void orderLIST(LIST **headPtr, int num);
void operationLIST(LIST *headPtr);
void outputLIST(LIST *headPtr,char s);
int main()
{
    char input[3]={0,0,0};
    int num = 0;
    scanf("%s", input);
    LIST *headPtr = NULL, *nowPtr = NULL, *lastPtr = NULL;
    while(strcmp(input,"-1")!=0)
    {
        nowPtr = malloc(sizeof(LIST *));
        strcpy(nowPtr->store, input);
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
        scanf("%s", input);
        num++;
    }
    if(lastPtr!=NULL)
        lastPtr->nextPtr = NULL;
    orderLIST(&headPtr, num);
    operationLIST(headPtr);

    return 0;
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
            if(strcmp(beforePtr->store,nowPtr->store)>0)
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
        if(strcmp(beforePtr->store, nowPtr->store) > 0)
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
            if(strcmp(nowPtr->store, afterPtr->store) > 0)
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

void outputLIST(LIST *headPtr,char s)
{
    LIST *currentPtr = headPtr;
    if(headPtr==NULL)
        printf("There is no item in %c list.\n", s);
    else
    {
        printf("The list %c is:", s);
        while(1)
        {
            if(currentPtr!=NULL)
            {
                printf(" %s", currentPtr->store);
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
void operationLIST(LIST *headPtr)
{
    LIST *headPtr_A = NULL, *headPtr_B = NULL, *headPtr_C = NULL;
    LIST *nowPtr_A = NULL, *nowPtr_B = NULL, *nowPtr_C = NULL;
    LIST *lastPtr_A = NULL, *lastPtr_B = NULL, *lastPtr_C = NULL;

    LIST *currentPtr = headPtr;
    while(1)
    {
        if(currentPtr==NULL)
            break;
        if((strcmp(currentPtr->store,"A")>=0&&strcmp(currentPtr->store,"Z")<=0)||(strcmp(currentPtr->store,"a")>=0&&strcmp(currentPtr->store,"z")<=0))
        {
            char copy[3]={0,0,0};
            strcpy(copy, currentPtr->store);
            nowPtr_A = malloc(sizeof(LIST *));
            strcpy(nowPtr_A->store, copy);
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
            if(lastPtr_A!=NULL)
                lastPtr_A->nextPtr = NULL;
        }
        else if(strcmp(currentPtr->store,"0")>=0&&strcmp(currentPtr->store,"9")<=0)
        {
            char copy[3]={0,0,0};
            strcpy(copy, currentPtr->store);
            nowPtr_B = malloc(sizeof(LIST *));
            strcpy(nowPtr_B->store, copy);
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
            if(lastPtr_B!=NULL)
                lastPtr_B->nextPtr = NULL;
        }
        else
        {
            char copy[3]={0,0,0};
            strcpy(copy, currentPtr->store);
            nowPtr_C = malloc(sizeof(LIST *));
            strcpy(nowPtr_C->store, copy);
            if(headPtr_C==NULL)
            {
                headPtr_C = nowPtr_C;
                lastPtr_C = nowPtr_C;
            }
            else
            {
                lastPtr_C->nextPtr = nowPtr_C;
                lastPtr_C = nowPtr_C;
            }
            if(lastPtr_C!=NULL)
                lastPtr_C->nextPtr = NULL;
        }
        currentPtr = currentPtr->nextPtr;
        if(currentPtr==NULL)
            break;
    }
    outputLIST(headPtr_A, 'A');
    outputLIST(headPtr_B, 'B');
    outputLIST(headPtr_C, 'C');
    freeHead(headPtr);
    freeHead(headPtr_A);
    freeHead(headPtr_B);
    freeHead(headPtr_C);
    return;
}