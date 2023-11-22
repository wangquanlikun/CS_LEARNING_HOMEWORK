#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

int count_return_int(NODE *head){
    int nodenum = 0;
    NODE *currentPtr = head;
    while(currentPtr->next != NULL){
        nodenum++;
        currentPtr = currentPtr->next;
    }
    return nodenum;
}

NODE *create();
void instrt(NODE *,int);
void delete(NODE *,int);
void revert(NODE *);
void dump(NODE *);
void verify(NODE *);
void count(NODE *);
void sum(NODE *);
void destroy(NODE *);

int main(){
    char command[20];
    NODE *head = NULL;
    while (1){
        scanf("%s",command);
        if(strcmp(command,"create")==0 || strcmp(command,"CREATE")==0)
            head = create();
        else if(head != NULL && (strcmp(command,"insert")==0 || strcmp(command,"INSERT")==0)){
            int data;
            scanf("%d",&data);
            instrt(head,data);
        }
        else if(head != NULL && (strcmp(command,"delete")==0 || strcmp(command,"DELETE")==0)){
            int data;
            scanf("%d",&data);
            delete(head,data);
        }
        else if(head != NULL && (strcmp(command,"revert")==0 || strcmp(command,"REVERT")==0))
            revert(head);
        else if(head != NULL && (strcmp(command,"dump")==0 || strcmp(command,"DUMP")==0))
            dump(head);
        else if(head != NULL && (strcmp(command,"verify")==0 || strcmp(command,"VERIFY")==0))
            verify(head);
        else if(head != NULL && (strcmp(command,"count")==0 || strcmp(command,"COUNT")==0))
            count(head);
        else if(head != NULL && (strcmp(command,"sum")==0 || strcmp(command,"SUM")==0))
            sum(head);
        else if(head != NULL && (strcmp(command,"destroy")==0 || strcmp(command,"DESTROY")==0))
            destroy(head);
        else if(strcmp(command,"bye")==0 || strcmp(command,"BYE")==0)
            break;
        else if(head == NULL)
            printf("Please use command CREATE first\n");
        else
            printf("Error Command\n");
    }
    return 0;
}

NODE *create(){
    NODE *head;
    head = malloc(sizeof(NODE));
    head->data = 0;
    head->next = NULL;
    return head;
}

void instrt(NODE *head,int inputdata){
    NODE* newnode;
    newnode = malloc(sizeof(NODE));
    newnode->data = inputdata;
    newnode->next = NULL;

    NODE *previousPtr = head;
    NODE *currentPtr = head->next;
    for (; currentPtr != NULL; previousPtr = currentPtr, currentPtr = currentPtr->next){
        if(currentPtr->data < inputdata)
            continue;
        else{
            newnode->next = currentPtr;
            previousPtr->next = newnode;
            return;
        }
    }
    if (currentPtr == NULL)
        previousPtr->next = newnode;
    return;
}

void delete(NODE *head, int inputdata){
    NODE *previousPtr = head;
    NODE *currentPtr = head->next;
    for (; currentPtr != NULL;){
        if(currentPtr->data == inputdata){
            currentPtr = currentPtr->next;
            previousPtr->next = currentPtr;
        }
        else{
            previousPtr = previousPtr->next;
            currentPtr = currentPtr->next;
        }
    }
    return;
}

void revert(NODE *head){
    NODE *currentPtr = head;
    NODE *last = NULL;
    while(currentPtr->next != NULL)
        currentPtr = currentPtr->next;
    last = currentPtr;

    if(count_return_int(head) == 0 || count_return_int(head) == 1)
        return;
    else if(count_return_int(head) == 2){
        NODE *cachePtr = head->next;
        head->next = last;
        last->next = cachePtr;
        cachePtr->next = NULL;
        return;
    }
    else{
        NODE *previousPtr = head;
        currentPtr = head->next;
        while(currentPtr != NULL){
            NODE *cachePtr = currentPtr->next;
            currentPtr->next = previousPtr;
            previousPtr = currentPtr;
            currentPtr = cachePtr;
        }
        head->next->next = NULL;
        head->next = last;
    }
    return;
}

void dump(NODE *head){
    NODE *currentPtr = head->next;
    printf("DUMP: ");
    if(currentPtr == NULL){
        printf("NULL LIST\n");
        return;
    }
    while(currentPtr != NULL){
        printf("%d ", currentPtr->data);
        currentPtr = currentPtr->next;
    }
    printf("\n");
    return;
}

void verify(NODE *head){
    NODE *currentPtr = head->next;
    int issort = 1;
    if(currentPtr == NULL){
        printf("NULL LIST\n");
        return;
    }
    while(currentPtr->next != NULL){
        if(currentPtr->data > currentPtr->next->data){
            issort = 0;
            break;
        }
        currentPtr = currentPtr->next;
    }
    if(issort)
        printf("VERIFY RIGHT\n");
    else
        printf("VERIFY WRONG\n");
    return;
}

void count(NODE *head){
    int nodenum = 0;
    NODE *currentPtr = head;
    while(currentPtr->next != NULL){
        nodenum++;
        currentPtr = currentPtr->next;
    }
    printf("COUNT %d\n", nodenum);
    return;
}

void sum(NODE *head){
    int sum = 0;
    NODE *currentPtr = head->next;
    while(currentPtr != NULL){
        sum += currentPtr->data;
        currentPtr = currentPtr->next;
    }
    printf("SUM %d\n", sum);
    return;
}

void destroy(NODE *head){
    NODE *prePtr, *currentPtr;
    prePtr = head;
    currentPtr = head->next;
    while(currentPtr != NULL){
        free(prePtr);
        prePtr = currentPtr;
        currentPtr = currentPtr->next;
    }
    free(prePtr);
    return;
}
