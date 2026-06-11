// Link: https://leetcode.com/problems/longest-uncommon-subsequence-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n). SC: O(1).
    int findLUSlength(string a, string b)
    {
        return a == b ? -1 : max(a.size(), b.size());
    }
};
