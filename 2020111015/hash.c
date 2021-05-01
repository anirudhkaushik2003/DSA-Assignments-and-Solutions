#include "hash.h"
float observations = 0;
float analyser(int numofprobes, int cond)
{

    observations += numofprobes;

    return (observations / 200.0);
}

Index Hash_string(const char *key, const int TableSize)
{
    unsigned int HashVal = 0;
    while (*key != '\0')
    {
        HashVal = (HashVal << 5) ^ *key++;
    }
    return (HashVal % TableSize);
}

hashtbl_string *InitializeTable_string(int N)
{
    //N is Table size
    hashtbl_string *H;
    int i;

    H = malloc(sizeof(hashtbl_string));
    assert(H != NULL);

    H->TableSize = N;

    H->TheLists = malloc(sizeof(list_2 *) * H->TableSize);
    assert(H->TheLists != NULL);

    for (i = 0; i < H->TableSize; i++)
    {
        H->TheLists[i] = malloc(sizeof(list_2));
        assert(H->TheLists[i] != NULL);
        H->TheLists[i]->next = NULL;
        H->TheLists[i]->occupied = false;
        H->TheLists[i]->common = false;
    }

    return H;
}
list_2 *Find_separatechaining_string(char *key, const hashtbl_string *H)
{
    list_2 *P, *L;
    int i = 0;
    L = H->TheLists[Hash_string(key, H->TableSize)];
    P = L->next;
    while (P != NULL && strcmp(P->word, key) != 0)
    {
        P = P->next;
        i++;
    }
    return P;
}

void Insert_string(char *key, hashtbl_string *H)
{
    Position_2 Pos, NewCell;
    list_2 *L;
    int aux;

    //Pos = Find_separatechaining(key, H);

    NewCell = malloc(sizeof(list_2));
    assert(NewCell != NULL);
    aux = Hash_string(key, H->TableSize);
    L = H->TheLists[aux];
    //H->TheLists[aux]->occupied = true;
    L->occupied = true;
    NewCell->next = L->next;
    //strcpy(NewCell->word, key);
    NewCell->word = key;
    L->next = NewCell;
    NewCell->occupied = true;
    NewCell->occupied = false;
}
void PrintList_string(hashtbl_string *H)
{

    //printf("=============\n");
    Position_2 B, F;
    int i = 0;
    for (B = H->TheLists[i]; B != NULL; B = H->TheLists[++i])
    {
        for (F = B->next; F != NULL; F = F->next)
        {
            if (B->occupied == true && F->occupied == true && F->word[0] != '\0')
                printf("%s\n", F->word);
        }
        //printf("\n");
    }
    //printf("=============\n");
}

void checker_string(char *string, int length, hashtbl_string *H)
{
    int i, j, k, condition = 0, temp, count;
    for (k = 0; k < length + 1; k++)
    {
        count = 0;
        if (length % (k + 1) == 0)
        {
            for (i = 0; i < (length / (k + 1)); i++)
            {
                //count++;
                for (j = 0; j <= k && (((i * (k + 1)) + j) < length); j++)
                {
                    if (length % (k + 1) == 0)
                    {
                        count = ((i * (k + 1))) + j;
                        if (string[((i * (k + 1))) + j] == string[j])
                        {
                            condition = 1;
                        }
                        else
                        {
                            condition = 0;
                            break;
                        }
                    }
                    else
                        condition = 0;
                }
                if (condition == 0)
                    break;
            }
            if (condition == 1)
            {

                char *key;
                key = malloc(sizeof(char) * (k + 2));
                assert(key != NULL);

                key[k + 1] = '\0';

                for (temp = 0; temp < k + 1; temp++)
                {
                    key[temp] = string[temp];
                }
                //printf("k = %d\n", k);
                Insert_string(key, H);
            }
        }
    }
}

void checker2_string(char *string, int length, hashtbl_string *H)
{
    int i, j, k, condition = 0, temp;
    for (k = 0; k < length + 1; k++)
    {
        if (length % (k + 1) == 0)
        {
            //count = 0;
            for (i = 0; i < (length / (k + 1)); i++)
            {
                //count++;
                for (j = 0; j <= k && (((i * (k + 1)) + j) < length); j++)
                {
                    if (length % (k + 1) == 0)
                    {
                        //count = ((i * (k + 1))) + j;
                        if (string[((i * (k + 1))) + j] == string[j])
                        {
                            condition = 1;
                        }
                        else
                        {
                            condition = 0;
                            break;
                        }
                    }
                    else
                        condition = 0;
                }
                if (condition == 0)
                    break;
            }
            if (condition == 1)
            {

                char *key;
                key = malloc(sizeof(char) * (k + 2));
                assert(key != NULL);
                key[k + 1] = '\0';

                for (temp = 0; temp < k + 1; temp++)
                {
                    key[temp] = string[temp];
                }
                //printf("k = %d\n", k);
                Insert2_string(key, H);
            }
        }
    }
}
void Insert2_string(char *key, hashtbl_string *H)
{
    Position_2 Pos, NewCell;
    list_2 *L;
    int aux;

    Pos = Find_separatechaining_string(key, H);
    if (Pos != NULL)
    {
        Pos->common = true;
    }
}
void PrintListCommon_string(hashtbl_string *H)
{

    //printf("=============\n");
    Position_2 B, F;
    int i = 0;
    int count = 0;

    for (B = H->TheLists[i]; B != NULL && i < (H->TableSize - 1); B = H->TheLists[++i])
    {

        for (F = B->next; F != NULL; F = F->next)
        {
            if (B->occupied == true && F->common == true && F->word[0] != '\0')
                count++;
        }
        //printf("\n");
    }
    printf("%d\n", count);
    //printf("=============\n");
}

Index Hash_dictionary(const char *key, const int TableSize)
{
    unsigned int HashVal = 0;
    while (*key != '\0')
    {
        HashVal = (HashVal << 5) ^ *key++;
    }
    return (HashVal % TableSize);
}

hashtbl_dictionary *InitializeTable_dictionary(int N)
{
    //N is Table size
    hashtbl_dictionary *H;
    int i;

    H = malloc(sizeof(hashtbl_dictionary));
    assert(H != NULL);

    H->TableSize = N;

    H->TheLists = malloc(sizeof(list_1 *) * H->TableSize);
    assert(H->TheLists != NULL);

    for (i = 0; i < (H->TableSize); i++)
    {
        H->TheLists[i] = malloc(sizeof(list_1));
        assert(H->TheLists[i] != NULL);
        H->TheLists[i]->next = NULL;
    }

    return H;
}
list_1 *Find_separatechaining_dictionary(char *key, const hashtbl_dictionary *H)
{
    list_1 *P, *L;
    int i = 0;
    L = H->TheLists[Hash_dictionary(key, H->TableSize)];
    P = L->next;
    while (P != NULL && strcmp(P->word, key) != 0)
    {
        P = P->next;
        i++;
    }
    //analyser(i, 0);
    return P;
}

void Insert_dictionary(char *key, hashtbl_dictionary *H)
{
    Position_1 Pos, NewCell;
    list_1 *L;

    Pos = Find_separatechaining_dictionary(key, H);
    if (Pos == NULL)
    {
        NewCell = malloc(sizeof(list_1));
        assert(NewCell != NULL);

        L = H->TheLists[Hash_dictionary(key, H->TableSize)];

        NewCell->next = L->next;
        strcpy(NewCell->word, key);
        L->next = NewCell;
    }
}
void PrintList_dictionary(hashtbl_dictionary *H)
{

    printf("=============\n");
    Position_1 B, F;
    int i = 0;
    for (B = H->TheLists[i]; i < (H->TableSize ); B = H->TheLists[++i])
    {
        for (F = B->next; F != NULL; F = F->next)
        {
            printf("%s-->", F->word);
        }
        printf("\n");
    }
    printf("=============\n");
}

int Find_dictionary(char *key, const hashtbl_dictionary *H)
{

    //int tempint = H->TableSize;

    int i, aux;
    list_1 *P;
    P = Find_separatechaining_dictionary(key, H);
    // aux = ((Hash(key, tempint)) % tempint);

    if (P != NULL && strcmp(P->word, key) == 0)
    {

        return 1;
    }

    else
        return 0;
}

Index Hash(const unsigned int Key, int TableSize)
{

    return Key % TableSize;
}

hashtbl *InitializeTable_separatechaining(int N)
{
    //N is Table size
    hashtbl *H;
    int i;

    H = malloc(sizeof(hashtbl));
    assert(H != NULL);

    H->TableSize = N;

    H->TheLists = malloc(sizeof(list *) * H->TableSize);
    assert(H->TheLists != NULL);

    for (i = 0; i < H->TableSize; i++)
    {
        H->TheLists[i] = malloc(sizeof(list));
        assert(H->TheLists[i] != NULL);
        H->TheLists[i]->next = NULL;
    }

    return H;
}

list *Find_separatechaining(unsigned int key, hashtbl *H)
{
    list *P, *L;
    int i = 0;
    L = H->TheLists[Hash(key, H->TableSize)];
    P = L->next;
    while (P != NULL && P->Element != key)
    {
        P = P->next;
        i++;
    }
    analyser(i, 0);
    return P;
}

int Find_separatechainingPos(unsigned int key, hashtbl *H)
{
    list *P, *L;
    int i = 0;
    L = H->TheLists[Hash(key, H->TableSize)];
    P = L->next;
    while (P != NULL && P->Element != key)
    {
        P = P->next;
        i++;
    }

    if (P == NULL)
        return -1;
    else
        return i;
}

void Insert_separatechaining(unsigned int key, hashtbl *H)
{
    Position Pos, NewCell;
    list *L, *P;
    int i = 0;
    //Pos = Find_separatechaining(key, H);

    NewCell = malloc(sizeof(list));
    assert(NewCell != NULL);

    L = H->TheLists[Hash(key, H->TableSize)];
    P = L->next;
    NewCell->Element = key;
    while (P != NULL && P->next != NULL)
    {
        P = P->next;
        i++;
    }
    analyser(i, 0);
    if (P != NULL)
        NewCell->next = P->next;
    else
    {
        NewCell->next = P;
    }

    if (P != NULL)
        P->next = NewCell;
    else
    {
        L->next = NewCell;
    }
}

void PrintList_separatechaining(hashtbl *H)
{
    Position B, F;
    int i = 0;
    for (B = H->TheLists[i]; B != NULL; B = H->TheLists[++i])
    {
        for (F = B->next; F != NULL; F = F->next)
        {
            printf("%d-->", F->Element);
        }
        printf("\n");
    }
}

hashtbl_LP *InitializeTable_LinearProbing(int N)
{
    //N is table size
    hashtbl_LP *H;
    H = malloc(sizeof(hashtbl_LP)); //pointer to dynamically allocated array
    assert(H != NULL);
    H->TableSize = N;

    H->array = malloc(sizeof(list) * H->TableSize);
    assert(H->array != NULL);
    int i;
    for (i = 0; i < H->TableSize; i++)
    {
        H->array[i].occupied = false;
    }
    return H;
}

void Insert_LP(unsigned int key, hashtbl_LP *H)
{
    int i, aux;
    for (i = 0; i < H->TableSize; i++)
    {
        aux = (Hash(key, H->TableSize) + i) % H->TableSize;
        if (H->array[aux].occupied == false)
        {
            H->array[aux].Element = key;
            H->array[aux].occupied = true;
            analyser(i, 0);
            return;
        }
    }
}

void PrintList_LP(hashtbl_LP *H)
{
    int i;
    printf("=============\n");
    for (i = 0; i < H->TableSize; i++)
    {
        printf("%d\n", H->array[i].Element);
    }
    printf("=============\n");
}

hashtbl_LP *InitializeTable_QuadProbing(int N)
{
    //N is table size
    hashtbl_LP *H;
    H = malloc(sizeof(hashtbl_LP)); //pointer to dynamically allocated array
    assert(H != NULL);
    H->TableSize = N;

    H->array = malloc(sizeof(list) * H->TableSize);
    assert(H->array != NULL);
    int i;
    for (i = 0; i < H->TableSize; i++)
    {
        H->array[i].occupied = false;
    }
    return H;
}

void Insert_QP(unsigned int key, hashtbl_LP *H)
{
    int i, aux;
    for (i = 0; i < H->TableSize; i++)
    {
        aux = (Hash(key, H->TableSize) + (i * i)) % H->TableSize;
        if (H->array[aux].occupied == false)
        {
            H->array[aux].Element = key;
            H->array[aux].occupied = true;
            analyser(i, 0);
            //printf("position = %d\n", (Hash(key, H->TableSize) + (i * i)) % H->TableSize);
            return;
        }
    }
}

void PrintList_QP(hashtbl_LP *H)
{
    int i;
    printf("=============\n");
    for (i = 0; i < H->TableSize; i++)
    {
        printf("%d\n", H->array[i].Element);
    }
    printf("=============\n");
}

int FindPos_QP(unsigned int key, hashtbl_LP *H)
{
    int i, aux;
    for (i = 0; i < H->TableSize; i++)
    {
        aux = (Hash(key, H->TableSize) + (i * i)) % H->TableSize;
        if (H->array[aux].Element == key)
        {

            return aux;
        }
    }
    return -1;
}

int FindPos_LP(unsigned int key, hashtbl_LP *H)
{
    int i, aux;
    for (i = 0; i < H->TableSize; i++)
    {
        aux = (Hash(key, H->TableSize) + i) % H->TableSize;
        if (H->array[aux].Element == key)
        {

            return aux;
        }
    }
    return -1;
}
