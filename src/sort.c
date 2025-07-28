/**
 * @file    sort.c
 * @author  Evan Riley L. Calupig
 * @author  Jon Chester C. Donguines
 * @brief   Implementation of a string array sorting utility.
 *
 * This file implements a simple Selection Sort algorithm to sort an array of
 * strings in-place. This algorithm was chosen for its straightforward
 * implementation, which is sufficient for the small-scale data constraints
 * of the project (maximum of 20 vertices).
 */

#include "sort.h"
#include <string.h>

/**
 * SwapStr() - Swaps the contents of two strings.
 *
 * @str1: The first string.
 * @str2: The second string.
 *
 * A helper function used in SortStrArr() that exchanges the contents of two
 * strings using a temporary variable.
 */
void SwapStr(String str1, String str2)
{
    String temp;

    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

/**
 * SortStrArr() - Sorts an array of strings in ascending order.
 *
 * @strArr: The array of strings to be sorted.
 * @size:   The number of elements in the array.
 *
 * Sorts the given string using selection sort. Lexicographic order is
 * determined using strcmp(). If the array has one or zero elements, the
 * function returns immediately.
 */
void SortStrArr(String strArr[], int size)
{
    int i, j, min_idx;

    if (size <= 1)
        return;

    for (i = 0; i < size - 1; i++) {
        min_idx = i;

        for (j = i + 1; j < size; j++)
            if (strcmp(strArr[j], strArr[min_idx]) < 0)
                min_idx = j;

        if (min_idx != i)
            SwapStr(strArr[i], strArr[min_idx]);
    }
}
