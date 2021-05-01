#include "../hash.h"

int main()
{
    int i, j, k;
    hashtbl_string *H;
    H = InitializeTable_string(100001);
    char string1[100001];
    char string2[100001];
    int temp1, temp2;
    scanf("%s", string1);
    scanf("%s", string2);
    //printf("string1 = %s\n", string1);
    //printf("string2 = %s\n", string2);
    temp1 = strlen(string1);
    temp2 = strlen(string2);
    if (temp1 < temp2)
    {
        checker_string(string1, temp1, H);
        checker2_string(string2, temp2, H);
    }
    else
    {
        checker_string(string2, temp2, H);
        checker2_string(string1, temp1, H);
    }
    //PrintList(H);
    PrintListCommon_string(H);
}
