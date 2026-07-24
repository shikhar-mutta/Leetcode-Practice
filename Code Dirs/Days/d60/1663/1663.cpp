// Link: https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input string.
    // SC: O(1) for storing the result.
    // Approach:
    //       1. Create a string of length n filled with 'a'.
    //       2. Calculate the remaining value to be added to the string by subtracting n from k.
    //       3. Iterate from the end of the string to the beginning, and for each character, add the minimum of 25 or the remaining value to the character.
    //       4. Update the remaining value by subtracting the added value from it.
    //       5. Return the resulting string.
    string getSmallestString(int n, int k)
    {
        string s(n, 'a');
        k = k - n;
        for (int i = n - 1; i >= 0 && k > 0; i--)
        {
            int add = min(25, k);
            s[i] += add;
            k = k - add;
            ;
        }
        return s;
    }
};
