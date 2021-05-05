#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct graph graph;
typedef struct vertex *vertexptr;
typedef struct vertex vertex;

typedef struct PQueuenode PQueuenode;
typedef struct PQueue PQueue;
typedef struct PQueuenode *PQptr;

struct vertex
{
    long long int name;
    long long int weight;
    vertexptr next;
};
struct graph
{
    long long int V;
    long long int E;
    vertexptr *vertices;
};

struct PQueuenode
{
    long long int src;
    long long int dest;
    long long int weight;
};

struct PQueue
{
    long long int size;
    PQptr PQ;
    long long int capacity;
};

PQueue *CreatEmptyPriorityQueue(long long int size)
{
    PQueue *Priority_Q;
    Priority_Q = malloc(sizeof(PQueue));
    Priority_Q->PQ = malloc(sizeof(PQueuenode) * size);

    Priority_Q->PQ[0].dest = 0;
    Priority_Q->PQ[0].weight = INT_MIN;
    Priority_Q->PQ[0].src = 0;

    Priority_Q->size = 0;
    Priority_Q->capacity = size - 1;

    return Priority_Q;
}

long long int IsFull(PQueue *Priority_Q)
{
    if (Priority_Q->size == Priority_Q->capacity)
    {
        return 1;
    }
    else
        return 0;
}
long long int IsEmpty(PQueue *Priority_Q)
{
    if (Priority_Q->size == 0)
    {
        return 1;
    }
    else
        return 0;
}

void InsertInQueue(PQueuenode *PQnode, PQueue *Priority_Q)
{
    long long int i;
    if (IsFull(Priority_Q))
    {
        //prlong long intf("Error Priority Queue is full!\n");
        return;
    }
    for (i = ++Priority_Q->size; Priority_Q->PQ[i / 2].weight > PQnode->weight; i /= 2)
    {
        Priority_Q->PQ[i].dest = Priority_Q->PQ[i / 2].dest;
        Priority_Q->PQ[i].src = Priority_Q->PQ[i / 2].src;
        Priority_Q->PQ[i].weight = Priority_Q->PQ[i / 2].weight;
    }
    Priority_Q->PQ[i].src = PQnode->src;
    Priority_Q->PQ[i].dest = PQnode->dest;
    Priority_Q->PQ[i].weight = PQnode->weight;
    //prlong long intf("Priority Queue size = %d\n", Priority_Q->size);
}

PQueuenode *ExtractMin(PQueue *Priority_Q)
{
    long long int i, child;
    PQptr MinElem, LastElem;

    MinElem = malloc(sizeof(PQueuenode));
    LastElem = malloc(sizeof(PQueuenode));

    if (IsEmpty(Priority_Q))
    {
        //prlong long intf("Error Priority Queue is empty!\n");
        return NULL;
    }
    MinElem->dest = Priority_Q->PQ[1].dest;
    MinElem->weight = Priority_Q->PQ[1].weight;
    MinElem->src = Priority_Q->PQ[1].src;

    LastElem->dest = Priority_Q->PQ[Priority_Q->size].dest;
    LastElem->weight = Priority_Q->PQ[Priority_Q->size].weight;
    LastElem->src = Priority_Q->PQ[Priority_Q->size--].src;

    for (i = 1; i * 2 <= Priority_Q->size; i = child)
    {
        child = i * 2;
        if (child != Priority_Q->size && (Priority_Q->PQ[child + 1].weight < Priority_Q->PQ[child].weight))
        {
            child++;
        }
        if (LastElem->weight > Priority_Q->PQ[child].weight)
        {
            Priority_Q->PQ[i].weight = Priority_Q->PQ[child].weight;
            Priority_Q->PQ[i].src = Priority_Q->PQ[child].src;
            Priority_Q->PQ[i].dest = Priority_Q->PQ[child].dest;
        }
        else
            break;
    }
    Priority_Q->PQ[i].dest = LastElem->dest;
    Priority_Q->PQ[i].src = LastElem->src;
    Priority_Q->PQ[i].weight = LastElem->weight;

    return MinElem;
}

graph *CreateGraph(long long int V, long long int E)
{
    graph *G;
    G = malloc(sizeof(graph));
    assert(G != NULL);
    G->V = V;
    G->E = E;
    G->vertices = malloc(sizeof(vertexptr) * ((G->V) + 1));
    for (long long int i = 1; i < (G->V) + 1; i++)
    {
        G->vertices[i] = malloc(sizeof(vertex));
        G->vertices[i]->name = i;
        G->vertices[i]->next = NULL;
        G->vertices[i]->weight = INT_MAX;
    }
    assert(G->vertices != NULL);

    return G;
}
void Insert_edge(graph *G, long long int src, long long int dest, long long int weight)
{
    vertexptr new_vertex;
    new_vertex = malloc(sizeof(vertex));
    assert(new_vertex != NULL);
    new_vertex->name = dest;
    new_vertex->weight = weight;
    new_vertex->next = G->vertices[src]->next;

    G->vertices[src]->next = new_vertex;

    vertexptr double_edge;
    double_edge = malloc(sizeof(vertex));
    assert(double_edge != NULL);
    double_edge->name = src;
    double_edge->weight = weight;
    double_edge->next = G->vertices[dest]->next;

    G->vertices[dest]->next = double_edge;
}

unsigned long long int PrimsAlgoForMST(graph *G)
{
    long long int i;
    vertexptr p;
    PQueue *Q;

    PQueuenode *PQnode;
    PQnode = malloc(sizeof(PQueuenode));
    assert(PQnode != NULL);

   unsigned long long int MSTcost = 0;
    Q = CreatEmptyPriorityQueue(1000000 + 1);

    bool *array_visited;
    array_visited = malloc(sizeof(bool) * 1000001);
    assert(array_visited != NULL);

    for (long long int j = 0; j < 1000001; j++)
    {
        array_visited[j] = false;
    }

    p = G->vertices[1]->next;
    array_visited[1] = true;
    int temp = 1;

    for (i = 1; i < G->V + 1; i++)
    {

        while (p != NULL)
        {
            PQnode->src = G->vertices[temp]->name;
            PQnode->dest = p->name;
            PQnode->weight = p->weight;

            InsertInQueue(PQnode, Q);

            p = p->next;
        }
        while (PQnode != NULL)
        {
            PQnode = ExtractMin(Q);
            if (PQnode == NULL)
                break;
            else
            {
                if (array_visited[PQnode->dest] == false)
                {
                    break;
                }
            }
        }
        if (PQnode != NULL)
        {
            //prlong long intf("destination = %d\n", PQnode->dest);
            p = G->vertices[PQnode->dest]->next;
            array_visited[PQnode->dest] = true;
            temp = PQnode->dest;
            MSTcost += PQnode->weight;
        }
    }
    return MSTcost;
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
            printf("%lld--(%lld)--%lld\n", G->vertices[i]->name, p->weight, p->name);
            p = p->next;
        }
        //prlong long intf("%d--(%d)--%d\n", G->edges[i].src, G->edges[i].weight, G->edges[i].dest);
    }
}
int main()
{
    long long int V, E;
    scanf("%lld %lld", &V, &E);
    graph *G;
    long long int src, dest, weight;
    G = CreateGraph(V, E);
    for (long long int i = 0; i < E; i++)
    {
        scanf("%lld %lld %lld", &src, &dest, &weight);
        Insert_edge(G, src, dest, weight);
    }
    //Prlong long intGraph(G);

    printf("%llu\n", PrimsAlgoForMST(G));
}