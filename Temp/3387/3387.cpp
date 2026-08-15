// Link: https://leetcode.com/problems/maximize-amount-after-two-days-of-conversions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, double> computeReach(string start, vector<vector<string>>& pairs, vector<double>& rates) {
        unordered_map<string, vector<pair<string,double>>> adj;
        for (int i = 0; i < (int)pairs.size(); i++) {
            string a = pairs[i][0], b = pairs[i][1];
            double r = rates[i];
            adj[a].push_back({b, r});
            adj[b].push_back({a, 1.0 / r});
        }

        unordered_map<string, double> reach;
        reach[start] = 1.0;
        function<void(string, double)> dfs = [&](string cur, double amt) {
            for (auto& [next, rate] : adj[cur]) {
                double namt = amt * rate;
                if (reach.count(next)) continue;
                reach[next] = namt;
                dfs(next, namt);
            }
        };
        dfs(start, 1.0);
        return reach;
    }

    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        auto day1 = computeReach(initialCurrency, pairs1, rates1);
        auto day2 = computeReach(initialCurrency, pairs2, rates2);

        double best = 0;
        for (auto& [cur, amt1] : day1) {
            if (day2.count(cur)) {
                double total = amt1 / day2[cur];
                best = max(best, total);
            }
        }
        return best;
    }
};
