// Link: https://leetcode.com/problems/closest-dessert-cost/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int best;
    int target_;

    void update(int cost) {
        if (abs(cost - target_) < abs(best - target_)) best = cost;
        else if (abs(cost - target_) == abs(best - target_) && cost < best) best = cost;
    }

    void dfs(vector<int>& toppingCosts, int idx, int cost) {
        if (idx == (int)toppingCosts.size()) {
            update(cost);
            return;
        }
        for (int cnt = 0; cnt <= 2; cnt++) {
            dfs(toppingCosts, idx + 1, cost + cnt * toppingCosts[idx]);
        }
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        target_ = target;
        best = baseCosts[0];
        for (int b : baseCosts) {
            dfs(toppingCosts, 0, b);
        }
        return best;
    }
};
