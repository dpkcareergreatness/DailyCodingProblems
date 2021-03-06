/*
 * Copyright (c) 2019
 *
 * Author : Deepak R
 * SPDX-License-Identifier: Apache-2.0
 */

 /*Q: This problem was asked by Cisco.
  Swap n bit LSB with n bit MSB of a number
 Bonus: Can you do this in one line?
 */


#include "stdio.h"

int swap(int number, int n) {
	int temp;
	n = n - 1;//because number is not same as digits
	int lsb_mask = (0x1 << (n + 1)) - 1;//set oxf for all n bits in lsb
	int msb_mask = -1 << (sizeof(int) * 8 - n - 1);//set 0xf for all MSB bits and 0 for others

	unsigned int lsb = number & lsb_mask;
	unsigned int msb = (number & msb_mask)>>(sizeof(int) * 8 - n - 1);

	temp = msb;//save the msb as lsb
	temp |= lsb<< (sizeof(int) * 8 - n - 1);//save the lsb as the new msb
	number = number & (~(lsb_mask | msb_mask));//save the remaining bits of the actual number;
	temp |= number;//restore the other bits in the number
	return temp;
}

int main()
{
	printf("%d",swap(3905, 6));

}
