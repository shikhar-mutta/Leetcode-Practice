// Link: https://leetcode.com/problems/stone-game-iv/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<char> dp(n + 1, false);
        for (int i = 1; i <= n; i++) {
            for (int s = 1; s * s <= i; s++) {
                if (!dp[i - s * s]) { dp[i] = true; break; }
            }
        }
        return dp[n];
    }
};
