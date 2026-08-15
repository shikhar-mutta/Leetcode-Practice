// Link: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    //   Approach:
    //     1. We can use two pointers to iterate through the string from both ends and compare the characters at the current indices.
    //     2. If the characters are equal, we can move the pointers towards the center of the string until we find a character that is not equal to the current character.
    //     3. We can continue this process until the pointers meet or cross each other and return the length of the remaining string as the result.
    //  Note: We need to check if the pointers have crossed each other to ensure that we do not exceed the length of the string.
    int minimumLength(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j && s[i] == s[j])
        {
            char c = s[i];
            while (i <= j && s[i] == c)
                ++i;
            while (j >= i && s[j] == c)
                --j;
        }
        return j - i + 1;
    }
};