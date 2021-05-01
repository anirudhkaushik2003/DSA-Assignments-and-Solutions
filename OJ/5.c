#include <stdio.h>
#include <stdlib.h>

long long int N;

void merge(long long int arr[], int l, int m, int r)
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
void mergeSort(long long int arr[], int l, int r)
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

int binarySearch(long long int arr[], int l, int r, int x)
{

    int mid = l + (r - l) / 2;
    if (x <= arr[0])
    {
        return 0;
    }
    if (x >= arr[N - 1])
    {
        return N - 1;
    }
    if (r >= l)
    {

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
    return mid;
}

int greatestlesser(long long int a[], int low, int high, int key)
{
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low + 1) / 2;
        int midVal = a[mid];

        if (midVal < key)
        {

            // if mid is less than key, all elements
            // in range [low, mid - 1] are < key
            // we note down the last found index, then
            // we search in right side of mid
            // so we now search in [mid + 1, high]
            ans = mid;
            low = mid + 1;
        }
        else if (midVal > key)
        {

            // if mid is greater than key, all elements
            // in range [mid + 1, high] are > key
            // then we search in left side of mid
            // so we now search in [low, mid - 1]
            high = mid - 1;
        }
        else if (midVal == key)
        {

            // if mid is equal to key, all elements
            // in range [mid + 1, high] are >= key
            // then we search in left side of mid
            // so we now search in [low, mid - 1]
            high = mid - 1;
        }
    }

    return ans;
}
int leastgreater(long long int a[], int low, int high, int key)
{
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low + 1) / 2;
        int midVal = a[mid];

        if (midVal < key)
        {

            // if mid is less than key, all elements
            // in range [low, mid - 1] are <= key
            // then we search in right side of mid
            // so we now search in [mid + 1, high]
            low = mid + 1;
        }
        else if (midVal > key)
        {

            // if mid is greater than key, all elements
            // in range [mid + 1, high] are >= key
            // we note down the last found index, then
            // we search in left side of mid
            // so we now search in [low, mid - 1]
            ans = mid;
            high = mid - 1;
        }
        else if (midVal == key)
        {

            // if mid is equal to key, all elements in
            // range [low, mid] are <= key
            // so we now search in [mid + 1, high]
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    long long int Q, K, count;
    scanf("%lld %lld %lld", &N, &Q, &K);
    int i;
    long long int a[N], b[N];
    long long int X, val;
    for (i = 0; i < N; i++)
    {
        scanf("%lld", &a[i]);
        b[i] = a[i];
    }
    mergeSort(b, 0, N - 1);
    int index, temp1, temp2, index1;
    while (Q > 0)
    {
        count = 0;
        scanf("%lld %lld", &X, &val);

        index = binarySearch(b, 0, N - 1, val);

        //printf("index = %d\n", index);
        /* if (index + K < N)
            count = X - 1 - (index + K);
        else
            count = 0;
        for (i = index; i < index + K && i < N; i++)
        {
            if (a[i] > val)
            {
                count++;
            }
        }
        for (i = index - 1; i >= index - K && i >= 0; i--)
        {
            if (a[i] > val)
            {
                count++;
            }
        }*/

        int lower_bound = index - K, upper_bound = index + K;
        //int count = 0;
        if (lower_bound < 0)
        {
            lower_bound = 0;
        }
        if (upper_bound > X)
        {
            upper_bound = X;
        }
        for (i = lower_bound; i < upper_bound; i++)
        {
            if (a[i] > val)
            {
                count++;
            }
        }
        count += X - upper_bound;

        //printf("index1 = %d\n", index1);
        printf("%d\n", count);
        Q--;
    }
}