// Link: https://leetcode.com/problems/first-matching-character-from-both-ends/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int firstMatchingIndex(string s)
    {
        int n = s.size();
        // walk inward; return the first index whose mirror char matches
        for (int i = 0; i <= n - 1 - i; i++)
            if (s[i] == s[n - 1 - i])
                return i;
        return -1;
    }
};
