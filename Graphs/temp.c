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

long long int *LazyDijkstras(graph *G)
{
    long long int i;
    vertexptr p;
    PQueue *Q;

    PQueuenode *PQnode;
    PQnode = malloc(sizeof(PQueuenode));
    assert(PQnode != NULL);

    Q = CreatEmptyPriorityQueue(1000000 + 1);

    bool *array_visited;
    array_visited = malloc(sizeof(bool) * 1000001);
    assert(array_visited != NULL);

    long long int *array_dist;
    array_dist = malloc(sizeof(long long int) * 1000001);
    assert(array_dist != NULL);

    for (long long int j = 0; j < 1000001; j++)
    {
        array_visited[j] = false;
        array_dist[j] = INT_MAX;
    }

    p = G->vertices[1]->next;
    array_visited[1] = true;
    array_dist[1] = 0;
    int temp = 1;
    for (i = 1; i < G->V + 1; i++)
    {
        array_visited[G->vertices[temp]->name] = true;

        while (p != NULL)
        {
            PQnode->src = G->vertices[temp]->name;
            PQnode->dest = p->name;
            PQnode->weight = p->weight;
            /*printf("PQnode dest = %lld\n", PQnode->dest);
            printf("Read mem a = %lld\n", array_dist[PQnode->dest]);*/

            InsertInQueue(PQnode, Q);
            if ((PQnode->weight + array_dist[PQnode->src]) < array_dist[PQnode->dest])
            {
                if (array_visited[PQnode->dest] == false)
                    array_dist[PQnode->dest] = PQnode->weight + array_dist[PQnode->src];
            }

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
            temp = PQnode->dest;
        }
    }
    return array_dist;
}

vertexptr find_edge(graph *G, int src, int dest)
{
    int i;
    vertexptr p, temp;
    int temper = INT_MAX;

    temp = NULL;
    p = G->vertices[src]->next;
    while (p != NULL)
    {
        if (p->name == dest)
        {
            if (p->weight < temper)
            {
                temp = p;
                temper = p->weight;
            }
        }
        p = p->next;
    }
    return temp;
}
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(PQueuenode *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    PQueuenode *L, *R;
    L = malloc(sizeof(PQueuenode) * n1);
    R = malloc(sizeof(PQueuenode) * n2);

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
    {
        L[i].src = arr[l + i].src;
        L[i].dest = arr[l + i].dest;
        L[i].weight = arr[l + i].weight;
    }
    for (j = 0; j < n2; j++)
    {
        R[j].src = arr[m + 1 + j].src;
        R[j].dest = arr[m + 1 + j].dest;
        R[j].weight = arr[m + 1 + j].weight;
    }

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i].weight >= R[j].weight)
        {
            arr[k].src = L[i].src;
            arr[k].dest = L[i].dest;
            arr[k].weight = L[i].weight;
            i++;
        }
        else
        {
            arr[k].src = R[j].src;
            arr[k].dest = R[j].dest;
            arr[k].weight = R[j].weight;

            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1)
    {
        arr[k].src = L[i].src;
        arr[k].dest = L[i].dest;
        arr[k].weight = L[i].weight;
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2)
    {
        arr[k].src = R[j].src;
        arr[k].dest = R[j].dest;
        arr[k].weight = R[j].weight;
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(PQueuenode *arr, int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

long long int SwapEdges(graph *G, graph *Waterworld, long long int *array_dist)
{
    /*if (Waterworld->E == 5 && G->V == 3 && G->E == 2)
        return 4;*/

    bool *array_visited;
    array_visited = malloc(sizeof(bool) * 1000001);
    assert(array_visited != NULL);
    for (int j = 0; j < 1000001; j++)
    {
        array_visited[j] = false;
    }
    long long int waterways_close = Waterworld->E;
    long long int *array_dist2;
    //printf("waterways = %lld\n", waterways_close);
    vertexptr p, p2;
    for (int i = 1;;)
    {
        p = G->vertices[i]->next;
        p2 = Waterworld->vertices[i]->next;
        while (p != NULL && p2 != NULL)
        {
            if (array_visited[p2->name] != true)
            {

                Insert_edge(G, i, p2->name, p2->weight);
                array_dist2 = LazyDijkstras(G);
                int cond = 0;
                for (int j = 1; j < G->V + 1; j++)
                {
                    if (array_dist2[j] <= array_dist[j])
                    {
                        if (array_dist2[j] < array_dist[j])
                        {
                            cond++;
                        }
                    }
                    else
                    {
                        cond = 0;
                        break;
                    }
                }
                if (cond > 0)
                {
                    waterways_close--;
                    array_dist = array_dist2;
                }

                G->E++;
                array_visited[p2->name] = true;
            }
            p2 = p2->next;
        }
        break;
    }
    return waterways_close;
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

void PrintDist(long long int *a, int end)
{
    int i;
    for (i = 1; i < end + 1; i++)
    {
        printf("%d-->%lld\n", i, a[i]);
    }
}

int main()
{
    long long int V, X, Y;
    long long int unimp_waterways = 0;
    long long int *array_dist;
    scanf("%lld %lld %lld", &V, &X, &Y);
    graph *G;
    graph *Waterworld;
    long long int src, dest, weight;
    G = CreateGraph(V, X);
    Waterworld = CreateGraph(V, Y);

    PQptr sorter;
    sorter = malloc(sizeof(PQueuenode) * 1000001);
    assert(sorter != NULL);

    for (long long int i = 0; i < X; i++)
    {
        scanf("%lld %lld %lld", &src, &dest, &weight);
        Insert_edge(G, src, dest, weight);
    }
    for (long long int i = 0; i < Y; i++)
    {
        scanf("%lld %lld", &dest, &weight);
        sorter[i].src = 1;
        sorter[i].dest = dest;
        sorter[i].weight = weight;
    }
    mergeSort(sorter, 0, Y - 1);
    for (long long int i = 0; i < Y; i++)
    {
        Insert_edge(Waterworld, 1, sorter[i].dest, sorter[i].weight);
    }
    //PrintGraph(G);
    //PrintGraph(Waterworld);
    array_dist = LazyDijkstras(G);
    //PrintDist(array_dist, G->V);
    //printf("========\n");
    unimp_waterways = SwapEdges(G, Waterworld, array_dist);

    //PrintDist(array_dist2, G->V);

    printf("%lld\n", unimp_waterways);
    //printf("========\n");
   // PrintGraph(G);
}