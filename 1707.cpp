// Link: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = queries.size();
        vector<int> v(n, 0);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (nums[0] > queries[i][1])
            {
                v[i] = -1;
                continue;
            }
            auto it1 = nums.begin();
            auto it2 = upper_bound(nums.begin(), nums.end(), queries[i][1]);
            int x = queries[i][0], y = 0;
            for (int j = 29; j >= 0 && it2 - it1 > 1; j--)
            {
                if ((*(it2 - 1) & (1 << j)) == 0)
                    continue;
                if (*it1 & (1 << j))
                {
                    y |= (1 << j);
                    continue;
                }
                auto it3 = lower_bound(it1, it2, y | (1 << j));
                if (x & (1 << j))
                    it2 = it3;
                else
                {
                    y |= (1 << j);
                    it1 = it3;
                }
            }
            v[i] = *it1 ^ x;
        }
        return v;
    }
};