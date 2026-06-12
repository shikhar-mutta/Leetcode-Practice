// Link: https://leetcode.com/problems/positions-of-large-groups/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    vector<vector<int>> largeGroupPositions(string s)
    {
        int cnt = 1, n = s.size(), start = 0, end = 0;
        vector<vector<int>> ans;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
                cnt++, end = i;
            else
            {
                if (cnt >= 3) // for the previous group, size >= 3
                    ans.push_back({start, end});
                start = end = i; // fresh start and end for the new group
                cnt = 1;
            }
        }
        if (cnt >= 3) // for the last group
            ans.push_back({start, end});
        return ans;
    }
};
