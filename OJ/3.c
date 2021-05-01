#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int count = 0;
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
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

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int countOccurrences(int arr[], int n, int x)
{
    int ind = binarySearch(arr, 0, n - 1, x);

    // If element is not present
    if (ind == -1)
        return 0;

    // Count elements on left side.
    int count = 1;
    int left = ind - 1;
    while (left >= 0 && arr[left] == x)
        count++, left--;

    // Count elements on right side.
    int right = ind + 1;
    while (right < n && arr[right] == x)
        count++, right++;

    return count;
}

int main()
{

    int i, j, l;
    int N, k;
    long long int x;
    scanf("%d", &N);
    //printf("n = %d and k = %d\n",N,k);
    int *a;
    a = malloc(sizeof(int) * N);
    assert(a != NULL);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
        //printf("%d ", a[i]);
    }
    scanf("%lld", &x);
    int *b;
    b = malloc(sizeof(long long int) * N + 1);
    assert(b != NULL);
    /*int **matrix;
    matrix = malloc(sizeof(int *) * N);
    assert(matrix != NULL);*/
    /*int **temp;
    temp = malloc(sizeof(int *) * N);
    assert(temp != NULL);*/
    long long int sum = 0;
    b[0] = 0;
    int temp = 0;
    for (int i = 0; i < N; i++)
    {
        temp += a[i];
        b[i + 1] = temp;
    }
    /*printf("B = ");
    printArray(b, N + 1);*/
    for (k = 1; k <= N; k++)
    {
        if (x % k == 0)
        {
            int *W;
            W = malloc(sizeof(long long int) * (N - k + 1));
            assert(W != NULL);

            for (i = 0; i < N - k + 1; i++)
            {

                W[i] = b[i + k] - b[i];
                //t[i] = 0;
            }

            //printf("W = ");
            //printArray(W, N - k + 1);

            mergeSort(W, 0, N - k);

            //printf("t = ");
            //printArray(t, N - k + 1);
            int val_x;
            int d;
            d = x / k;
            int temp1, count_x;
            //int k_boi;

            for (i = 0; i < N - k + 1; i++)
            {
                val_x = ((d)-W[i]);
                temp1 = binarySearch(W, 0, N - k, val_x);
                if (temp1 != -1)
                {
                    count_x = countOccurrences(W, N - k + 1, val_x);
                    count += count_x;
                }
            }
            for (i = 0; i < N - k + 1; i++)
            {
                val_x = ((x / k) - W[i]);
            }
            free(W);
        }
    }
    // printArray(t, N - k + 1);
    printf("%d\n", count);
}