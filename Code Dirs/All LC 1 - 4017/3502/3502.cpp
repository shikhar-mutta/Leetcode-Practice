// Link: https://leetcode.com/problems/minimum-cost-to-reach-every-position/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> ans(cost.size());
        int best = INT_MAX;
        for (int i = 0; i < (int)cost.size(); i++) {
            best = min(best, cost[i]);
            ans[i] = best;
        }
        return ans;
    }
};
