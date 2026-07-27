// Link: https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: dp[i] = number of valid partitions of the first i elements,
// dp[0]=1. dp[i] = sum of dp[j] over all j such that nums[j..i-1] has
// max-min <= k. The set of valid j for a fixed i is a suffix [lo, i), and
// lo is monotonically non-decreasing as i grows, so maintain a sliding
// window with monotonic deques for the window's max/min, shrinking from
// the left whenever the max-min gap exceeds k, and a running prefix sum
// of dp values to answer each dp[i] in O(1).
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> dp(n + 1, 0), preSum(n + 2, 0);
        dp[0] = 1;
        preSum[1] = 1; // preSum[i] = dp[0]+...+dp[i-1]

        deque<int> maxDq, minDq;
        int lo = 0;
        for (int i = 1; i <= n; i++) {
            int idx = i - 1;
            while (!maxDq.empty() && nums[maxDq.back()] <= nums[idx]) maxDq.pop_back();
            maxDq.push_back(idx);
            while (!minDq.empty() && nums[minDq.back()] >= nums[idx]) minDq.pop_back();
            minDq.push_back(idx);

            while (nums[maxDq.front()] - nums[minDq.front()] > k) {
                if (maxDq.front() == lo) maxDq.pop_front();
                if (minDq.front() == lo) minDq.pop_front();
                lo++;
            }

            dp[i] = (preSum[i] - preSum[lo] + MOD) % MOD;
            preSum[i + 1] = (preSum[i] + dp[i]) % MOD;
        }
        return (int)dp[n];
    }
};
