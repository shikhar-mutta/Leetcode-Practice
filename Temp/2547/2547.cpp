// Link: https://leetcode.com/problems/minimum-cost-to-split-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int j = 0; j < n; j++) {
            if (dp[j] == INT_MAX) continue;
            unordered_map<int,int> freq;
            int cost = 0;
            for (int i = j; i < n; i++) {
                int c = nums[i];
                freq[c]++;
                if (freq[c] == 2) cost += 2;
                else if (freq[c] > 2) cost += 1;

                if (dp[j] + k + cost < dp[i+1]) {
                    dp[i+1] = dp[j] + k + cost;
                }
            }
        }
        return dp[n];
    }
};
