/******************************************************************************
*     File Name           :     mergesort.h                                   *
*     Created By          :     Klas                                          *
*     Creation Date       :     [2016-06-23 01:16]                            *
*     Last Modified       :     [2016-06-23 10:42]                            *
*     Description         :     Mergesort                                     *
******************************************************************************/
#ifndef MERGESORT
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/******************************************************************************
* Function: mergesort                                                         *
* ~~~~~~~~~~~~~~~~~~~                                                         *
* Self explanatory.                                                           *
*                                                                             *
* A_void: Pointer to list which should be merged.                             *
* size: Size of list.                                                         *
* nmemb: Size of each element.                                                *
* cmp: Compare function.                                                      *
*                                                                             *
* Returns: E_OK if successful.                                                *
******************************************************************************/
int tdc_mergesort(void *A_void, size_t size, size_t nmemb,
				 int (*cmp)(const void *, const void *));
/******************************************************************************
* Function: merge                                                             *
* ~~~~~~~~~~~~~~~                                                             *
* Merge two lists into one, the merged list is sorted in the process.         *
*                                                                             *
* A: Destination of merge.                                                    *
* nmemb: Size of each element.                                                *
* cmp: Compare function.                                                      *
* L: Left list.                                                               *
* left: Size of left list.                                                    *
* R: Right list.                                                              *
* right: Size of right list.                                                  *
*                                                                             *
* Returns: E_OK if successful.                                                *
******************************************************************************/
int merge(char *A, size_t nmemb, int (*cmp)(const void *a, const void *b),
				char *L, int left, char *R, int right);
#endif

