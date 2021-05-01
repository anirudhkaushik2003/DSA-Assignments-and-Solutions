#include "hash.h"

Index Hash(const char *key, const int TableSize)
{
    unsigned int HashVal = 0;
    while (*key != '\0')
    {
        HashVal = (HashVal << 5) ^ *key++;
    }
    return (HashVal % TableSize);
}

hashtbl *InitializeTable(int N)
{
    hashtbl *H;
    H = malloc(sizeof(hashtbl)); //pointer to dynamically allocated array
    assert(H != NULL);
    H->TableSize = N;

    H->array = malloc(sizeof(list) * H->TableSize);
    assert(H->array != NULL);
    for (int i = 0; i < H->TableSize; i++)
    {
        H->array[i].occupied = false;
    }
    return H;
}

void Insert(char *key, hashtbl *H)
{
    int i, aux;
    for (i = 0; i < H->TableSize; i++)
    {
        aux = (Hash(key, H->TableSize) + i) % H->TableSize;
        if (H->array[aux].occupied == false)
        {
            strcpy(H->array[aux].word, key);

            H->array[aux].occupied = true;
            return;
        }
    }
}
void PrintList(hashtbl *H)
{
    int i;
    printf("=============\n");
    for (i = 0; i < H->TableSize; i++)
    {
        printf("%s\n", H->array[i].word);
    }
    printf("=============\n");
}

int Find(char *key, const hashtbl *H)
{

    int tempint = H->TableSize;

    int i, aux;
    bool cond = false;
    aux = ((Hash(key, tempint)) % tempint);
    for (i = 0; i < tempint; i++)
    {
        aux = (aux + i) % tempint;
        if (strcmp(H->array[aux].word, key) == 0)
        {

            cond = true;
        }
    }
    if (cond == false)
        return 0;
    else
        return 1;
}