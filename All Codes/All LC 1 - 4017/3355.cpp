// Link: https://leetcode.com/problems/zero-array-transformation-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q) SC: O(n)
// Approach: difference array counting how many queries cover each index.
// Each covering query can decrement that index by at most 1, so index i
// can reach 0 iff its coverage count >= nums[i].
class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> diff(n, 0);
        for (int i = 0; i < queries.size(); i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            int d = 1;
            diff[l] += 1;
            if (r + 1 < n)
                diff[r + 1] -= 1;
        }
        for (int i = 1; i < n; i++)
            diff[i] = diff[i - 1] + diff[i];

        for (int i = 0; i < n; i++)
        {
            if (nums[i] - diff[i] > 0)
                return false;
        }
        return true;
    }
};
