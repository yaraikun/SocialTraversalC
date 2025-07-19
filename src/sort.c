#include <string.h>
#include "sort.h"

void SwapStr(String str1, String str2)
{
    String temp;
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

void SortStrArr(String strArr[], int size)
{
    int i, j, min_idx;

    if (size <= 1) return;

    for (i = 0; i < size - 1; i++) {
        min_idx = i;

        for (j = i + 1; j < size; j++)
            if (strcmp(strArr[j], strArr[min_idx]) < 0)
                min_idx = j;

        if (min_idx != i)
            SwapStr(strArr[i], strArr[min_idx]);
    }
}
