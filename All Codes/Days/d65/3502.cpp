// Link: https://leetcode.com/problems/minimum-cost-to-reach-every-position/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n = cost.size();
        vector<int> ans(n);
        int best = cost[0];
        for (int i = 0; i < n; i++) {
            best = min(best, cost[i]);
            ans[i] = best;
        }
        return ans;
    }
};
