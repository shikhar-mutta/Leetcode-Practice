// Link: https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/description/

#include <bits/stdc++.h>
using namespace std;

static int speedup = []()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    // TC: O(nlogn + mlogn)
    // SC: O(n)
    // Approach:
    // 1. Sort the nums array.
    // 2. Create a prefix sum array of nums.
    // 3. For each query, find the index of the first element in nums that is
    //    greater than or equal to the query using binary search.
    // 4. Calculate the number of operations needed to make all elements equal to the query.
    // 5. Return the result.
    vector<long long> minOperations(vector<int> &nums, vector<int> &queries)
    {
        ranges::sort(nums);
        int n = nums.size();
        vector<long long> res, pre(n + 1);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + nums[i];
        for (int q : queries)
        {
            int i = ranges::lower_bound(nums, q) - nums.begin();
            res.push_back(1LL * (2 * i - n) * q + pre[n] - 2 * pre[i]);
        }
        return res;
    }
};