// Link: https://leetcode.com/problems/accounts-merge/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        };
        unordered_map<string, int> emailToAccount;
        for (int i = 0; i < n; i++) {
            for (size_t j = 1; j < accounts[i].size(); j++) {
                const string& email = accounts[i][j];
                if (emailToAccount.count(email)) {
                    int ra = find(i), rb = find(emailToAccount[email]);
                    if (ra != rb) parent[ra] = rb;
                } else {
                    emailToAccount[email] = i;
                }
            }
        }
        map<int, set<string>> grouped;
        for (auto& [email, idx] : emailToAccount) {
            grouped[find(idx)].insert(email);
        }
        vector<vector<string>> result;
        for (auto& [root, emails] : grouped) {
            vector<string> account;
            account.push_back(accounts[root][0]);
            for (const string& e : emails) account.push_back(e);
            result.push_back(account);
        }
        return result;
    }
};
