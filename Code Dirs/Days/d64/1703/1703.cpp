// Link: https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) + O(n) + O(n) + O(n) + O(n) = O(nlogn)
// SC: O(n) + O(n) + O(n) + O(n) = O(n)
// Approach: Sliding Window + Prefix Sum + Median
// We can use a sliding window of size k to find the minimum number of adjacent swaps needed to group k consecutive 1's together.
int o[100000] = {0};
long long sum[100001] = {0};
class Solution
{
public:
    int minMoves(vector<int> &nums, int k)
    {
        if (k == 1)
            return 0;
        int n = nums.size(), o_size = 0;
        for (int i = 0; i < n; ++i)
            if (nums[i])
            {
                o[o_size++] = i;
                sum[o_size] = sum[o_size - 1] + i;
            }
        long long ans = 1e15;
        for (int r = k - 1, l = 0; r < o_size; ++r, ++l)
        {
            int i = (l + r) >> 1;
            long long nl = i - l + 1, nr = r - i;
            ans = min(ans, nl * o[i] - (sum[i + 1] - sum[l]) -
                               nl * (nl - 1) / 2 + sum[r + 1] - sum[i + 1] -
                               nr * (o[i] + 1) - nr * (nr - 1) / 2);
        }
        return ans;
    }
};