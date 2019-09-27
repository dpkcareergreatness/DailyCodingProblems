/*
 * Copyright (c) 2019
 *
 * Author : Deepak R
 * SPDX-License-Identifier: Apache-2.0
 */
 
/*Q: This problem was asked by Cisco.

Given an unsigned 8-bit integer, swap its even and odd bits.
The 1st and 2nd bit should be swapped, the 3rd and 4th bit should be swapped, 
and so on.
For example, 10101010 should be 01010101. 11100010 should be 11010001.
Bonus: Can you do this in one line?
*/

#include <stdio.h>
/* This is to demonstrate a macr which swaps the even and odd bits of any 32bit number */

#define even_odd_bitswap(num) ( (num & 0xaaaaaaaa)>>1 | (num & 0x55555555)<<1)

int main() {
    unsigned int n;
    printf("Enter number for bit swapping");
    scanf("%d",&n);
    printf("Given number was 0x%x\n",n);
    printf("Byte swapped number is 0x%x",even_odd_bitswap(n));
    
	return 0;
}