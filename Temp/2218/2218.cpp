// Link: https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<int> dp(k + 1, 0);
        for (auto& pile : piles) {
            vector<int> prefix(pile.size() + 1, 0);
            for (int i = 0; i < (int)pile.size(); i++) prefix[i + 1] = prefix[i] + pile[i];
            vector<int> ndp = dp;
            for (int j = k; j >= 0; j--) {
                for (int take = 1; take <= (int)pile.size() && take <= j; take++) {
                    ndp[j] = max(ndp[j], dp[j - take] + prefix[take]);
                }
            }
            dp = ndp;
        }
        return dp[k];
    }
};
