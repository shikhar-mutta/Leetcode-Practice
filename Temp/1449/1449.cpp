// Link: https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> dp(target + 1, INT_MIN);
        dp[0] = 0;
        for (int t = 1; t <= target; t++) {
            for (int d = 1; d <= 9; d++) {
                int c = cost[d-1];
                if (c <= t && dp[t-c] != INT_MIN) dp[t] = max(dp[t], dp[t-c] + 1);
            }
        }
        if (dp[target] < 0) return "0";

        string res;
        int remaining = target;
        while (remaining > 0) {
            for (int d = 9; d >= 1; d--) {
                int c = cost[d-1];
                if (c <= remaining && dp[remaining-c] == dp[remaining] - 1) {
                    res += char('0' + d);
                    remaining -= c;
                    break;
                }
            }
        }
        return res;
    }
};
