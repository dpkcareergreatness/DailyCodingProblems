/*
 * Copyright (c) 2019
 *
 * Author : Deepak R
 * SPDX-License-Identifier: Apache-2.0
 */
 
/*Q: This problem was asked by Indeed.Given a 32-bit positive integer N, determine whether it is a power of four in faster than O(log N) time.
*/

#include <stdio.h>
#include <stdbool.h>
int main() {
    unsigned int N;
    int ones_count = 0;
	bool otherbitset = false;
    
    //Power of 4 number has exactly one bit set and that set bit will be
    //in a bit poistion where the binary weight is power of 2 like
     //0,2,4 etc(2^0,2^1,2^2 etc)
     //
     char ch;

	do
	{
		printf("Enter number N");
		scanf("%d",&N);
		for(int i =0;i<sizeof(N)*8;i = i+2)
		{
			if(N>>(i) > 0)
			{
				char validbit = (N>>(i))&0x1;
				char otherbit = (N>>(i))&0x2;
				if( validbit == 1)
				{
					ones_count += 1;
				}
				if(otherbit != 0)
				{
					otherbitset = true;
					break;
				}
			}
		}

		if (ones_count == 1 && otherbitset == false)
		{
			printf("Power of 4");
		}
		else 
		{
			printf("Not power of 4");
		}
		printf("Enter more numers(Y/N)?");
		ch = getchar();
	}while(ch == 'y' || ch == 'Y');
	return 0;
}
