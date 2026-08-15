// Link: https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        int ans = 0;
        for (int x : nums) {
            int oldX = dp.count(x) ? dp[x] : 0;
            int viaXminus1 = (dp.count(x-1) ? dp[x-1] : 0) + 1;
            int newX = max(oldX, viaXminus1);
            int newXplus1 = max(dp.count(x+1) ? dp[x+1] : 0, oldX + 1);
            dp[x] = newX;
            dp[x+1] = newXplus1;
            ans = max({ans, dp[x], dp[x+1]});
        }
        return ans;
    }
};
