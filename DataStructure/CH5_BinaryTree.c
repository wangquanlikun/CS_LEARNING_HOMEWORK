#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char data;
    struct node *lchild;
    struct node *rchild;
}Node;
typedef struct levelqueue{
    Node *treenode;
    int level;
} LevelQueue;

Node * createTree(char[], char[]);
void preOrder(Node *);
void inOrder(Node *);
void postOrder(Node *);
void levelOrder(Node *);
void printTree(Node *);
int getLevel(Node *);
int isCorrect(Node *);
Node * copyTree(Node *);
void swapTree(Node *);
void cutTree(Node *, char);
int destroyTree(Node *);

void printall(Node* root){
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    levelOrder(root);
    printf("\n");
    printTree(root);
}

int main(){
    char inputstrA[100], inputstrB[100];
    scanf("%s", inputstrA);
    scanf("%s", inputstrB);
    //层序序列和中序序列构造出二叉树
    Node *rootA =NULL;
    rootA = createTree(inputstrA, inputstrB);
    //打印二叉树的前序、中序、后序和层序序列
    //凹入表缩进方式打印二叉树
    printall(rootA);
    //求二叉树t的高度
    printf("Level = %d\n", getLevel(rootA));
    //验证性质
    printf("%s\n", isCorrect(rootA) ? "True" : "False");
    //拷贝二叉树t为新的二叉树t1
    Node *rootB;
    rootB = copyTree(rootA);
    //将二叉树t1左右子树交换，然后对t1执行打印
    swapTree(rootB);
    printall(rootB);
    //剪除t中值为E的节点以及其全部子孙，然后对t执行打印
    cutTree(rootA, 'E');
    printall(rootB);
    //销毁二叉树t和t1
    printf("%s\n",destroyTree(rootA) ? "Destroyed T" : "Failed");
    printf("%s\n",destroyTree(rootB) ? "Destroyed T1" : "Failed");
    return 0;
}

int _2power(int n){
    int ret = 1;
    for (int i = 0; i < n; i++)
        ret *= 2;
    return ret;
}

Node * createTree(char inputstrA[], char inputstrB[]){
    Node *root;
    if(strlen(inputstrA) == 0){
        root = NULL;
    }
    else if(strlen(inputstrA) != strlen(inputstrB)){
        printf("Invalid input\n");
        exit(0);
    }
    else if(strlen(inputstrA) == 1){
        root = (Node *)malloc(sizeof(Node));
        root->data = inputstrA[0];
        root->lchild = NULL;
        root->rchild = NULL;
    }
    else{
        root = (Node *)malloc(sizeof(Node));
        root->data = inputstrA[0];
        int posotion = strchr(inputstrB, inputstrA[0]) - inputstrB;
        int i = 0, p = 0, k = 0, maxlen = strlen(inputstrA);
        char ltreeA[100], rtreeA[100];
        char ltreeB[100], rtreeB[100];
        for (i = 1; i < maxlen; i++){
            if((strchr(inputstrB, inputstrA[i]) - inputstrB) < posotion){
                ltreeA[p] = inputstrA[i];
                p++;
            }else{
                rtreeA[k] = inputstrA[i];
                k++;
            }
        }
        ltreeA[p] = 0;
        rtreeA[k] = 0;
        for (i = 0; i < posotion; i++)
            ltreeB[i] = inputstrB[i];
        ltreeB[i] = 0;
        for (i = posotion + 1, p = 0; i <= maxlen; p++, i++)
            rtreeB[p] = inputstrB[i];
        rtreeB[p] = 0;
        root->lchild = createTree(ltreeA, ltreeB);
        root->rchild = createTree(rtreeA, rtreeB);
    }
    return root;
}

void preOrder(Node *root){
    if(root != NULL){
        printf("%c ", root->data);
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

void inOrder(Node *root){
    if(root != NULL){
        inOrder(root->lchild);
        printf("%c ", root->data);
        inOrder(root->rchild);
    }
}

void postOrder(Node *root){
    if(root != NULL){
        postOrder(root->lchild);
        postOrder(root->rchild);
        printf("%c ", root->data);
    }
}

void levelOrder(Node *root){
    if(root == NULL)
        return;
    Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while(front < rear){
        Node *temp = queue[front++];
        printf("%c ", temp->data);
        if(temp->lchild != NULL)
            queue[rear++] = temp->lchild;
        if(temp->rchild != NULL)
            queue[rear++] = temp->rchild;
    }
    return;
}

void printTree(Node *root){
    if(root == NULL)
        return;
    LevelQueue queue[100];
    int front = 0, rear = 0;
    queue[rear++].treenode = root;
    queue[rear].level = getLevel(root);
    int prelevel = getLevel(root);
    while(front < rear){
        Node *temp = queue[front++].treenode;
        int nowlevel = queue[front].level;
        if(nowlevel != prelevel){
            printf("\n");
            prelevel = nowlevel;
        }
        printf("%*s", _2power(nowlevel), " ");
        printf("%c", temp->data);
        printf("%*s", _2power(nowlevel), " ");
        
        if(temp->lchild != NULL){
            queue[rear++].treenode = temp->lchild;
            queue[rear].level = nowlevel - 1;
        }else if(nowlevel > 1){
            Node *cache = malloc(sizeof(Node));
            cache->data = ' ';
            cache->lchild = NULL;
            cache->rchild = NULL;
            queue[rear++].treenode = cache;
            queue[rear].level = nowlevel - 1;
        }
        if(temp->rchild != NULL){
            queue[rear++].treenode = temp->rchild;
            queue[rear].level = nowlevel - 1;
        }else if(nowlevel > 1){
            Node *cache = malloc(sizeof(Node));
            cache->data = ' ';
            cache->lchild = NULL;
            cache->rchild = NULL;
            queue[rear++].treenode = cache;
            queue[rear].level = nowlevel - 1;
        }
    }
    printf("\n");
    return;
}

int getLevel(Node *root){
    if(root == NULL){
        return 0;
    }
    int llevel = getLevel(root->lchild);
    int rlevel = getLevel(root->rchild);
    return (llevel > rlevel ? llevel : rlevel) + 1;
}

char find_min(Node *root){
    if(root == NULL)
        return 0;
    else{
        char retvalue = root->data;
        char lvalue = find_min(root->lchild);
        char rvalue = find_min(root->rchild);
        if(retvalue > lvalue && root->lchild != NULL)
            retvalue = lvalue;
        if(retvalue > rvalue && root->rchild != NULL)
            retvalue = rvalue;
        return retvalue;
    }
}

int isCorrect(Node *root){
    if(root == NULL)
        return 1;
    return (root->data == find_min(root)) && isCorrect(root->lchild) && isCorrect(root->rchild);
}

Node * copyTree(Node *root){
    if(root == NULL){
        return NULL;
    }
    Node *newroot = (Node *)malloc(sizeof(Node));
    newroot->data = root->data;
    newroot->lchild = copyTree(root->lchild);
    newroot->rchild = copyTree(root->rchild);
    return newroot;
}

void swapTree(Node *root){
    if(root == NULL){
        return;
    }
    Node *temp = root->lchild;
    root->lchild = root->rchild;
    root->rchild = temp;
    swapTree(root->lchild);
    swapTree(root->rchild);
    return;
}

void cutTree(Node *root, char data){
    if(root == NULL){
        return;
    }
    if(root->lchild != NULL && root->lchild->data == data){
        root->lchild = NULL;
    }
    if(root->rchild != NULL && root->rchild->data == data){
        root->rchild = NULL;
    }
    cutTree(root->lchild, data);
    cutTree(root->rchild, data);
    return;
}

int destroyTree(Node *root){
    if(root == NULL){
        return 0;
    }
    destroyTree(root->lchild);
    destroyTree(root->rchild);
    free(root);
    return 1;
}