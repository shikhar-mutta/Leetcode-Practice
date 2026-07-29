// Link: https://leetcode.com/problems/painting-the-walls/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2), SC: O(N)
// Approach: 0/1 knapsack. dp[j] = min cost using paid painters so far to "cover" at least j
// walls, where hiring the paid painter for wall i covers 1 (itself) + time[i] (free painter's
// output during that time). Cap coverage at n since extra coverage is wasted. The free painter
// covers whatever's left over at zero cost, so the answer is dp[n].
class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = n; j >= 0; j--) {
                if (dp[j] == INT_MAX) continue;
                int nj = min(n, j + 1 + time[i]);
                dp[nj] = min(dp[nj], dp[j] + cost[i]);
            }
        }
        return dp[n];
    }
};
