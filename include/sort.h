/**
 * @file    sort.h
 * @author  Evan Riley L. Calupig
 * @author  Jon Chester C. Donguines
 * @brief   Declaration of a general-purpose string array sorting utility.
 *
 * This file declares the `SortStrArr` function. The purpose of this module is
 * to provide a single, centralized sorting utility that can be used by various
 * parts of the program (e.g., traversals, degree calculation) to meet
 * alphabetical ordering requirements.
 */

#ifndef SORT_H
#define SORT_H

#include "graph.h"

/**
 * SortStrArr() - Sorts an array of strings in ascending alphabetical order.
 * @strArr: The array of strings to be sorted.
 * @size:   The number of elements in the array.
 *
 * This function is a general-purpose helper used to enforce alphabetical
 * ordering requirements for multiple output files. It modifies the array
 * in-place.
 */
void SortStrArr(String strArr[], int size);

#endif /* SORT_H */
