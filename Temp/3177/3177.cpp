// Link: https://leetcode.com/problems/find-the-maximum-length-of-a-good-subsequence-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> bestByValue;
        vector<int> bestOverall(k + 1, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int v = nums[i];
            auto it = bestByValue.find(v);
            if (it == bestByValue.end()) {
                bestByValue[v] = vector<int>(k + 1, 0);
                it = bestByValue.find(v);
            }
            vector<int>& bv = it->second;
            vector<int> dp(k + 1, 0);
            for (int j = 0; j <= k; j++) {
                int val = bv[j] + 1;
                if (j > 0) val = max(val, bestOverall[j-1] + 1);
                dp[j] = val;
            }
            for (int j = 0; j <= k; j++) {
                bv[j] = max(bv[j], dp[j]);
                bestOverall[j] = max(bestOverall[j], dp[j]);
                ans = max(ans, dp[j]);
            }
        }
        return ans;
    }
};
