// Link: https://leetcode.com/problems/minimize-string-length/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int minimizedStringLength(string s)
    {
        bitset<26> seen;
        for (char c : s)
            seen.set(c - 'a');
        return seen.count();
    }
};
