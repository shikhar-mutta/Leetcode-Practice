// Link: https://leetcode.com/problems/stone-game-iii/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: dp[i] = best possible (score so far minus opponent's future
// score) achievable by the player to move, starting from index i, under
// optimal play from both sides. dp[i] = max over taking 1, 2, or 3
// stones of (sum taken - dp[i+taken]), since the opponent then plays
// optimally on the remainder. dp[n]=0. Compare dp[0] to 0 for the result.
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
