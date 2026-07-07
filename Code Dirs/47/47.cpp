// Link: https://leetcode.com/problems/permutations-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> used(n, false);

        function<void()> bt = [&]()
        {
            if ((int)cur.size() == n)
            {
                res.push_back(cur);
                return;
            }
            for (int i = 0; i < n; i++)
            {
                if (used[i])
                    continue;
                // skip duplicate values at the same depth
                if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                    continue;
                used[i] = true;
                cur.push_back(nums[i]);
                bt();
                cur.pop_back();
                used[i] = false;
            }
        };
        bt();
        return res;
    }
};
