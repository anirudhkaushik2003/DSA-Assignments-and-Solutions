#include "bst.h"

float a[4];
void dummy()
{
    srand(clock() * 373737);
}
tree *randombst(int N)
{
    dummy();
    int i, num;
    int array[N];
    //int a[N];
    for (i = 0; i < N; i++)
    {
        array[i] = 0;
    }
    tree *T = NULL;

    for (i = 0; i < N;)
    {
        num = (rand() % N) + 1;
        if (array[num - 1] == 0)
        {
            array[num - 1] = num;
            if (T == NULL)
                T = Insert(num, T);
            else
                Insert(num, T);
            i++;
        }
    }
    return T;
    //Print(T,0);
}

tree *Insert(int x, tree *T)
{
    if (T == NULL)
    {
        T = malloc(sizeof(tree));
        assert(T != NULL);

        T->data = x;
        T->left = NULL;
        T->right = NULL;
    }
    else
    {
        if (x < T->data)
        {
            T->left = Insert(x, T->left);
        }
        else
        {
            if (x > T->data)
            {
                T->right = Insert(x, T->right);
            }
        }
    }

    return T;
}

int height(tree *T)
{
    int left_height;
    int right_height;
    if (T != NULL)
    {
        left_height = height(T->left);
        right_height = height(T->right);
        if (left_height < right_height)
        {
            return right_height + 1;
        }
        else
        {
            return left_height + 1;
        }
    }
    else
        return -1;
}
void avgdepth()
{

    int i;
    _avgdepth(10.0);

    for (i = 0; i < 4; i++)
    {
        printf("%.6lf ", a[i]);
    }
    printf("\n");
    //sleep(1);
    _avgdepth(50.0);

    for (i = 0; i < 4; i++)
    {
        printf("%.6lf ", a[i]);
    }
    printf("\n");
    //sleep(1);
    _avgdepth(100.0);

    for (i = 0; i < 4; i++)
    {
        printf("%.6lf ", a[i]);
    }
    printf("\n");
    //sleep(1);
    _avgdepth(1000.0);

    for (i = 0; i < 4; i++)
    {
        printf("%.6lf ", a[i]);
    }
    printf("\n");
}
void _avgdepth(float m)
{
    int i;
    float sum = 0;
    tree *root;
    float avg_depth;
    // printf("m = %lf\n", m);
    for (i = 0; i < m; i++)
    {
        srand((unsigned)time(NULL));
        //tree *root;
        root = randombst(10);
        //printf("done %d\n",i+1);
        sum += height(root);
        free(root);
    };
    avg_depth = (float)sum / (float)m;
    a[0] = avg_depth;
    sum = 0;
    //printf("%lf\n", avg_depth);
    for (i = 0; i < m; i++)
    {
        srand((unsigned)time(NULL));
        //tree *root;
        root = randombst(50);
        sum += height(root);
    }
    avg_depth = sum / m;
    a[1] = avg_depth;
    sum = 0;
    //printf("done\n");
    for (i = 0; i < m; i++)
    {
        srand((unsigned)time(NULL));
        //tree *root;
        root = randombst(100);
        sum += height(root);
    }
    avg_depth = (float)sum / (float)m;
    a[2] = avg_depth;
    //printf("done\n");
    sum = 0;
    for (i = 0; i < m; i++)
    {
        srand((unsigned)time(NULL));
        //tree *root;
        root = randombst(1000);
        sum += height(root);
    }
    avg_depth = (float)sum / (float)m;
    a[3] = avg_depth;
    sum = 0;
    //printf("done\n");
}

void Print(tree *T, int depth)
{
    tree *cur;
    cur = T;
    int dep;
    dep = depth;
    if (T != NULL)
    {

        while (depth > 0)
        {

            printf("_");
            depth--;
            if (depth == 1)
            {
                //printf("|");
            }
        }

        printf("%d\n", cur->data);
        printf("|");
        Print(cur->left, dep + 1);
        depth = dep;

        Print(cur->right, dep + 1);
    }
}

/*void sort(int array[])
{
    for ()
}*/