// Link: https://leetcode.com/problems/stone-game-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int best = INT_MIN, sum = 0;
            for (int take = 1; take <= 3 && i + take <= n; take++) {
                sum += stoneValue[i + take - 1];
                best = max(best, sum - dp[i + take]);
            }
            dp[i] = best;
        }
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};
