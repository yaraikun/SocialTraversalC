/**
 * @file sort.h
 * @brief Declaration of a string array sorting utility.
 *
 * This file provides an interface to a sorting function. The purpose is to
 * have a centralized sorting utility that can be used by various modules
 * to meet output requirements, such as alphabetizing vertex lists or edges.
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
