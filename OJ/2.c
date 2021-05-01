#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct Node node;

struct Node
{
    long long int position;
    char name[21];
    int order;
};

void merge(node arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    node *L, *R;
    L = malloc(sizeof(node) * n1);
    assert(L != NULL);
    R = malloc(sizeof(node) * n2);
    assert(R != NULL);

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
    {
        L[i].position = arr[l + i].position;
        strcpy(L[i].name, arr[l + i].name);
        L[i].order = arr[l + i].order;
    }
    for (j = 0; j < n2; j++)
    {
        R[j].position = arr[m + 1 + j].position;
        strcpy(R[j].name, arr[m + 1 + j].name);
        R[j].order = arr[m + 1 + j].order;
    }

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i].position < R[j].position)
        {
            arr[k].position = L[i].position;
            strcpy(arr[k].name, L[i].name);
            i++;
        }
        else
        {
            if (L[i].position == R[j].position)
            {
                if (L[i].order < R[j].order)
                {
                    arr[k].position = L[i].position;
                    strcpy(arr[k].name, L[i].name);
                    i++;
                }
                else
                {
                    arr[k].position = R[j].position;
                    strcpy(arr[k].name, R[j].name);
                    j++;
                }
            }
            else
            {
                arr[k].position = R[j].position;
                strcpy(arr[k].name, R[j].name);
                j++;
            }
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1)
    {
        arr[k].position = L[i].position;
        strcpy(arr[k].name, L[i].name);
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2)
    {
        arr[k].position = R[j].position;
        strcpy(arr[k].name, R[j].name);
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(node arr[], int l, int r)
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

int main()
{
    int N;
    scanf("%d", &N);
    node *a;
    a = malloc(sizeof(node) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld %s", &a[i].position, &a[i].name);
        a[i].order = i;
    }
    mergeSort(a, 0, N - 1);
    for (int i = 0; i < N; i++)
    {
        printf("%lld %s\n", a[i].position, a[i].name);
    }
}