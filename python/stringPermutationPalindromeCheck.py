#!/usr/bin/python3
'''
This problem was asked by Amazon.

Given a string, determine whether any permutation of it is a palindrome.

For example, carrace should return true, 
since it can be rearranged to form racecar, which is a palindrome. 
daily should return false, since there's no rearrangement that can form a palindrome.
'''

def getCharFreq(string):
    charFreq = {}
    for char in string:
        if(charFreq.get(char, 0) == 0):
            charFreq[char] = 1
        else:
            charFreq[char] = charFreq[char] + 1

    return charFreq


def checkStringComboPalindrome(string):
    strlength = len(string)
    if string[-1] == '\0':
        strlength -= 1
    charFreq = getCharFreq(string)
    bUniqueOddElement = False

    # For odd length string to be a palindrome, there has to be exactly one char in the string which is odd
    # For even leght string to be a palidnrome, all chars in the string has to be even
    for item, value in charFreq.items():
        if (value % 2 != 0) and (strlength % 2 == 0):
            return False
        elif (value % 2 != 0) and (strlength % 2 != 0):
            if bUniqueOddElement == True:
                return False
            else:
                bUniqueOddElement = True

    return True


if __name__ == '__main__':
    string = input('Enter string')
    status = checkStringComboPalindrome(string)
    print("Entered string {} palindrome status is {}".format(string, status))
