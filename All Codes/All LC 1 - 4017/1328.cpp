// Link: https://leetcode.com/problems/break-a-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(1)
    // Approach:
    //  1. If the length of the palindrome is less than 2, return an empty string.
    //  2. Iterate through the first half of the palindrome.
    //  3. If a character is not 'a', change it to 'a' and return the modified palindrome.
    //  4. If all characters in the first half are 'a', change the last character to 'b' and return the modified palindrome.
    //  5. This ensures that the resulting string is the lexicographically smallest non-palindrome.
    //  6. If the palindrome is of length 1, return an empty string as it cannot be converted to a non-palindrome.
    //  7. The function modifies the palindrome in place and returns the result.
    string breakPalindrome(string palindrome)
    {
        int n = palindrome.size();
        if (n < 2)
            return "";
        for (int i = 0; i < n / 2; ++i)
        {
            if (palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n - 1] = 'b';
        return palindrome;
    }
};