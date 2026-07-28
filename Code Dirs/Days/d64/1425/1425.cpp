// Link: https://leetcode.com/problems/constrained-subsequence-sum/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: dp[i] = max subsequence sum ending exactly at i, where the
// previous chosen element (if any) is within k positions back.
// dp[i] = nums[i] + max(0, best dp value among the last k indices).
// Maintain that "best in window" via a monotonic decreasing deque of
// indices (by dp value), giving O(1) amortized max-query per step.
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        deque<int> dq; // indices, dp values decreasing
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            while (!dq.empty() && dq.front() < i - k) dq.pop_front();
            int best = dq.empty() ? 0 : max(0, dp[dq.front()]);
            dp[i] = nums[i] + best;
            ans = max(ans, dp[i]);
            while (!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();
            dq.push_back(i);
        }
        return ans;
    }
};
