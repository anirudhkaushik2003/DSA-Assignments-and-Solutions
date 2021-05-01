#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void InitilizeToZero(int a[], int count1[])
{
    for (int i = 0; i < 20; i++)
    {
        count1[i] = a[i];
    }
}
void InitilizeTo0(int a[], int count1[])
{
    for (int i = 0; i < 20; i++)
    {
        count1[i] = a[i];
    }
}
void topleft(int z, int count[], int k, int N, int a[N][N])
{
    for (int i = 0; i < 20; i++)
    {
        count[i] = 0;
    }
    //printArray(count, 20);
    for (int x = z; x < z + k; x++)
    {

        for (int y = 0; y < k; y++)
        {
            //printf("x = %d y = %d\n", x, y);
            count[(a[x][y]) - 1]++;
        }
    }
    //printArray(count, 20);
}
int FindMedian(int count[], int size)
{
    //printArray(count, 20);

    int temp = 0;

    for (int i = 0; i < 20; i++)
    {
        temp += count[i];
        if (temp >= ((size + 1) / 2))
        {
            return (i + 1);
        }
    }
}

int main()
{

    int N, k;
    scanf("%d %d", &N, &k);
    int i, j;
    int a[N][N];

    for (i = 0; i < N; i++)
    {

        for (j = 0; j < N; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int count[20];

    int temp1;

    //printf("%d ", A[((k * k) / 2)]);
    for (int z = 0; z <= N - k; z++)
    {
        topleft(z, count, k, N, a);
        //printArray(count, 20);

        temp1 = FindMedian(count, (k * k));
        printf("%d ", temp1);
        for (j = 0; j < N - k; j++)
        {
            //printf("reached\n");
            for (i = z; i < z + k; i++)
            {
                count[a[i][j] - 1]--;
                count[a[i][j + k] - 1]++;
            }

            //printArray(count, 20);

            temp1 = FindMedian(count, (k * k));
            printf("%d ", temp1);
        }
        printf("\n");
    }
}
