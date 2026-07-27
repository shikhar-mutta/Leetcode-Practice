// Link: https://leetcode.com/problems/sum-of-k-subarrays-with-length-at-least-m/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * k) SC: O(n * k)
// Approach: dp[j][i] = max sum using exactly j non-overlapping subarrays
// (each length >= m) chosen from the first i elements. Either skip
// element i (dp[j][i-1]), or end a new subarray exactly at i with some
// length L >= m: dp[j][i] = max_p (dp[j-1][p] - prefix[p]) + prefix[i]
// for p <= i-m. The inner max is tracked as a running best as i grows,
// avoiding an O(n) inner scan.
class Solution {
public:
    int maxSum(vector<int>& nums, int k, int m) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + nums[i];

        const long long NEG = LLONG_MIN / 2;
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, NEG));
        for (int i = 0; i <= n; i++) dp[0][i] = 0;

        for (int j = 1; j <= k; j++) {
            long long best = NEG; // max over p<=i-m of dp[j-1][p]-prefix[p]
            for (int i = 0; i <= n; i++) {
                int p = i - m;
                if (p >= 0 && dp[j-1][p] > NEG) best = max(best, dp[j-1][p] - prefix[p]);
                long long take = (best > NEG) ? best + prefix[i] : NEG;
                long long skip = (i > 0) ? dp[j][i-1] : NEG;
                dp[j][i] = max(take, skip);
            }
        }
        return (int)dp[k][n];
    }
};
