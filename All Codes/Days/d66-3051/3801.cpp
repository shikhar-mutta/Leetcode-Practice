// Link: https://leetcode.com/problems/minimum-cost-to-merge-sorted-lists/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(2^n*log(nl)*n*logl + 3^n)  SC: O(n*l + 2^n)
// Approach: bitmask DP over which lists (n<=12) have been merged. dp1[mask]
// = total element count of the union (size sum, independent of merge
// order). dp2[mask] = median value of the merged union (also order-
// independent, found via binary search over all distinct values counting
// how many elements of the mask are <= a candidate). dp3[mask] = min cost
// to merge exactly the lists in mask, by trying every way to split mask
// into two nonempty submasks: dp3[sub]+dp3[mask^sub]+|median diff|+dp1[mask]
// (the length term is always the full merged size, charged once per split
// level regardless of internal merge order).
class Solution
{
public:
    long long minMergeCost(vector<vector<int>> &lists)
    {
        int n = lists.size();
        int full = 1 << n;
        vector<int> dp1(full, 0);
        for (int i = 0; i < n; i++)
            dp1[1 << i] = lists[i].size();
        for (int mask = 1; mask < full; mask++)
        {
            int low = mask & (-mask);
            if (mask != low)
                dp1[mask] = dp1[mask ^ low] + dp1[low];
        }

        vector<int> sortedVals;
        for (auto &l : lists)
            for (int x : l)
                sortedVals.push_back(x);
        sort(sortedVals.begin(), sortedVals.end());
        sortedVals.erase(unique(sortedVals.begin(), sortedVals.end()), sortedVals.end());
        int m = sortedVals.size();

        vector<int> dp2(full, 0);
        for (int mask = 1; mask < full; mask++)
        {
            int lo = 0, hi = m - 1;
            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                int cnt = 0;
                for (int i = 0; i < n; i++)
                {
                    if (!(mask & (1 << i)))
                        continue;
                    cnt += upper_bound(lists[i].begin(), lists[i].end(), sortedVals[mid]) - lists[i].begin();
                }
                if (cnt >= (dp1[mask] + 1) / 2)
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            dp2[mask] = sortedVals[lo];
        }

        vector<long long> dp3(full, 0);
        const long long INF = LLONG_MAX / 2;
        for (int mask = 1; mask < full; mask++)
        {
            if ((mask & (mask - 1)) == 0)
                continue;
            dp3[mask] = INF;
            for (int sub = (mask - 1) & mask; sub > (mask ^ sub); sub = (sub - 1) & mask)
            {
                long long cost = dp3[sub] + dp3[mask ^ sub] + abs(dp2[sub] - dp2[mask ^ sub]) + dp1[mask];
                dp3[mask] = min(dp3[mask], cost);
            }
        }
        return dp3[full - 1];
    }
};
