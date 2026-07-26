// Link: https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/

// TC: O(n)
// SC: O(1)
// Approach: iterate through pairs of consecutive characters in row-major order.
// If characters in a pair differ, increment the change counter. Since the string
// length is guaranteed to be even, all cells form complete pairs without division.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minChanges(string s)
    {
        int changes = 0;
        // Iterate through pairs of characters
        for (int i = 0; i < s.length(); i += 2)
        {
            // If the pair is different, we need one change
            if (s[i] != s[i + 1])
            {
                changes++;
            }
        }
        return changes;
    }
};
