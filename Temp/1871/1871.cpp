// Link: https://leetcode.com/problems/jump-game-vii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n-1] != '0') return false;
        vector<bool> dp(n, false);
        dp[0] = true;
        int reachableCount = 0;
        for (int i = 1; i < n; i++) {
            if (i >= minJump) reachableCount += dp[i - minJump] ? 1 : 0;
            if (i > maxJump) reachableCount -= dp[i - maxJump - 1] ? 1 : 0;
            dp[i] = (s[i] == '0') && (reachableCount > 0);
        }
        return dp[n-1];
    }
};
