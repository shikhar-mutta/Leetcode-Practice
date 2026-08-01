// Link: https://leetcode.com/problems/peaks-in-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((n+q) log n)  SC: O(n)
//  Approach: a BIT over "isPeak[i]" indicators (peak: 0<i<n-1 and
//  nums[i-1]<nums[i]>nums[i+1]). Type 2 query [l,r] sums peaks in that range via prefix sums. Type 1 update [i,val] changes nums[i], which can only affect peak status at i-1, i, i+1 — recompute those three indicators before and after the change, updating the BIT with the delta for each.
//  Note: the BIT is 1-indexed, so we store peak indicators at indices 1..n-2 (corresponding to nums indices 1..n-2).
class Solution
{
    bool peak(int a, int b, int c) { return a < b && b > c; }

public:
    vector<int> countOfPeaks(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> tree(n - 1), ans;
        ans.reserve(queries.size());

        for (int i = 1; i < n - 1; ++i)
        {
            tree[i] += peak(nums[i - 1], nums[i], nums[i + 1]);
            int p = i + (i & -i);
            if (p < n - 1)
                tree[p] += tree[i];
        }

        auto add = [&](int i, int d)
        {
            for (; i < n - 1; i += (i & -i))
                tree[i] += d;
        };

        auto get = [&](int i)
        {
            int ans = 0;
            for (; i > 0; i -= (i & -i))
                ans += tree[i];
            return ans;
        };

        for (auto &query : queries)
        {
            int q = query[0];
            if (q == 1)
            {
                int l = query[1], r = query[2];
                ans.push_back(l < r ? get(r - 1) - get(l) : 0);
            }
            else
            {
                int i = query[1], val = query[2];
                if (i > 1)
                {
                    int d = peak(nums[i - 2], nums[i - 1], val) -
                            peak(nums[i - 2], nums[i - 1], nums[i]);
                    if (d)
                        add(i - 1, d);
                }
                if (i > 0 && i < n - 1)
                {
                    int d = peak(nums[i - 1], val, nums[i + 1]) -
                            peak(nums[i - 1], nums[i], nums[i + 1]);
                    if (d)
                        add(i, d);
                }
                if (i < n - 2)
                {
                    int d = peak(val, nums[i + 1], nums[i + 2]) -
                            peak(nums[i], nums[i + 1], nums[i + 2]);
                    if (d)
                        add(i + 1, d);
                }
                nums[i] = val;
            }
        }
        return ans;
    }
};
