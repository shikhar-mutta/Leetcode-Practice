// Link: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    //  Approach:
    //  1. Create an array of size 256 to store the counts of characters in both strings.
    //  2. Iterate through the characters of both strings and update the counts array
    //     by incrementing the count for the character in s1 and decrementing the count
    //     for the character in s2. The offset is used to differentiate between characters
    //     at even and odd indices.
    //  3. After processing both strings, check if all counts in the array are zero
    //     If any count is not zero, return false. Otherwise, return true.
    bool checkStrings(string s1, string s2)
    {
        int counts[256] = {0};

        for (int i = 0; i < s1.length(); i++)
        {
            int offset = (i & 1) << 7;
            counts[offset + s1[i]]++;
            counts[offset + s2[i]]--;
        }

        for (int i = 0; i < 256; i++)
        {
            if (counts[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};
