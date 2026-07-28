// Link: https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(k * sum(pile sizes))  SC: O(k)
// Approach: grouped knapsack. dp[j] = max value using j coins taken so
// far. For each pile, iterate j from k down to 0, and for each prefix take
// of that pile update dp[j+take] = max(dp[j+take], dp[j] + prefixSum).
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> dp(k + 1, 0);
        for (auto& pile : piles) {
            vector<int> prefix(pile.size() + 1, 0);
            for (int i = 0; i < (int)pile.size(); i++) prefix[i+1] = prefix[i] + pile[i];
            for (int j = k; j >= 0; j--) {
                for (int take = 1; take <= (int)pile.size() && take <= j; take++) {
                    dp[j] = max(dp[j], dp[j - take] + prefix[take]);
                }
            }
        }
        return dp[k];
    }
};
