// Link: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n^2)
// Approach: dp[i][diff] = number of weak arithmetic subsequences (length
// >=2) ending at i with common difference diff; when extending from j to i,
// dp[j][diff] existing means we can form new length>=3 slices = dp[j][diff]
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, int>> dp(n);
        int total = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = (long long)nums[i] - nums[j];
                int prev = dp[j].count(diff) ? dp[j][diff] : 0;
                total += prev;
                dp[i][diff] += prev + 1;
            }
        }
        return total;
    }
};
