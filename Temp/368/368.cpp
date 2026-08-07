// Link: https://leetcode.com/problems/largest-divisible-subset/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n)
// Approach: sort ascending, dp[i] = length of largest divisible subset
// ending at i, track predecessor to reconstruct
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), prev(n, -1);
        int bestIdx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[bestIdx]) bestIdx = i;
        }
        vector<int> res;
        for (int i = bestIdx; i != -1; i = prev[i]) res.push_back(nums[i]);
        reverse(res.begin(), res.end());
        return res;
    }
};
