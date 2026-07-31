// Link: https://leetcode.com/problems/zero-array-transformation-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q) SC: O(n)
//  Approach: difference array counting how many queries cover each index.
//  Each covering query can decrement that index by at most val, so index i
//  can reach 0 iff its coverage count >= nums[i].
class Solution
{
public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size(), sum = 0, k = 0;
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            while (sum + cnt[i] < nums[i])
            {
                if (k == queries.size())
                    return -1;
                int l = queries[k][0];
                int r = queries[k][1];
                int val = queries[k][2];
                k++;

                if (r < i)
                    continue;
                cnt[max(l, i)] += val;
                cnt[r + 1] -= val;
            }
            sum += cnt[i];
        }
        return k;
    }
};