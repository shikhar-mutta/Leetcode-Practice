// Link: https://leetcode.com/problems/split-array-with-same-average/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2 * maxSum / 64)  SC: O(n * maxSum / 64)
// Approach: a valid split into subset A (size k) and its complement
// with equal averages requires sum(A) = totalSum * k / n for some
// 1<=k<=n/2 (by symmetry, checking up to half the array suffices).
// Use a bitset-per-count subset-sum DP: dp[k] tracks all sums reachable
// using exactly k elements, built via 0/1 knapsack (iterate k high to
// low per element). Then test each k for a divisible, reachable target.
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return false;
        int total = accumulate(nums.begin(), nums.end(), 0);
        int maxSum = total; // upper bound for any subset sum
        vector<bitset<300001>> dp(n / 2 + 1);
        dp[0][0] = 1;
        for (int num : nums) {
            for (int k = min((int)(n / 2), 30); k >= 1; k--) {
                dp[k] |= dp[k - 1] << num;
            }
        }
        for (int k = 1; k <= n / 2; k++) {
            if ((long long)total * k % n != 0) continue;
            long long target = (long long)total * k / n;
            if (target <= maxSum && dp[k][target]) return true;
        }
        return false;
    }
};
