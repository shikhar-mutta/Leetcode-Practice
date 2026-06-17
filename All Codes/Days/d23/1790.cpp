// Link: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    bool areAlmostEqual(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;
        vector<int> diff; // store indices of differing characters
        for (int i = 0; i < (int)s1.size(); i++)
            if (s1[i] != s2[i])
                diff.push_back(i);

        if (diff.empty())
            return true; // already equal: zero swaps needed
        if (diff.size() != 2)
            return false; // one swap fixes exactly two positions
        int a = diff[0], b = diff[1];
        return s1[a] == s2[b] && s1[b] == s2[a]; // the two chars must be crossed
    }
};
