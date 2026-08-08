// Link: https://leetcode.com/problems/accounts-merge/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(n)
// Approach: union-find over account indices; union two accounts if they share any email. Then group emails by root, sort each group, prepend the account name.
class Solution {
    vector<int> parent;
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        unordered_map<string, int> emailToAcc;
        for (int i = 0; i < n; i++) {
            for (size_t j = 1; j < accounts[i].size(); j++) {
                string& email = accounts[i][j];
                if (emailToAcc.count(email)) {
                    int rx = find(i), ry = find(emailToAcc[email]);
                    if (rx != ry) parent[rx] = ry;
                } else {
                    emailToAcc[email] = i;
                }
            }
        }
        unordered_map<int, set<string>> grouped;
        for (auto& [email, acc] : emailToAcc) grouped[find(acc)].insert(email);
        vector<vector<string>> res;
        for (auto& [root, emails] : grouped) {
            vector<string> entry;
            entry.push_back(accounts[root][0]);
            for (auto& e : emails) entry.push_back(e);
            res.push_back(entry);
        }
        return res;
    }
};
