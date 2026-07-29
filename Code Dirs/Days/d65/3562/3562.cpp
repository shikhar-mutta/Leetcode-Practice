// Link: https://leetcode.com/problems/maximum-profit-from-trading-stocks-with-discounts/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int NEG = -1000000;
    vector<vector<int>> children;
    vector<int>* presentP;
    vector<int>* futureP;
    int budget_;

    vector<int> merge(vector<int> a, const vector<int>& b) {
        int B = budget_;
        vector<int> res(B + 1, NEG);
        for (int j1 = 0; j1 <= B; j1++) {
            if (a[j1] == NEG) continue;
            for (int j2 = 0; j1 + j2 <= B; j2++) {
                if (b[j2] == NEG) continue;
                int val = a[j1] + b[j2];
                if (val > res[j1 + j2]) res[j1 + j2] = val;
            }
        }
        return res;
    }

    vector<int> dfs(int node, int price) {
        int B = budget_;
        vector<int>& present = *presentP;
        vector<int>& future = *futureP;

        vector<int> notBuy(B + 1, 0);
        vector<int> buy(B + 1, NEG);
        for (int j = price; j <= B; j++) buy[j] = future[node] - price;

        for (int child : children[node]) {
            vector<int> childFull = dfs(child, present[child]);
            notBuy = merge(notBuy, childFull);
            vector<int> childDisc = dfs(child, present[child] / 2);
            buy = merge(buy, childDisc);
        }

        vector<int> result(B + 1);
        for (int j = 0; j <= B; j++) result[j] = max(notBuy[j], buy[j]);
        return result;
    }

    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        budget_ = budget;
        presentP = &present;
        futureP = &future;
        // shift to 0-indexed
        vector<int> present0(n), future0(n);
        for (int i = 0; i < n; i++) { present0[i] = present[i]; future0[i] = future[i]; }
        presentP = &present0;
        futureP = &future0;

        children.assign(n, {});
        for (auto& h : hierarchy) children[h[0]-1].push_back(h[1]-1);

        vector<int> res = dfs(0, present0[0]);
        int best = 0;
        for (int j = 0; j <= budget; j++) best = max(best, res[j]);
        return best;
    }
};
