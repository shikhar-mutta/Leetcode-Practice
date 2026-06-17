// Link: https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    bool checkAlmostEquivalent(string word1, string word2)
    {
        int diff[26] = {0};
        for (char c : word1)
            diff[c - 'a']++; // count in word1
        for (char c : word2)
            diff[c - 'a']--; // subtract word2's counts
        // every letter's frequency must differ by at most 3
        for (int d : diff)
            if (abs(d) > 3)
                return false;
        return true;
    }
};
