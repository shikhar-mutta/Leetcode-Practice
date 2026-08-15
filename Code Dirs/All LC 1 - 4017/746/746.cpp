// Link: https://leetcode.com/problems/min-cost-climbing-stairs/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: dp[i] = min cost to reach step i; dp[i] = cost[i] + min(dp[i-1], dp[i-2]). Answer is min(dp[n-1], dp[n-2]) (top can be reached from either of the last two steps).
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = 0, prev1 = 0;
        for (int i = 2; i <= n; i++) {
            int cur = min(prev1 + cost[i-1], prev2 + cost[i-2]);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
