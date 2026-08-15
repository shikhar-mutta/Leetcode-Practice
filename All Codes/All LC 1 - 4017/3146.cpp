// Link: https://leetcode.com/problems/permutation-difference-between-two-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int findPermutationDifference(string s, string t)
    {
        // record each char's index in t, then sum |pos_s - pos_t| over all chars
        int pos[26];
        for (int i = 0; i < (int)t.size(); ++i)
            pos[t[i] - 'a'] = i;
        int diff = 0;
        for (int i = 0; i < (int)s.size(); ++i)
            diff += abs(i - pos[s[i] - 'a']);
        return diff;
    }
};
