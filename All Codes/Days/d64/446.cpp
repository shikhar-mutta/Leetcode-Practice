// Link: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2)  SC: O(n^2)
// Approach: dp[i][diff] = number of "weak" arithmetic subsequences
// (length >= 2) ending at index i with common difference diff. For each
// pair (j,i), dp[i][diff] += dp[j][diff] + 1 (extending j's subsequences
// plus the new 2-length pair); only dp[j][diff] (length>=2 already)
// contributes to actual answer (length >= 3) slices.
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, int>> dp(n);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = (long long)nums[i] - nums[j];
                int prev = dp[j].count(diff) ? dp[j][diff] : 0;
                ans += prev;
                dp[i][diff] += prev + 1;
            }
        }
        return (int)ans;
    }
};
