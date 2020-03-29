/*
 * Copyright (c) 2020
 *
 * Author : Deepak R
 * SPDX-License-Identifier: Apache-2.0
 */
 
 //Link with math library (-lm) for log10 function
 
/*Q: Find out if given number is a power of entered number(which should be a power of 2
*/

//Algo:
// 1. Entered number must be a power of 2 first. Then only it can be any other power of 2
// 2. The number must have exactly 1 bit set at log n position(where n is the power of 2 entered)

#include <stdio.h>
#include <math.h>

void main()
{
	int N,powerof2;
	printf("Enter any number ");
	scanf("%d",&N);
	printf("Enter power of 2 ");
	scanf("%d",&powerof2);
	
	if( (N&N-1) != 0)
	{
		printf("Not a power of 2. Hence not power of %d",powerof2);
		return;
	}
	else
	{
		unsigned int pos = log10(powerof2)/log10(2);//No log2 function so use maths to calculate log2
		int count = 0;
		for(unsigned int i=pos;i<sizeof(N)*8;i+=pos)
		{
			unsigned int mask = 1<<i;
			if((mask&N) != 0)
			{
				count = 1;//No need to check other bits as already we checked power of 2 earlier which covers this check
				break;
			}
		}
		if (count == 1)
		{
			printf("Entered number is power a of %d",powerof2);
		}
		else
		{
			printf("Entered number is not a power of %d",powerof2);
		}
	}
}
