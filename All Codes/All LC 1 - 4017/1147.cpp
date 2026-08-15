// Link: https://leetcode.com/problems/longest-chunked-palindrome-decomposition/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2)  SC: O(n)
// Approach: greedily grow a matching prefix/suffix pair from both ends;
// as soon as the current prefix equals the current suffix (non-empty,
// non-overlapping), count that as 2 chunks and recurse on the middle
// remainder. A leftover single middle piece (or nothing) contributes
// 1 (or 0) more chunk.
class Solution
{
public:
    int longestDecomposition(string text)
    {
        int n = text.size();
        if (n == 0)
            return 0;
        for (int len = 1; len <= n / 2; len++)
        {
            if (text.substr(0, len) == text.substr(n - len, len))
            {
                return 2 + longestDecomposition(text.substr(len, n - 2 * len));
            }
        }
        return 1;
    }
};
