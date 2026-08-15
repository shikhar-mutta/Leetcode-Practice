// Link: https://leetcode.com/problems/optimal-account-balancing/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n!) worst case  SC: O(n)
// Approach: compute each person's net balance, keep only nonzero balances,
// backtrack: fix the first nonzero balance, try settling it with every
// other opposite-sign balance, recurse; minimize total settlements
class Solution {
    int best;

    void dfs(vector<int>& balances, int start, int count) {
        while (start < (int)balances.size() && balances[start] == 0) start++;
        if (start == (int)balances.size()) {
            best = min(best, count);
            return;
        }
        for (int i = start + 1; i < (int)balances.size(); i++) {
            if (balances[i] == 0 || (balances[i] > 0) == (balances[start] > 0)) continue;
            balances[i] += balances[start];
            dfs(balances, start + 1, count + 1);
            balances[i] -= balances[start];
        }
    }

public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, long long> net;
        for (auto& t : transactions) {
            net[t[0]] -= t[2];
            net[t[1]] += t[2];
        }
        vector<int> balances;
        for (auto& [id, bal] : net) if (bal != 0) balances.push_back((int)bal);

        best = balances.size();
        dfs(balances, 0, 0);
        return best;
    }
};
