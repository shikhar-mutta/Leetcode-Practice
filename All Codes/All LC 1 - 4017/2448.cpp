// Link: https://leetcode.com/problems/minimum-cost-to-make-array-equal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlog(max-min)) SC: O(1)
//  Approach:
//   1. Find the minimum and maximum values in the input array.
//   2. Use binary search to find the optimal value that minimizes the cost of making the array equal.
//   3. For each mid value, calculate the cost of making all elements equal to mid and mid+1.
//   4. If the cost of making all elements equal to mid is greater than the cost of making all elements equal to mid+1, then search in the right half of the range, otherwise search in the left half of the range.
//   5. Return the minimum cost found during the binary search.
class Solution
{
public:
    int n;
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        n = nums.size();
        int s = INT_MAX;
        int e = 0;
        for (int i = 0; i < n; i++)
        {
            s = min(s, nums[i]);
            e = max(e, nums[i]);
        }
        long long ans = LLONG_MAX;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            long long cost1 = 0;
            long long cost2 = 0;
            for (int i = 0; i < n; i++)
            {
                cost1 += 1LL * abs(nums[i] - mid) * cost[i];
                cost2 += 1LL * abs(nums[i] - mid - 1) * cost[i];
            }
            if (cost1 == cost2)
                return cost1;
            if (cost1 > cost2)
                s = mid + 1;
            else
                e = mid - 1;
            ans = min(ans, cost1);
        }
        return ans;
    }
};