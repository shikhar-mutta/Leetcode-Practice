// Link: https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> dp(n + 1, 0), prefSum(n + 2, 0);
        dp[0] = 1;
        prefSum[1] = 1; // prefSum[i] = dp[0]+...+dp[i-1]

        deque<int> maxDq, minDq; // store indices, nums[idx]
        int left = 0;

        for (int i = 1; i <= n; i++) {
            int idx = i - 1; // nums index just added
            while (!maxDq.empty() && nums[maxDq.back()] <= nums[idx]) maxDq.pop_back();
            maxDq.push_back(idx);
            while (!minDq.empty() && nums[minDq.back()] >= nums[idx]) minDq.pop_back();
            minDq.push_back(idx);

            while (!maxDq.empty() && !minDq.empty() && nums[maxDq.front()] - nums[minDq.front()] > k) {
                left++;
                if (maxDq.front() < left) maxDq.pop_front();
                if (minDq.front() < left) minDq.pop_front();
            }

            // dp[i] = sum dp[j] for j in [left, i-1]
            long long sum = (prefSum[i] - (left > 0 ? prefSum[left] : 0) + MOD) % MOD;
            dp[i] = sum;
            prefSum[i+1] = (prefSum[i] + dp[i]) % MOD;
        }

        return (int)dp[n];
    }
};
