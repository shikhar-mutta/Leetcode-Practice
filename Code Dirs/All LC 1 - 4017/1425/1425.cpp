// Link: https://leetcode.com/problems/constrained-subsequence-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        deque<int> dq; // indices, dp values decreasing
        int best = INT_MIN;

        for (int i = 0; i < n; i++) {
            while (!dq.empty() && dq.front() < i - k) dq.pop_front();
            int prevBest = dq.empty() ? 0 : max(0, dp[dq.front()]);
            dp[i] = nums[i] + prevBest;
            best = max(best, dp[i]);
            while (!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();
            dq.push_back(i);
        }
        return best;
    }
};
