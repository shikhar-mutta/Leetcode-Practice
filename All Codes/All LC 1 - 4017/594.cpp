// Link: https://leetcode.com/problems/longest-harmonious-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        unordered_map<int, int> rc;
        for (auto n : nums)
            rc[n]++;
        int mx = 0;
        for (auto &[key, val] : rc)
            if (rc.count(key + 1)) // rc.count() is O(1) on average for unordered_map
                mx = max(mx, val + rc[key + 1]);
        return mx;
    }
};