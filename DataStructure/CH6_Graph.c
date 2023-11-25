#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

typedef struct adjacencynode{
    int weight;
    int ivertex;
    int jvertex;
    struct adjacencynode *ilink;
    struct adjacencynode *jlink;
} AdjacencyNode;

typedef struct graphnode{
    int vertex;
    wchar_t name[20];
    AdjacencyNode *firstedge;
} GraphNode;

typedef struct closedge{
    int adjvex;
    int lowcost;
} Closedge;

GraphNode* create(int);
void vertex(int, wchar_t[], GraphNode *);
void edge(int, int, int, GraphNode *);
void dump(GraphNode *);
void dfs(int, GraphNode *, int []);
void spanningTree(int, GraphNode *);
int shortestPath(int, int, GraphNode *);

int totalvertexnum = 0;

int main(){
    char command[20];
    scanf("%s", command);
    GraphNode *root = NULL;
    while(1){
        if(strcmp(command,"CREATE") == 0){
            int n;
            scanf("%d", &n);
            totalvertexnum = n;
            root = create(n);
        }
        else if(totalvertexnum == 0){
            printf("Please create a graph first!\n");
            continue;
        }
        else if(strcmp(command,"VERTEX") == 0){
            int n;
            wchar_t name[20];
            scanf("%d", &n);
            fgetws(name, 20, stdin);
            vertex(n, name, root);
        }
        else if(strcmp(command,"EDGE") == 0){
            int n1, n2, weight;
            scanf("%d %d %d", &n1, &n2, &weight);
            edge(n1, n2, weight, root);
        }
        else if(strcmp(command,"DUMP") == 0){
            dump(root);
        }
        else if(strcmp(command,"DFS") == 0){
            int visited[totalvertexnum];
            for(int i = 0; i < totalvertexnum; i++)
                visited[i] = 0;
            int n;
            scanf("%d", &n);
            dfs(n, root, visited);
        }
        else if(strcmp(command,"SPANNING-TREE") == 0){
            int n;
            scanf("%d", &n);
            spanningTree(n, root);
        }
        else if(strcmp(command,"SHORTEST-PATH") == 0){
            int n1, n2;
            scanf("%d %d", &n1, &n2);
            int shortest = shortestPath(n1, n2, root);
            if(shortest == -1)
                printf("No path!\n");
            else
                printf("Shortest path is %d\n", shortest);
        }
        else if(strcmp(command,"BYE") == 0){
            printf("Bye!\n");
            break;
        }
        else
            printf("Invalid command!\n");
        scanf("%s", command);
    }
    return 0;
}

GraphNode* create(int n){
    GraphNode *root = (GraphNode *)malloc(sizeof(GraphNode) * n);
    int i;
    for(i = 0; i < n; i++){
        wcscpy(root[i].name, L"");
        root[i].vertex = i;
        root[i].firstedge = NULL;
    }
    return root;
}

void vertex(int n, wchar_t name[], GraphNode *root){
    wcscpy(root[n].name, name);
    return;
}

void edge(int n1, int n2, int weight, GraphNode *root){
    AdjacencyNode *newnode = (AdjacencyNode *)malloc(sizeof(AdjacencyNode));
    newnode->weight = weight;
    newnode->ivertex = n1;
    newnode->jvertex = n2;
    newnode->ilink = NULL;
    newnode->jlink = NULL;

    if(root[n1].firstedge == NULL){
        root[n1].firstedge = newnode;
    }
    else{
        AdjacencyNode *temp = root[n1].firstedge;
        while((temp->ilink != NULL && temp->ivertex == n1) || (temp->jlink != NULL && temp->jvertex == n1)){
            while(temp->ilink != NULL && temp->ivertex == n1)
                temp = temp->ilink;
            while(temp->jlink != NULL && temp->jvertex == n1)
                temp = temp->jlink;
        }
        if(temp->ivertex == n1)
            temp->ilink = newnode;
        else if(temp->jvertex == n1)
            temp->jlink = newnode;
    }

    if(root[n2].firstedge == NULL){
        root[n2].firstedge = newnode;
    }
    else{
        AdjacencyNode *temp = root[n2].firstedge;
        while((temp->ilink != NULL && temp->ivertex == n2) || (temp->jlink != NULL && temp->jvertex == n2)){
            while(temp->ilink != NULL && temp->ivertex == n2)
                temp = temp->ilink;
            while(temp->jlink != NULL && temp->jvertex == n2)
                temp = temp->jlink;
        }
        if(temp->ivertex == n2)
            temp->ilink = newnode;
        else if(temp->jvertex == n2)
            temp->jlink = newnode;
    }
    return;
}

void dump(GraphNode *root){
    for(int i = 0; i < totalvertexnum; i++){
        printf("%d", root[i].vertex);
        wprintf(L" [%ls]: \t", root[i].name);
        AdjacencyNode *temp = root[i].firstedge;
        while(temp != NULL){
            printf("(%d, %d) -> %d\t", temp->ivertex, temp->jvertex, temp->weight);
            if(temp->ivertex == i)
                temp = temp->ilink;
            else if (temp->jvertex == i)
                temp = temp->jlink;
        }
        printf("\n");
    }
    return;
}

void dfs(int n, GraphNode *root, int visited[]){
    printf("%d", root[n].vertex);
    wprintf(L" [%ls]\n", root[n].name);
    visited[n] = 1;
    AdjacencyNode *temp = root[n].firstedge;
    while(temp != NULL){
        if(visited[temp->ivertex] == 0){
            dfs(temp->ivertex, root, visited);
        }
        if(visited[temp->jvertex] == 0){
            dfs(temp->jvertex, root, visited);
        }

        if(temp->ivertex == n)
            temp = temp->ilink;
        else if(temp->jvertex == n)
            temp = temp->jlink;
    }
    return;
}

void spanningTree(int n, GraphNode *root){
    Closedge closedge[totalvertexnum];
    int matrix[totalvertexnum][totalvertexnum];
    for(int i = 0; i < totalvertexnum; i++){
        for(int j = 0; j < totalvertexnum; j++){
            matrix[i][j] = 65535;
        }
    }
    for(int i = 0; i < totalvertexnum; i++){
        AdjacencyNode *temp = root[i].firstedge;
        while(temp != NULL){
            matrix[temp->ivertex][temp->jvertex] = temp->weight;
            matrix[temp->jvertex][temp->ivertex] = temp->weight;
            if(temp->ivertex == i)
                temp = temp->ilink;
            else if (temp->jvertex == i)
                temp = temp->jlink;
        }
    }
    int k = n;
    for(int i = 0; i < totalvertexnum; i++){
        closedge[i].adjvex = k;
        closedge[i].lowcost = matrix[k][i];
    }
    closedge[k].lowcost = 0;
    for(int i = 1; i < totalvertexnum; i++){
        int min = 65535;
        int minindex = k;
        for(int j = 0; j < totalvertexnum; j++){
            if(closedge[j].lowcost != 0 && closedge[j].lowcost < min){
                min = closedge[j].lowcost;
                minindex = j;
            }
        }
        printf("(%d, %d) -> %d\n", closedge[minindex].adjvex, minindex, closedge[minindex].lowcost);
        closedge[minindex].lowcost = 0;
        for(int j = 0; j < totalvertexnum; j++){
            if(matrix[minindex][j] < closedge[j].lowcost){
                closedge[j].adjvex = minindex;
                closedge[j].lowcost = matrix[minindex][j];
            }
        }
    }
    return;
}

int shortestPath(int n1, int n2, GraphNode *root){
    int matrix[totalvertexnum][totalvertexnum];
    for(int i = 0; i < totalvertexnum; i++){
        for(int j = 0; j < totalvertexnum; j++){
            matrix[i][j] = 65535;
        }
    }
    for(int i = 0; i < totalvertexnum; i++){
        AdjacencyNode *temp = root[i].firstedge;
        while(temp != NULL){
            matrix[temp->ivertex][temp->jvertex] = temp->weight;
            matrix[temp->jvertex][temp->ivertex] = temp->weight;
            if(temp->ivertex == i)
                temp = temp->ilink;
            else if (temp->jvertex == i)
                temp = temp->jlink;
        }
    }
    int visited[totalvertexnum];
    int distance[totalvertexnum];
    for(int i = 0; i < totalvertexnum; i++){
        visited[i] = 0;
        distance[i] = matrix[n1][i];
    }
    visited[n1] = 1;
    distance[n1] = 0;
    for(int i = 1; i < totalvertexnum; i++){
        int min = 65535;
        int minindex = n1;
        for(int j = 0; j < totalvertexnum; j++){
            if(visited[j] == 0 && distance[j] < min){
                min = distance[j];
                minindex = j;
            }
        }
        visited[minindex] = 1;
        for(int j = 0; j < totalvertexnum; j++){
            if(visited[j] == 0 && distance[j] > distance[minindex] + matrix[minindex][j]){
                distance[j] = distance[minindex] + matrix[minindex][j];
            }
        }
    }
    return distance[n2];
}
