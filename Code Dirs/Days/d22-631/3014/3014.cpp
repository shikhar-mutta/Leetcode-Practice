// Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n). SC: O(1).
    int minimumPushes(string word)
    {
        int n = word.size(), total = 0;
        // each key can hold 8 letters, so the number of pushes for each letter is its index divided by 8 (integer division) plus 1
        for (int i = 0; i < n; ++i)
            total += i / 8 + 1;
        return total;
    }
};
