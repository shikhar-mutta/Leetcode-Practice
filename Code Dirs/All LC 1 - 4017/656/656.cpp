// Link: https://leetcode.com/problems/coin-path/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*B) SC: O(n)
// Approach: DP from the end backwards; dp[i] = min cost to reach n starting at i, next[i] = best next index (smallest index among ties) achieving that min. Skip positions with A[i]==-1 (unreachable). Reconstruct path via next[] pointers from index 1.
class Solution {
public:
    vector<int> cheapestJump(vector<int>& coins, int B) {
        int n = coins.size();
        vector<long long> dp(n+1, LLONG_MAX);
        vector<int> nxt(n+1, -1);
        dp[n-1] = coins[n-1];
        for (int i = n-2; i >= 0; i--) {
            if (coins[i] == -1) continue;
            for (int j = i+1; j <= min(i+B, n-1); j++) {
                if (dp[j] == LLONG_MAX) continue;
                long long cost = coins[i] + dp[j];
                if (cost < dp[i]) {
                    dp[i] = cost;
                    nxt[i] = j;
                }
            }
        }
        vector<int> res;
        if (dp[0] == LLONG_MAX) return res;
        int cur = 0;
        while (cur != -1) {
            res.push_back(cur+1);
            cur = nxt[cur];
        }
        return res;
    }
};
