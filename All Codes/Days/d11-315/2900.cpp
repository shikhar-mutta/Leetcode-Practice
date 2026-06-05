// Link: https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        vector<string> ans;
        int preBit = groups[0];
        ans.push_back(words[0]);
        for (int i = 1; i < groups.size(); i++)
        {
            if (groups[i] != preBit)
            {
                ans.push_back(words[i]);
                preBit = groups[i];
            }
        }

        return ans;
    }
};
