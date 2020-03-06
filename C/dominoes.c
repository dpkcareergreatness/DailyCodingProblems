/*
 * Copyright (c) 2019
 *
 * Author : Deepak R
 * SPDX-License-Identifier: Apache-2.0
 */
 
/*Q: This problem was asked by Microsoft.

You are given an string representing the initial conditions of some dominoes. Each element can take one of three values:

L, meaning the domino has just been pushed to the left,
R, meaning the domino has just been pushed to the right, or
., meaning the domino is standing still.
Determine the orientation of each tile when the dominoes stop falling. Note that if a domino receives a force from the left and right side simultaneously, it will remain upright.

For example, given the string .L.R....L, you should return LL.RRRLLL.

Given the string ..R...L.L, you should return ..RR.LLLL.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int checkLfill(char *ch,int pos);
int checkRfill(char *ch,int pos);

int main() {
	char ch[9];
	int lpos[9];
	int rpos[9];
	int flag = 0;
	printf("Enter string");
	//keep reading characters till \n is found
	scanf("%[^\n]",ch);
	printf("String entered is %s",ch);
	//Should evaluate all filled positions together.
	//IT is like a multiplayer game. You should allow all players equal turn
	//First evaluate the next  movement of all the players involved. DO NOT fill until you have evaluated all players next mvoe
	//save the index to which they should movenext in an array.
	//At the endof evaluation fill the array with eveyr players next move and then repeat till no player can move again
	do
	{
		int len = strlen(ch);
		flag = 0;
		memset(lpos,-1,9);
		memset(rpos,-1,9);
		for(int i=0;i<len;i++)
		{	
			if(ch[i] == 'L')
			{
				if(checkLfill(ch,i) == 1)
				{
					lpos[i-1]=1;
					flag = 1;
				}
			}
			else if (ch[i] == 'R')
			{
				if(checkRfill(ch,i) == 1)
				{
					rpos[i+1]=1;
					flag = 1;
				}
			}
			else
			{
			}
		}
		for(int i=0;i<len;i++)
		{
			if(lpos[i] == 1)
			{
				ch[i] = 'L';
			}
			else if(rpos[i] == 1)
			{
				ch[i] = 'R';
			}
		}
		
	}while(flag == 1);
	printf("String filled is %s",ch);
	return 0;
}

int checkLfill(char *ch, int pos)
{
	int ret=0;
	
	if( ((pos-2) > 0) && (ch[pos-2] != 'R') )
		ret = 1;
	else if( (pos -1) == 0 && (ch[pos-1] == ' '))
		ret = 1;
	else
		ret = 0;
		
	if(ch[pos-1] != ' ')
		ret = 0;
	 
	return ret;
}

int checkRfill(char *ch, int pos)
{
	int ret=0;
	
	if( ((pos+2) > 0) && (ch[pos+2] != 'L')  )
		ret = 1;
	else if( (pos+1) == strlen(ch) && (ch[pos+1] == ' ' ))
		ret = 1;
	else
		ret = 0;
		
	if(ch[pos+1] != ' ')
		ret = 0;
	return ret;
}

