#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct graph graph;
typedef struct vertex *vertexptr;
typedef struct vertex vertex;

typedef struct Node node;
typedef struct Node *nodeptr;
typedef struct Node *Stack;

int root;

struct Node
{
    long long int src;
    long long int dest;
    nodeptr next;
};

struct vertex
{
    long long int name;
    vertexptr next;
};
struct graph
{
    long long int V;
    long long int E;
    vertexptr *vertices;
    bool *array_visited;
    long long int *count;
};
int IsEmpty(Stack S)
{
    return (S->next == NULL);
}
Stack CreateEmptyStack()
{
    Stack S;
    S = malloc(sizeof(node));
    assert(S != NULL);

    S->next = NULL;

    return S;
}

void PushOnStack(nodeptr P, Stack S)
{
    P->next = S->next;
    S->next = P;
}

nodeptr PopOffSTack(Stack S)
{
    if (IsEmpty(S) == 0)
    {
        nodeptr P;
        P = S->next;
        S->next = P->next;
        return P;
    }
    else
        return NULL;
}

graph *CreateGraph(long long int V, long long int E)
{
    graph *G;
    G = malloc(sizeof(graph));
    assert(G != NULL);
    G->V = V;
    G->E = E;
    G->vertices = malloc(sizeof(vertexptr) * ((G->V) + 1));
    assert(G->vertices != NULL);
    for (long long int i = 1; i < (G->V) + 1; i++)
    {
        G->vertices[i] = malloc(sizeof(vertex));
        G->vertices[i]->name = i;
        G->vertices[i]->next = NULL;
        //G->vertices[i]->weight = INT_MAX;
    }
    G->array_visited = malloc(sizeof(bool) * 1000001);
    assert(G->array_visited != NULL);
    for (int i = 0; i < 1000001; i++)
    {
        G->array_visited[i] = false;
    }
    G->count = malloc(sizeof(long long int) * G->V + 1);
    assert(G->count != NULL);
    for (int i = 0; i < G->V + 1; i++)
    {
        G->count[i] = 0;
    }

    return G;
}
void Insert_DirectedEdge(graph *G, long long int src, long long int dest)
{
    vertexptr new_vertex;
    new_vertex = malloc(sizeof(vertex));
    assert(new_vertex != NULL);
    new_vertex->name = dest;
    //new_vertex->weight = weight;
    new_vertex->next = G->vertices[src]->next;

    G->vertices[src]->next = new_vertex;
}

void PrintGraph(graph *G)
{
    long long int i;
    vertexptr p;
    for (i = 1; i < G->V + 1; i++)
    {
        p = G->vertices[i]->next;
        while (p != NULL)
        {
            printf("%lld---%lld\n", G->vertices[i]->name, p->name);
            p = p->next;
        }
        //prlong long intf("%d--(%d)--%d\n", G->edges[i].src, G->edges[i].weight, G->edges[i].dest);
    }
}

void DFSForGraphs(graph *G, int src, bool *array_visited)
{
    array_visited[src] = true;
    G->array_visited[src] = true;

    //printf("%lld ", G->vertices[src]->name);

    vertexptr p;
    p = G->vertices[src]->next;
    while (p != NULL)
    {
        if (array_visited[p->name] == false)
        {
            DFSForGraphs(G, p->name, array_visited);
        }
        G->count[root]++;
        p = p->next;
    }
}

void makeFalse(bool *array_visited)
{
    for (int j = 0; j < 1000001; j++)
    {
        array_visited[j] = false;
    }
}

int main()
{
    long long int integer;
    long long int V, E;
    long long int *array_indegree;
    scanf("%lld %lld", &V, &E);
    graph *G, *GT;

    long long int src, dest;
    G = CreateGraph(V, E);
    GT = CreateGraph(V, E);

    for (long long int i = 0; i < E; i++)
    {
        scanf("%lld %lld", &src, &dest);
        Insert_DirectedEdge(G, src, dest);
        Insert_DirectedEdge(GT, dest, src);
    }

    bool *array_visited;
    array_visited = malloc(sizeof(bool) * 1000001);
    assert(array_visited != NULL);

    long long int temp_max = INT_MIN;
    int store;

    for (int i = 1; i < G->V + 1; i++)
    {
        vertexptr p;
        p = G->vertices[i]->next;
        if (G->array_visited[i] == false)
        {
            root = i;
            DFSForGraphs(G, i, array_visited);
            makeFalse(array_visited);
            if (temp_max < G->count[root])
            {
                temp_max = G->count[root];
                store = root;
            }
        }
    }
    //PrintIndegree(array_indegree, G->V);

    printf("%d\n", store);
}