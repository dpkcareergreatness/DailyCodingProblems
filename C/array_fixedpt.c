/*
 * Copyright (c) 2019
 *
 * Author : Deepak R
 * SPDX-License-Identifier: Apache-2.0
 */
 
/*Q: This problem was asked by Microsoft.

This problem was asked by Apple.

A fixed point in an array is an element whose value is equal to its index. Given a sorted array of distinct elements, return a fixed point, if one exists. Otherwise, return False.

For example, given [-6, 0, 2, 40], you should return 2. Given [1, 5, 7, 8], you should return False.
*/
//I could've used binary search here which would have been O(log n) instead of worst case O(n)
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
bool fixedPtInArray(int *ret,int a[],int size)
{
	bool bret = false;
	for(int i = 0; i<size;i++)
	{
		/*Sorted list, so if an element is greater than its index,
		 * there is no point in proceeding further.
		 * */
		if(a[i] > i)
		{
			break;
		}
		else if(a[i] == i)
		{
			*ret = i;
			bret = true;
			break;
		}
	}
	return bret;
}

int main() 
{
	int *a, size;
	printf("Enter size of array: ");
	scanf("%d",&size);
	a = (int *) malloc(size*sizeof(int));
	printf("Enter array ");
	for(int i = 0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	int fixedpoint;
	bool ret = fixedPtInArray(&fixedpoint,a,size);
	if(ret == true)
	{
		printf("Fixed point exit It is %d ", fixedpoint);
	}
	else
	{
		printf("No fixed point exist. ");
	}
	return 0;
}
