// Link: https://leetcode.com/problems/maximize-amount-after-two-days-of-conversions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((V+E)) per day SC: O(V+E)
// Approach: build an undirected weighted graph per day (edge u->v with
// rate r also gives v->u with rate 1/r). DFS from initialCurrency on
// day1's graph tracking the MAX product reachable per currency, and on
// day2's graph tracking the MIN product reachable per currency. Since
// max-reverse-path(c -> initial) = 1 / min-forward-path(initial -> c),
// the answer is the max over common reachable currencies of
// maxRatio1[c] / minRatio2[c].
class Solution {
    void dfs(unordered_map<string, vector<pair<string,double>>>& adj, string node,
              double cur, unordered_map<string,double>& best, bool takeMax) {
        auto it = best.find(node);
        if (it != best.end()) {
            if (takeMax && cur <= it->second) return;
            if (!takeMax && cur >= it->second) return;
        }
        best[node] = cur;
        for (auto& [nxt, rate] : adj[node]) dfs(adj, nxt, cur * rate, best, takeMax);
    }
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        unordered_map<string, vector<pair<string,double>>> adj1, adj2;
        for (int i = 0; i < (int)pairs1.size(); i++) {
            adj1[pairs1[i][0]].push_back({pairs1[i][1], rates1[i]});
            adj1[pairs1[i][1]].push_back({pairs1[i][0], 1.0 / rates1[i]});
        }
        for (int i = 0; i < (int)pairs2.size(); i++) {
            adj2[pairs2[i][0]].push_back({pairs2[i][1], rates2[i]});
            adj2[pairs2[i][1]].push_back({pairs2[i][0], 1.0 / rates2[i]});
        }

        unordered_map<string,double> maxRatio1, minRatio2;
        dfs(adj1, initialCurrency, 1.0, maxRatio1, true);
        dfs(adj2, initialCurrency, 1.0, minRatio2, false);

        double ans = 0;
        for (auto& [cur, val] : maxRatio1) {
            auto it = minRatio2.find(cur);
            if (it != minRatio2.end()) ans = max(ans, val / it->second);
        }
        return ans;
    }
};
