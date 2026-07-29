// Link: https://leetcode.com/problems/maximum-number-of-groups-getting-fresh-donuts/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n * n)  SC: O(2^n * n)
//  Approach: Use a bitmask to represent the state of the groups. For each state, we can calculate the number of happy groups by checking the remainder of the sum of the group sizes modulo the batch size. We can use memoization to store the results of previously computed states to avoid redundant calculations. The final answer will be the maximum number of happy groups we can achieve by trying all possible combinations of groups.
class Solution
{
public:
    map<vector<int>, int> dp;
    int dfs(vector<int> &cnt, int left)
    {
        auto it = dp.find(cnt);
        if (it != end(dp))
            return it->second;
        int res = 0, bz = cnt.size();
        for (auto j = 1; j < bz; ++j)
        {
            if (--cnt[j] >= 0)
                res = max(res, (left == 0) + dfs(cnt, (bz + left - j) % bz));
            ++cnt[j];
        }
        return dp[cnt] = res;
    }
    int maxHappyGroups(int bz, vector<int> &groups)
    {
        vector<int> cnt(bz);
        int res = 0;
        for (auto group : groups)
        {
            if (group % bz == 0)
                ++res;
            else if (cnt[bz - group % bz])
            {
                --cnt[bz - group % bz];
                ++res;
            }
            else
                ++cnt[group % bz];
        }
        return dfs(cnt, 0) + res;
    }
};