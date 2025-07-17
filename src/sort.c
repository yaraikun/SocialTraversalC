#include <stdio.h>
#include <string.h>
#include "sort.h"
#include "graph.h"

void SwapStr(String Str1, String Str2)
{
    String Temp;

    strcpy(Temp, Str1);
    strcpy(Str1, Str2);
    strcpy(Str2, Temp);
}

void SortStrArr(String StrArr[], int Size)
{
    int i, j, MinIdx;

    for (i = 0; i < Size - 1; i++) {
        MinIdx = i;
        
        for (j = i + 1; j < Size; j++)
            /*****************************************************
             * 
             * WORKS INCORRECTLY WITH MIXED CASE STRING ELEMENTS
             * 
             *****************************************************/
            if (strcmp(StrArr[j], StrArr[MinIdx]) < 0)
                MinIdx = j;

        if (MinIdx != i)
            SwapStr(StrArr[i], StrArr[MinIdx]);
    }
}
