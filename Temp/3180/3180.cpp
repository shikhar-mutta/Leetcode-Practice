// Link: https://leetcode.com/problems/maximum-total-reward-using-operations-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());
        int maxSum = 0;
        for (int v : rewardValues) maxSum += v;
        vector<bool> dp(maxSum + 1, false);
        dp[0] = true;
        for (int v : rewardValues) {
            for (int s = min(maxSum, v - 1); s >= 0; s--) {
                if (dp[s]) dp[s + v] = true;
            }
        }
        int ans = 0;
        for (int s = maxSum; s >= 0; s--) if (dp[s]) { ans = s; break; }
        return ans;
    }
};
